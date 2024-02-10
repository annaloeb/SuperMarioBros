#include "World.h"
#include "Level.h"
#include <cstdlib>

Level l;

World::World() // default constructor declares the 3-D array
{
    char*** world;
}

World::~World() // default destructor 
{

}

char*** World::createWorld(int numLevels, int gridSize, int p1, int p2, int p3, int p4, int p5)
{
    world = new char**[numLevels];
    for (int i = 0; i < numLevels; i++)
    {
        world[i] = l.createPopulatedLevel(gridSize, p1, p2, p3, p4, p5); // create a populated level for the specified number of levels
    }
    for (int i = 0; i < numLevels - 1; i++) // add warp pipe to all levels except the last 
    {
        int x = rand() % gridSize;
        int y = rand() % gridSize;
        world[i][x][y] = 'w';
    }
    return world;
}