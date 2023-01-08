#include "../include/Output.hpp"

ExecResults_t constructResultStruct(){
    ExecResults_t execResults;
    execResults.pi = -1.0;
    execResults.hitNeedles = 0;
    execResults.iteration = 0;
    execResults.runtime = 0;
    return execResults;
}
