#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

#include "../include/Needle.hpp"

Needle::Needle(Canvas* inputCanvas) {

    canvas = inputCanvas;

    // Generate the edge points. Only x-values matter.
    p1 = {canvas->getRandomGenerator()->generateRandomValue()};
    p2 = {getPointOnCircle(p1)};
}

bool Needle::needleHit(){

    bool result = false;

    // If one x-value is across the grid line of the other x-value,
    // then the needle must be laying over the grid line, hitting it.
    for(long unsigned int i = 0; i < canvas->getGridLineXValues()->size(); i++){
        if(((*canvas->getGridLineXValues())[i] >= p1) ==
        ((*canvas->getGridLineXValues())[i] <= p2)){
            result = true;
        }
    }
    return result;
}

vector<double> Needle::getValidCirclePoint(){

    // Generate a random vector with x and y-coordinates within [0,1)
    vector<double> randomUnitVector{
        canvas->getRandomGenerator()->generateRandomDouble(),
        canvas->getRandomGenerator()->generateRandomDouble()
        };

    // Disregard all random vectors that would not lead to a uniform
    // circular distribution.
    if(this->computeMagnitude(&randomUnitVector) <= 1.0f){
        return randomUnitVector;
    } else {

        // If the vector is disregarded, call the function again until
        // a proper vector is found.
        // This was implemented this way to make sure the number of needles
        // would remain the same.
        return getValidCirclePoint();
    }
}


double Needle::getPointOnCircle(double x) {
    vector<double> circlePoint = getValidCirclePoint();

    // Vector calculations. We have to normalize so the magnitude
    // of the random circle vector point can be simply multiplied with the
    // length of a needle.
    // Additionally, we have an offset of x, the first point of the needle.
    return x + (circlePoint[0]/computeMagnitude(&circlePoint)) * (canvas->getCanvasProperties()->needleLength);
}

double Needle::computeMagnitude(vector<double>* input){
    double sum = 0.0f;
    for(long unsigned int i = 0; i < input->size(); i++){
        sum += pow((*input)[i], 2.0f);
    }
    return sqrt(sum);
}

long unsigned int generateNeedles(CanvasProperties_t* inputCanvasProperties, long unsigned int numberNeedles){

    // Get a new instance of a canvas
    // Using only one canvas throughout all threads
    // will lead to data-race for the Random Value Generator.
    Canvas inputCanvas = Canvas(*inputCanvasProperties);
    long unsigned int needleHits = 0;

    for(long unsigned int i = 0; i < numberNeedles; i++){
        Needle needle = Needle(&inputCanvas);
        if(needle.needleHit()){
            needleHits++;
        }
    }

    return needleHits;
}

