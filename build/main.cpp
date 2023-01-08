#include <iostream>
#include <chrono>
#include <thread>
#include <future>

using namespace std;

#include "../lib/include/Canvas.hpp"
#include "../lib/include/Needle.hpp"
#include "../lib/include/Input.hpp"
#include "../lib/include/Output.hpp"
#include "../lib/include/Logger.hpp"

int main(int argc, char* argv[]){

    // Convert the command line arguments to a vector of strings.
    vector<string> stringArgv(argv+1, argv+argc);

    // Get a struct filled with the command line arguments.
    ExecParameters_t execParameters = getExecParamFromArgv(stringArgv);

    // Display the parameters to double-check input.
    displayParameters(execParameters);

    // Create canvas and assign properties.
    CanvasProperties_t canvasProperties;
    canvasProperties.lowerBound = execParameters.lowerBound;
    canvasProperties.upperBound = execParameters.upperBound;
    canvasProperties.gridLineDistance = execParameters.gridLineDist;
    canvasProperties.needleLength = execParameters.needleLength;
    canvasProperties.numberNeedles = execParameters.numberNeedles;

    // Start the execution of the iterations
    // and begin measuring total runtime
    displayMessage("\033[1m[ == EXECUTION START == ]\033[0m");
    auto start = std::chrono::high_resolution_clock::now();

    // Compute how many needles each thread will get.
    // Because there can be needles left after equally dividing all to the threads
    // safe the remainder for later to add to the last thread.
    unsigned int numberThreads = execParameters.numberThreads;
    long unsigned int numThreadRemainder = canvasProperties.numberNeedles % numberThreads;
    long unsigned int numberPerThread = (canvasProperties.numberNeedles - numberThreads)/numberThreads;

    // piSum necessary for computing mean of pi.
    double piSum = 0;

    // For each iteration, compute pi.
    for(long int i = 0; i < execParameters.iterations; i++){

        // Start measuring runtime for this iteration.
        auto startIteration = std::chrono::high_resolution_clock::now();

        // Create a vector of async calls, i.e. threads
        // "Future" here is a helper object, which makes it
        // easier to gather values from the threads after
        // they are done executing.
        vector<future<long unsigned int>> asyncCalls;

        // Fill the results struct with values to prevent
        // garbage data to trickle through
        ExecResults_t execResults = constructResultStruct();

        // Create n-1 threads and call the generateNeedles function.
        for(unsigned int i = 0; i < numberThreads - 1; i++){
            asyncCalls.emplace_back(async(generateNeedles, &canvasProperties, numberPerThread + 1));
        }

        // The last threads gets the thread remainder on top.
        asyncCalls.emplace_back(async(generateNeedles, &canvasProperties, numberPerThread + numThreadRemainder + 1));

        // Wait for all threads to end execution and collect the
        // needles that hit for each thread process.
        for(unsigned int i = 0; i < numberThreads; i++){
            execResults.hitNeedles += asyncCalls[i].get();
        }

        // i+1 since this is supposed to be the "1st, 2nd, 3rd"
        // iteration.
        execResults.iteration = i+1;

        // Maths: pi = (2L/D)*(N/n)
        execResults.pi = 2.0f*((double)canvasProperties.numberNeedles)/((double)execResults.hitNeedles);
        piSum += execResults.pi;

        // Finish time measuring and convert to microseconds.
        auto finishIteration = std::chrono::high_resolution_clock::now();
        auto runtimeIteration = std::chrono::duration_cast<std::chrono::microseconds>(
                finishIteration - startIteration);
        execResults.runtime = runtimeIteration.count();

        // Display and write the results of this iteration to file.
        displayIndividualResults(execResults);
        writeResultToFile(execResults, execParameters);
    }


    // Finish measuring total runtime and convert to microseconds.
    auto finish = std::chrono::high_resolution_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);

    // Compute the final pi mean and display the final result.
    double meanPi = piSum/((double)execParameters.iterations);
    displayFinalResult(meanPi, runtime.count());

    return 0;
}
