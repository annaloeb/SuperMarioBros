#include "Mario.h"
#include "World.h"
#include "MoveGenerator.h"
#include "Level.h"
#include "Gameplay.h"
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

ofstream log; // create writer object
Mario mario;
MoveGenerator mg;
char*** world;
char currentPosition;
int numMoves;
int levels;
int gridSize;
int x;
int y;
int z;

Gameplay::Gameplay() // default constructor
{

}

Gameplay::Gameplay(int numLevels, int varGridSize, int lives, int p1, int p2, int p3, int p4, int p5) // overloaded constructor takes in all inputs and initializes member variables
{
    World w;
    world = w.createWorld(numLevels, varGridSize, p1, p2, p3, p4, p5);
    mario.setNumLives(lives);
    numMoves = 0;
    levels = numLevels;
    gridSize = varGridSize;
    x = rand() % gridSize;
    y = rand() % gridSize;
    z = 0;
    currentPosition = world[z][y][x];
}

Gameplay::~Gameplay() // default destructor 
{

}

void Gameplay::playGame(string output){

    log.open(output, ios::out); // create output file 

    // to print the world at the start of the game
    for (int i = 0; i < levels; i++)
    {
        log << "Level " << i << endl;
        for (int j = 0; j < gridSize; j++)
        {
            for (int k = 0; k < gridSize; k++)
            {
                log << world[i][j][k] << ' ';
            }
            log << endl;
        }
        log << "=============" << endl;
    }
    log << "Mario is starting in position: (" << y << ',' << x << ')' << endl;
    log << "=============" << endl;
    ///////////////////////////////////////////

    world[z][y][x] = 'H';

    while (mario.returnIsDead() == false && mario.returnHasWon() == false)
    {
        numMoves += 1; // add to round count
        // to print level at the start of every round
        for (int i = z; i <= z; i++)
        {
            for (int j = 0; j < gridSize; j++)
            {
                for (int k = 0; k < gridSize; k++)
                {
                log << world[i][j][k] << ' ';
                }
                log << endl;
            }
            log << "=============" << endl;
        }
        ///////////////////////////////////////

        string nextMove = mg.getNextMove(); // variable creates and stores the next generated move for each round
        string printedMove = "Mario will "; // variable to hold the movement that will be printed

        // string to hold a record of what happens during each turn is initialized to hold the variables that are constant throughout the round
        string recordOfTurn = "Level: " + to_string(z) + ". Mario is at position: (" + to_string(y) + ',' + to_string(x) + "). Mario is at power level " + to_string(mario.getPowerLevel()) + ". ";

        if (currentPosition == 'c') 
        {
            mario.addCoin();
            if (mario.getNumCoins() == 20) 
            {
                mario.addLife(); // add life and reset coins if mario collects 20 coins
                mario.resetCoins();
            }
            recordOfTurn += "Mario collected a coin. ";
            Gameplay::move(nextMove);
            printedMove += "move " + nextMove;
        }
        else if (currentPosition == 'x')
        {
            Gameplay::move(nextMove);
            recordOfTurn += "Mario visited an empty space. ";
            printedMove += "move " + nextMove;
        }
        else if (currentPosition == 'm')
        {
            if (mario.getPowerLevel() != 2)
            {
                mario.increasePowerLevel(); // increase power level if mario is not already at PL2
                Gameplay::move(nextMove);
            } 
            else
            {
                Gameplay::move(nextMove); // do nothing if mario is at PL2
            }
            recordOfTurn += "Mario ate a mushroom. ";
            printedMove += "move " + nextMove;
        }
        else if (currentPosition == 'g')
        {
            int random = rand() % 100;
            if (random < 80) // if mario wins
            {
                recordOfTurn += "Mario encountered a Goomba and won. ";
                Gameplay::move(nextMove); // mario moves on
                mario.addToWinCount();
                if (mario.getWinCount() == 7)
                {
                    mario.addLife(); // if mario's win count is 7 after defeating the goomba, he gets another life
                }
                printedMove += "move " + nextMove;
            }
            else if (random > 80) // if mario loses
            {
                if (mario.getPowerLevel() == 0) // if mario loses and his power level is 0
                {
                    if (mario.getLives() != 0) 
                    {
                        mario.takeAwayLife();
                        recordOfTurn += "Mario encountered a Goomba and lost a life. "; // mario loses a life and continues in the same location if he has more lives
                    }
                    else if (mario.getLives() == 0) 
                    {
                        recordOfTurn += "Mario encountered a Goomba and died. "; // mario dies if he has no more lives
                        mario.setIsDeadToTrue();
                    }
                    printedMove += "stay put. ";
                }
                else // if mario loses and his power level is greater than 0
                {
                    mario.decreasePowerLevel();
                    Gameplay::moveGoomba(nextMove);
                    recordOfTurn += "Mario encountered a Goomba and lost. "; // mario's power level decreases and he moves on leaving the Goomba in place
                    printedMove += "move " + nextMove;
                }
            }
        }
        else if (currentPosition == 'k')
        {
            int random = rand() % 100;
            if (random < 65) // if mario wins
            {
                recordOfTurn += "Mario encountered a Koopa and won. ";
                Gameplay::move(nextMove); // mario moves on
                mario.addToWinCount();
                if (mario.getWinCount() == 7)
                {
                    mario.addLife(); // if mario's win count is 7 after defeating the koopa, he gets another life
                }
                printedMove += "move " + nextMove;
            }
            else if (random > 65) // if mario loses
            {
                if (mario.getPowerLevel() == 0) // if mario loses and his power level is 0
                {
                    if (mario.getLives() != 0) 
                    {
                        mario.takeAwayLife();
                        recordOfTurn += "Mario encountered a Koopa and lost a life. "; // mario loses a life and continues in the same location if he has more lives
                    }
                    else if (mario.getLives() == 0) 
                    {
                        recordOfTurn += "Mario encountered a Koopa and died. "; // mario dies if he has no more lives
                        mario.setIsDeadToTrue();
                    }
                    printedMove += "stay put. ";
                }
                else // if mario loses and his power level is greater than 0
                {
                    mario.decreasePowerLevel();
                    Gameplay::moveKoopa(nextMove);
                    recordOfTurn += "Mario encountered a Koopa and lost. "; // mario's power level decreases and he moves on leaving the Koopa in place 
                    printedMove += "move " + nextMove;
                }               
            }
        }
        else if (currentPosition == 'b')
        {
            if (z < levels - 1) // if its not the final level
            {
                
                int random = rand() % 100;
                if (random < 50) // if mario wins
                {
                    Gameplay::warp(); 
                    recordOfTurn += "Mario fought the level boss and won. "; // mario warps to next level 
                    printedMove += "WARP";
                    mario.addToWinCount();
                    if (mario.getWinCount() == 7)
                    {
                        mario.addLife(); // if mario's win count is 7 after defeating the level boss, he gets another life
                    }
                }
                else if (random < 100) // if mario loses
                {
                    if (mario.getPowerLevel() <= 1) // if mario loses and his power level is 0 or 1
                    {
                        if (mario.getLives() == 0)
                        {
                            mario.setIsDeadToTrue();
                            recordOfTurn += "Mario fought the level boss and died. "; // mario dies if he has no more lives
                        }
                        else 
                        {
                            mario.takeAwayLife();
                            recordOfTurn += "Mario fought the level boss and lost a life. "; // mario loses a life he has more lives
                        }
                    }
                    else // if mario loses and his power level is 2
                    {
                        mario.decreasePowerLevel();
                        mario.decreasePowerLevel();
                        recordOfTurn += "Mario fought the level boss and decreased 2 power levels. "; // mario decreases 2 power levels and fights the boss again
                    }
                    printedMove += "stay put. "; // mario continues at the same location
                }
                
            }
            else // if it is the final level
            {
                int random = rand() % 100;
                if (random < 50) // if mario wins
                {
                    mario.setHasWonToTrue();
                    recordOfTurn += "Mario fought the final boss and won the game! "; // mario wins the game
                    printedMove += "stay put. ";
                }
                else if (random < 100) // if mario loses
                {
                    if (mario.getPowerLevel() <= 1) // if mario loses and his power level is 0 or 1
                    {
                        if (mario.getLives() == 0)
                        {
                            mario.setIsDeadToTrue();
                            recordOfTurn += "Mario fought the final boss and died. "; // mario dies if he has no more lives
                        }
                        else 
                        {
                            mario.takeAwayLife();
                            recordOfTurn += "Mario fought the final boss and lost a life. "; // mario loses a life he has more lives
                        }
                    }
                    else // if mario loses and his power level is 2
                    {
                        mario.decreasePowerLevel();
                        mario.decreasePowerLevel();
                        recordOfTurn += "Mario fought the final boss and decreased 2 power levels. "; // mario decreases 2 power levels 
                    }
                    printedMove += "stay put. "; // mario continues at the same location
                }

            }
        }
        else if (currentPosition == 'w')
        {
            Gameplay::warp();
            recordOfTurn += "Mario found a warp pipe. "; // mario warps
            printedMove += "WARP";
        }
        
        // add updated stats to string containing record of turn
        recordOfTurn += "Mario has " + to_string(mario.getLives()) + " lives left. Mario has " + to_string(mario.getNumCoins()) + " coins. ";
        recordOfTurn += printedMove;

        // print turn to log
        log << recordOfTurn << endl;
        log << "=============" << endl;
    }

    if (mario.returnIsDead() == true)
    {
        log << "Mario lost the game :( This game lasted " << numMoves << " moves." << endl;
    }
    else
    {
        log << "Mario won the game! This game lasted " << numMoves << " moves." << endl;
    }
}

