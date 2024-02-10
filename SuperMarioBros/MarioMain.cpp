#include "Level.h"
#include "World.h"
#include "GetInput.h"
#include "Mario.h"
#include "MoveGenerator.h"
#include "Gameplay.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc,char*argv[]){

    // initialize input variables
    GetInput g;
    int* inputValues = g.makeArrayOfInput(argv[1]);
    int levels = inputValues[0];
    int gridSize = inputValues[1];
    int lives = inputValues[2];
    int p1 = inputValues[3];
    int p2 = inputValues[4];
    int p3 = inputValues[5];
    int p4 = inputValues[6];
    int p5 = inputValues[7];

    Gameplay *game = new Gameplay(levels, gridSize, lives, p1, p2, p3, p4, p5); // create new game

    game->playGame(argv[2]); // play game and log to output file

    return 0;
}