#include "GetInput.h"
#include <fstream>
using namespace std;

int* inputValues;

GetInput::GetInput() // default constructor
{
    
}

GetInput::~GetInput() // default destructor
{

}

int* GetInput::makeArrayOfInput(string input)
{
    fstream reader; // create reader object

    const int arraySize = 8;
    inputValues = new int[arraySize]; // initialize integer array of size equal to the number of inputs

    reader.open(input, ios::in); // open input file

    string specs; // declare variable to store content

     while(getline(reader, specs)){  // while there are lines to be read in the file
        for (int i = 0; i < arraySize; i++) // for each index in the array
        {
            inputValues[i] = stoi(specs); // convert each line of input to an integer and assign to the index
            getline(reader, specs); // move on to the next line
        }
    }

    reader.close(); // close input file

    return inputValues;
}