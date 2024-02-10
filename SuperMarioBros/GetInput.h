#ifndef GETINPUT_H
#define GETINPUT_H
using namespace std;

#include <string>

class GetInput{
    public:
       GetInput(); // default constructor
       ~GetInput(); // default destructor
       int* makeArrayOfInput(string input); // generate and return an integer array containing the numbers on each line of the input file
    private:
       int* inputValues; 
};

#endif
