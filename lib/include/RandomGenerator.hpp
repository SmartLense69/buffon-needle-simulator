#ifndef CODE_RANDOMGENERATOR_HPP
#define CODE_RANDOMGENERATOR_HPP

#include <random>
#include <vector>
#include <stdexcept>

using namespace std;

/**
 * A RandomGenerator includes the seed,
 * the distribution generator mt19937 and the distributions generated.
 * This was made to make sure, that a canvas will be using the same seed
 * and distribution throughout its lifetime.
 */
class RandomGenerator {
public:

    /**
     * Generates a set of distributions, which boundaries is defined by the
     * lower and upperBound vectors.
     * @param lowerBound Lower bounds of the distributions.
     * @param upperBound Upper bounds of the distributions.
     * @throw invalid_argument If the dimension of the lower and upper Bound
     * do not match.
     */
    RandomGenerator(double lowerBound = 0.0f, double upperBound = 10.0f);

    /**
     * Generates a random vector based on the size of the set of distributions.
     * and the distributions itself.
     * @return Randomized vector.
     */
    vector<double> generateRandomVector();

    /**
     * Generates a random value within the interval
     * [distance-mean, mean+distance].
     * @param mean Mean of the distribution.
     * @param distance Distance away from the mean.
     * @return Random value within the distribution
     */
    double generateRandomValue(double mean, double distance);

    /**
      * Generates a random double within the x-width of the Canvas.
      * @return Random double between the lowerBound and upperBound.
      */
    double generateRandomValue();

    /**
    * Generates a random value within the interval [0,1).
    * @return Random value within [0,1)
    */
    double generateRandomDouble();

private:

    /**
     * Mersenne Twister Algorithm for random numbers.
     */
    mt19937 generator;

    /**
     * Distribution between [lowerBound, upperBound)
     */
    uniform_real_distribution<double> boundaryDistribution;

    /**
     * Distribution between [0,1)
     */
    uniform_real_distribution<double> unitDistribution;
};

#endif //CODE_RANDOMGENERATOR_HPP
