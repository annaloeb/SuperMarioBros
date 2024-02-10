#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H
#include <string>
using namespace std;

class MoveGenerator{
    public:
       MoveGenerator(); // default constructor
       ~MoveGenerator(); // default destructor
       string getNextMove(); // Randomly generate and return a string containing either "UP", "DOWN", "LEFT", or "RIGHT" based off 25% probability for each
};

#endif
