#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <string>
using namespace std;

class Gameplay{
    public:
        Gameplay(); // default constructor
        Gameplay(int numLevels, int gridSize, int lives, int p1, int p2, int p3, int p4, int p5); // overloaded constructor given all input 
        ~Gameplay(); // default destructor
        void playGame(string output); // runs and logs the game until mario is dead or has won
    private:
        char*** w;
        char currentPos;
        int numberOfMoves;
        int numLevels;
        int varGridSize;
        int xcor;
        int ycor;
        int zcor;
        void move(string nextMove); // move given the next direction
        void moveGoomba(string nextMove); // move normally but keep goomba in place
        void moveKoopa(string nextMove); // move normally but keep koopa in place
        void warp(); // randomly spawn to next level
};

#endif
