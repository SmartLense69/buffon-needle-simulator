#ifndef CODE_INPUT_HPP
#define CODE_INPUT_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * Parameters of the program.
 * - lowerBound, upperBound: Boundaries of the Canvas\n
 * - gridLineDistance: Distance between each grid line\n
 * - needleLength: Length of a needle\n
 * - numberThreads: The number of threads used for the program\n
 * - numberNeedles: Number of needles to generate\n
 * - iterations: How often the process of generating
 * needles and computing pi should be repeated\n
 * - filename: filename to where the results will be written to\n
 */
struct ExecParameters_t{
    double lowerBound;
    double upperBound;
    double gridLineDist;
    double needleLength;
    int numberThreads;
    long int numberNeedles;
    long int iterations;
    string filename;
};

/**
 * Constant vector of possible command line arguments.
 */
const static vector<string> cmdLineArgs{
        "--help",
        "-h",
        "--lowerBound=",
        "-l=",
        "--upperBound=",
        "-u=",
        "--gridLineDist=",
        "-g=",
        "--needleLength=",
        "-nl=",
        "--threads=",
        "-t=",
        "--needles=",
        "-n=",
        "--iterations=",
        "-i=",
        "--filename=",
        "-f="
};

/**
 * Checks if a string can be safely converted to an integer.
 * It checks if there is something which is not a digit,
 * and checks if at most one minus sign is included in the beginning.
 * @param input The input string.
 * @return True if the string is a possible int, False if not.
 */
bool isStringInt(string input);

/**
 * Checks if a string can be safely converted to a floating-point number.
 * It checks if there is a char in the string which is not a digit,
 * only one decimal point char is used throughout the string,
 * and looks if at most one minus sign is included in the beginning.
 * @param input The input string.
 * @return True if the string is a possible floating point number, False if not.
 */
bool isStringFloat(string input);

/**
 * Checks if a certain char is in the string.
 * @param inputString The string to test for.
 * @param character The char to find in the inputString.
 * @return True if the char is in the string, False if not.
 */
bool isCharInString(string inputString, char character);

/**
 * Checks if a smaller string is in a larger string.
 * @param inputString The input string.
 * @param substring The smaller string.
 * @return True if it is the string, false if not.
 * @todo Add error handling if the input string is smaller than the substring.
 */
bool isSubstringInString(string inputString, string substring);

/**
 * Deletes a substring in a larger input string.
 * It can only delete a substring beginning from the start.
 * @example inputString: "Hello", subString: "Hel" results to "lo".
 * @example inputString: "Hello", subString: "el"
 * will lead to undefined behaviour.
 * @param inputString The input string.
 * @param substring The smaller string.
 * @return String after the substring has been deleted.
 */
string deleteSubstringInString(string inputString, string substring);

/**
 * Converts a string to double safely.
 * @param input The Input string.
 * @return Double value.
 */
double stringToDouble(string input);

/**
 * Converts a string to Integer safely.
 * @param input The Input string.
 * @return Integer value.
 */
int stringToInt(string input);

/**
 * Converts a string to a long Integer safely.
 * @param input The Input string.
 * @return Long int.
 */
long int stringToLongInt(string input);

/**
 * Fills in (and sanitizes) the input from the
 * command line arguments to the ExecParameters_t struct,
 * which it will return by value.
 * @param argv Command line arguments.
 * @return Filled ExecParameters_t instance.
 */
ExecParameters_t getExecParamFromArgv(vector<string> argv);

/**
 * Sanitizes the input of the command line arguments.
 * This includes checking if the lowerBound is actually
 * smaller than the upperBound, removes the sign of (long) ints,
 * and checks if certain values are zero, which they shouldn't be.
 * @param execParameters Parameters of the Executable
 * @return Sanitized Parameters.
 */
ExecParameters_t sanitizeParameters(ExecParameters_t execParameters);

#endif //CODE_INPUT_HPP
