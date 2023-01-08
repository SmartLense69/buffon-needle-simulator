#include <iostream>
#include <fstream>

#include "../include/Logger.hpp"

void displayHelp(){
    string fileBuffer;
    ifstream manualFile("manual.txt");
    while(getline(manualFile, fileBuffer)){
        cout << fileBuffer << endl;
    }
    throw 0;
}

void displayMessage(string message){
    cout << message << endl;
}

void displayError(Errors error, string message){
    cout << "\033[1;31m[ == ERROR: ";
    switch(error){
        case ERROR_BAD_ARGUMENT:
            cout << "Bad Input | Invalid Argument == ]\033[0m" << endl;
            cout << message << endl;
            throw 1;
        case ERROR_BAD_CAST:
            cout << "Bad Input | Invalid Cast == ]\033[0m" << endl;
            cout << message << endl;
            throw 2;
        case ERROR_NO_ARGUMENT:
            cout << "Bad Input | No Argument == ]\033[0m" << endl;
            cout << message << endl;
            throw 3;
        case ERROR_NO_SUCH_ARG:
            cout << "Bad Input | No such argument == ]\033[0m" << endl;
            cout << message << endl;
            throw 4;
        case ERROR_MULTIPLE_ARG:
            cout << "Bad Input | Multiple arguments == ]\033[0m" << endl;
            cout << message << endl;
            throw 5;
        case ERROR_LOGIC_BOUNDS:
            cout << "Faulty Logic | Canvas Boundaries == ]\033[0m" << endl;
            cout << message << endl;
            throw 6;
        case ERROR_LOGIC_ZERO:
            cout << "Faulty Logic | Variable can't be zero == ]\033[0m" << endl;
            cout << message << endl;
            throw 7;
        case ERROR_UNDEFINED:
            cout << "Undefined Error == ]\033[0m" << endl;
            cout << message << endl;
            throw 255;
    }
}

void displayParameters(ExecParameters_t inputParam){
    cout << "\033[1m[ -- Input Parameter -- ]\033[0m" << endl;
    cout << "Canvas Lower Bound\t|\t";
    cout << inputParam.lowerBound << endl;
    cout << "Canvas Upper Bound\t|\t";
    cout << inputParam.upperBound << endl;
    cout << "Grid Line Distance\t|\t";
    cout << inputParam.gridLineDist << endl;
    cout << "Needle Length L\t\t|\t";
    cout << inputParam.needleLength << endl;
    cout << "Number of Threads\t|\t";
    cout << inputParam.numberThreads << endl;
    cout << "Number of Needles\t|\t";
    cout << inputParam.numberNeedles << endl;
    cout << "Iterations\t\t|\t";
    cout << inputParam.iterations << endl;
    cout << "Result File Name\t|\t";
    cout << inputParam.filename << endl << endl;
}

void displayIndividualResults(ExecResults_t outputResult){
    cout << "\033[1m[ -- SIMULATION RESULTS | Iteration " <<
    outputResult.iteration << " -- ]\033[0m" << endl;
    cout << "Needle Hits\t\t|\t" << outputResult.hitNeedles << endl;
    cout << "Pi for this run\t\t|\t" << outputResult.pi << endl;
    cout << "Computing time in ms\t|\t" << outputResult.runtime << endl << endl;
}

void displayFinalResult(double piMean, long int runtimeCount){
    cout.precision(15);
    cout << "\033[1m[ == FINAL RESULT == ]" << endl << endl;
    cout << "MEAN PI: " << piMean << "\033[0m" << endl;
    long int microseconds = runtimeCount % 1000;
    long int milliseconds = ((runtimeCount - microseconds) % 1000000) / 1000 ;
    long int seconds = ((runtimeCount - milliseconds - microseconds) % 1000000000) / 1000000;
    cout << "Executed in " << seconds << " Seconds,\n" << milliseconds <<
    " Milliseconds and " << microseconds << " Microseconds." << endl;
}

void writeResultToFile(ExecResults_t result, ExecParameters_t param){
    ofstream file;
    file.open(param.filename, ios::app);
    file.precision(15);
    file << param.numberNeedles << " ";
    file << param.numberThreads << " ";
    file << result.runtime << " ";
    file << result.pi << " ";
    file << result.iteration << " ";
    file << param.needleLength << " ";
    file << param.gridLineDist;
    file << endl;
    file.close();
}

