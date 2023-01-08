#include <memory>

#include "../include/RandomGenerator.hpp"


RandomGenerator::RandomGenerator(double lowerBound, double upperBound){

    // This takes a seed from hardware information,
    // like heat and such.
    random_device randomDevice;

    // Give this seed to the generator for random values.
    mt19937 gen(randomDevice());
    generator = gen;

    // Here, the type of distribution is specified.
    uniform_real_distribution<double> distribution1(lowerBound, upperBound);
    boundaryDistribution = distribution1;
    uniform_real_distribution<double> distribution2(0.0f,1.0f);
    unitDistribution = distribution2;

}

double RandomGenerator::generateRandomValue(double mean, double distance) {
    uniform_real_distribution<double> dist(mean-distance, mean+distance);
    return dist(generator);
}

double RandomGenerator::generateRandomValue(){
    return boundaryDistribution(generator);
}

double RandomGenerator::generateRandomDouble(){
    return unitDistribution(generator);
}
