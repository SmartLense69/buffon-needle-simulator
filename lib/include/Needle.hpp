#ifndef CODE_NEEDLE_HPP
#define CODE_NEEDLE_HPP

#include <vector>

#include "./Canvas.hpp"

/**
 * A needle is a line limited by a start and ending point.
 * The length is determined by the distance of these two points
 * For data redundancy sake, it also includes the pointer to which canvas
 * the needle belongs to.
 */
class Needle {
public:

    /**
     * Creates a new needle.
     * @param inputCanvas The canvas on which the needle
     * should be generated on. Takes the properties of canvas
     * to determine its supposed length.
     */
    Needle(Canvas* inputCanvas);

    /**
     * Checks if a needle hit a grid line.
     * Looks if one needle end is on the other
     * side of the grid line.
     * @return True if it hit the grid line, False if not.
     */
    bool needleHit();

private:

    // End points of the needle
    double p1;
    double p2;

    /**
     * Gets a vector of random values [0,1)
     * that are within a circle or radius 1.
     * This was implemented to make sure the distribution gives
     * a uniform circle arc distribution, as it is required for
     * getting all possible needle rotations uniformly.
     * @return vector of random values.
     */
    vector<double> getValidCirclePoint();
    Canvas* canvas;

    /**
     * Computes the magnitude of a vector.
     * @param input The memory address of the vector.
     * @return Magnitude [sqrt(a²+b²+etc.)] of the vector.
     */
    double computeMagnitude(vector<double>* input);

    /**
     * Gets the point along the circle with radius length
     * away from p1 for a particular x coordinate.
     * @param x x-Coordinate
     * @return The corresponding y-coordinate along the circle.
     */
    double getPointOnCircle(double x);
};

/**
 * Generates needles onto the canvas
 * and checks if the needles hit the grid line(s).
 * @param inputCanvasProperties Properties of the canvas.
 * @param numberNeedles How many needles should generated
 * @return The number of needles that hit.
 */
long unsigned int generateNeedles(CanvasProperties_t* inputCanvasProperties,
                                  long unsigned int numberNeedles);
#endif //CODE_NEEDLE_HPP
