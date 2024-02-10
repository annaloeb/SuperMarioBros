#ifndef WORLD_H
#define WORLD_H

class World{
    public:
        World(); // default constructor
        ~World(); // default desctructor
        char*** createWorld(int numLevels, int gridSize, int p1, int p2, int p3, int p4, int p5); // create 3-D character array (world) of specified number of levels using createPopulatedLevel() function in level class
    private:
        char*** world;
};

#endif
