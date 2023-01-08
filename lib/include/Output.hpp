#ifndef CODE_OUTPUT_HPP
#define CODE_OUTPUT_HPP

/**
 * Results of an iteration.\n
 * - pi: The computed pi for this iteration\n
 * - hitNeedles: The number of needles that hit the grid line\n
 * - iteration: Which iteration is this result belonging to\n
 * - runtime: Execution time for this iteration in microseconds\n
 */
struct ExecResults_t {
    double pi;
    long unsigned int hitNeedles;
    long unsigned int iteration;
    long int runtime;
};

/**
 * Initializes the ExecResult_t struct.
 * @return ExecResult_t instance.
 */
ExecResults_t constructResultStruct();

#endif //CODE_OUTPUT_HPP
