#ifndef CODE_LOGGER_HPP
#define CODE_LOGGER_HPP

#include <string>

#include "../include/Input.hpp"
#include "../include/Output.hpp"

using namespace std;

/**
 * List of possible error outcomes.
 */
enum Errors {
    ERROR_BAD_ARGUMENT,     // 1
    ERROR_BAD_CAST,         // 2
    ERROR_NO_ARGUMENT,      // 3
    ERROR_NO_SUCH_ARG,      // 4
    ERROR_MULTIPLE_ARG,     // 5
    ERROR_LOGIC_BOUNDS,     // 6
    ERROR_LOGIC_ZERO,       // 7
    ERROR_UNDEFINED         // 255
};

/**
 * Displays information about the program,
 * and all command line arguments.
 */
void displayHelp();

/**
 * Displays a message in console.
 * @param message The message that should be displayed in console.
 * @note std::cout, which is utilized by this function,
 * is not thread safe and should be replace with some kind of buffer.
 */
void displayMessage(string message);

/**
 * Displays an error in console and terminates the program.
 * Throws an instance of an integer corresponding to the error.
 * @param error One of the enum entries of Error.
 * @param message Additional information about the error.
 * @throw int An integer associated with the type of error.
 * @see Enum Errors for the different return codes.
 */
void displayError(Errors error, string message);

/**
 * Displays the parameters with which the program was called.
 * @param inputParam The struct containing all parameters.
 * @see ExecParameters_t for a list of all parameters.
 */
void displayParameters(ExecParameters_t inputParam);

/**
 * Displays the Results of one iteration.
 * Shows computed pi, computational time in ms and
 * the number of needles that hit the grid line.
 * @param outputResult Results of one iteration.
 * @see ExecResults_t for a list of all result fields.
 */
void displayIndividualResults(ExecResults_t outputResult);

/**
 * Displays the final result after taking the average
 * of pi of all iterations. Also shows total runtime.
 * @param piMean Mean of pi for all runs.
 * @param runtimeCount Runtime in microseconds.
 */
void displayFinalResult(double piMean, long int runtimeCount);

/**
 * Writes the results of one iteration to file.
 * The values are written to file as listed below from left to right:\n
 * - Number of needles used in the iteration\n
 * - Number of threads computing this iteration\n
 * - Runtime of the iteration in microseconds\n
 * - Computed pi for this run\n
 * - Which iteration this is\n
 * - The set needle length\n
 * - The distance between grid lines
 * @param result Result of one iteration.
 * @param param Parameter of the program.
 */
void writeResultToFile(ExecResults_t result,
                       ExecParameters_t param);


#endif //CODE_LOGGER_HPP