void Gameplay::move(string nextMove)  // update x or y coordinate variable depending on input
{
    world[z][y][x] = 'x'; // assign old space to 'x',
    if (nextMove == "RIGHT")
    {
        if (x == gridSize - 1)
        {
            x = 0;
        }
        else
        {
            x += 1;
        }
    }
    else if (nextMove == "LEFT")
    {
        if (x == 0)
        {
            x = gridSize -1;
        }
        else
        {
            x -= 1;
        }
    }
    else if (nextMove == "UP")
    {   
        if (y == 0)
        {
            y = gridSize -1;
        }
        else
        {
            y -= 1;
        }
    }
    else if (nextMove == "DOWN")
    {
        if (y == gridSize - 1)
        {
            y = 0;
        }
        else
        {
            y += 1;
        }
    } 
    currentPosition = world[z][y][x]; // update current position
    world[z][y][x] = 'H'; // assign current position to 'H'
}

void Gameplay::moveGoomba(string nextMove)  // update x or y coordinate variable depending on input
{
    world[z][y][x] = 'g'; // assign old space to 'g',
    if (nextMove == "RIGHT")
    {
        if (x == gridSize - 1)
        {
            x = 0;
        }
        else
        {
            x += 1;
        }
    }
    else if (nextMove == "LEFT")
    {
        if (x == 0)
        {
            x = gridSize -1;
        }
        else
        {
            x -= 1;
        }
    }
    else if (nextMove == "UP")
    {   
        if (y == 0)
        {
            y = gridSize -1;
        }
        else
        {
            y -= 1;
        }
    }
    else if (nextMove == "DOWN")
    {
        if (y == gridSize - 1)
        {
            y = 0;
        }
        else
        {
            y += 1;
        }
    } 
    currentPosition = world[z][y][x]; // update current position
    world[z][y][x] = 'H'; // assign current position to 'H'
}

void Gameplay::moveKoopa(string nextMove)  // update x or y coordinate variable depending on input
{
    world[z][y][x] = 'k'; // assign old space to 'k',
    if (nextMove == "RIGHT")
    {
        if (x == gridSize - 1)
        {
            x = 0;
        }
        else
        {
            x += 1;
        }
    }
    else if (nextMove == "LEFT")
    {
        if (x == 0)
        {
            x = gridSize -1;
        }
        else
        {
            x -= 1;
        }
    }
    else if (nextMove == "UP")
    {   
        if (y == 0)
        {
            y = gridSize -1;
        }
        else
        {
            y -= 1;
        }
    }
    else if (nextMove == "DOWN")
    {
        if (y == gridSize - 1)
        {
            y = 0;
        }
        else
        {
            y += 1;
        }
    } 
    currentPosition = world[z][y][x]; // update current position
    world[z][y][x] = 'H'; // assign current position to 'H'
}

void Gameplay::warp()
{
    x = rand() % gridSize; // generate random x coordinate
    y = rand() % gridSize; // generate random y coordinate
    z += 1; // add 1 to the current level
    currentPosition = world[z][y][x]; // update current position
    world[z][y][x] = 'H'; // assign current position to 'H'
}

