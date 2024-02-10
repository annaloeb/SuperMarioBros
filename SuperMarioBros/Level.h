#ifndef LEVEL_H
#define LEVEL_H

class Level{
    public:
        Level(); // default constructor
        ~Level(); // default destructor
        char** createPopulatedLevel(int gridSize, int p1, int p2, int p3, int p4, int p5); //create populated 2-D character array (level) given dimensions and probabilities
    private:
        char** levelGrid;
};

#endif