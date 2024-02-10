#include "Level.h"
#include <cstdlib>

char** level;

Level::Level() // default constructor
{

}

Level::~Level() // default destructor
{

}

char** Level::createPopulatedLevel(int gridSize, int p1, int p2, int p3, int p4, int p5)
{
    level = new char*[gridSize];
    for (int i = 0; i < gridSize; i++)
    {
        level[i] = new char[gridSize];
    }
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            int random = rand() % 100;
            if (random < p1)
            {
                level[i][j] = 'c';
            }
            else if (random < p1 + p2)
            {
                level[i][j] = 'x';
            }
            else if (random < p1 + p2 + p3)
            {
                level[i][j] = 'g';
            }
            else if (random < p1 + p2 + p3 + p4)
            {
                level[i][j] = 'k';
            }
            else if (random < p1 + p2 + p3 + p4 + p5)
            {
                level[i][j] = 'm';
            }
        }
    }
    int x = rand() % gridSize;
    int y = rand() % gridSize;
    level[x][y] = 'b'; // randomly declare a boss on every level
    return level;
}
