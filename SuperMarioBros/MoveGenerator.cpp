#include "MoveGenerator.h"
#include <cstdlib>
#include <string>
using namespace std;

MoveGenerator::MoveGenerator() // default constructor
{

}

MoveGenerator::~MoveGenerator() // default destructor
{
    
}

string MoveGenerator::getNextMove()
{
    int random = rand() % 100;
    if (random < 25)
    {
        return "UP";
    }
    else if (random < 50)
    {
        return "DOWN";
    }
    else if (random < 75)
    {
        return "LEFT";
    }
    else if (random < 100)
    {
        return "RIGHT";
    }
}
        