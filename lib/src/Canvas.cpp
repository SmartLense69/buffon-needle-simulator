#include <iostream>

#include "../include/Canvas.hpp"
#include "../include/RandomGenerator.hpp"

Canvas::Canvas(CanvasProperties_t inputCanvasProperties){

    canvasProperties = inputCanvasProperties;
    randomGenerator = RandomGenerator(canvasProperties.lowerBound,canvasProperties.upperBound);

    // Get the length in x-direction of the canvas,
    // then get the possible number of grid lines for these parameters.
    // Then loop through this number and push back each new x-coordinate.
    double gridXLength = canvasProperties.upperBound - canvasProperties.lowerBound;
    long unsigned int gridXNum = (long unsigned int) (gridXLength/(canvasProperties.gridLineDistance));
    for(long unsigned int i = 0; i < gridXNum+1; i++){
        gridLineXValues.push_back(canvasProperties.lowerBound+((double)i)*(canvasProperties.gridLineDistance));
    }
}

CanvasProperties_t *Canvas::getCanvasProperties() {
    return &canvasProperties;
}

vector<double> *Canvas::getGridLineXValues() {
    return &gridLineXValues;
}

RandomGenerator *Canvas::getRandomGenerator() {
    return &randomGenerator;
}
