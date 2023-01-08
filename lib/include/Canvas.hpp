#ifndef CODE_CANVAS_HPP
#define CODE_CANVAS_HPP

#include <vector>

#include "./RandomGenerator.hpp"

/**
 * Struct for the properties of the canvas.
 * - lowerBound,upperBound: Define the measurements of the canvas.\n
 * - gridLineDistance: Define the distance between the grid lines on the canvas.\n
 * - needleLength: Defines the length of the needles generated onto the canvas.\n
 * - numberNeedles: The number of needles to generate it on.\n
 */
struct CanvasProperties_t{
    double lowerBound;
    double upperBound;
    double gridLineDistance;
    double needleLength;
    long unsigned int numberNeedles;
};

/**
 * The Canvas class combines the properties of the canvas and
 * the random number Generator, which must be unique to the canvas, (there can only be one
 * throughout one canvas)
 * @see CanvasProperties_t
 */
class Canvas {
public:

    /**
     * Initialises the Random number generator for the boundaries
     * of the Canvas, as well as computing a vector of grid line x-coordinates,
     * based on the boundaries and the given grid line distance.
     * @param inputCanvasProperties The supposed properties of the canvas.
     */
    Canvas(CanvasProperties_t inputCanvasProperties);

    /**
     * Getter for Canvas Properties.
     * @return Memory address of the canvas properties.
     */
    CanvasProperties_t* getCanvasProperties();

    /**
     * Getter for the random generator.
     * @return Memory address of the Random number generator.
     */
    RandomGenerator* getRandomGenerator();

    /**
     * Getter for the x-coordinates of the grid lines.
     * @return Memory address of the vector of grid line x-coordinates.
     */
    vector<double>* getGridLineXValues();

private:

    CanvasProperties_t canvasProperties;
    RandomGenerator randomGenerator;
    vector<double> gridLineXValues;
};

#endif //CODE_CANVAS_HPP
