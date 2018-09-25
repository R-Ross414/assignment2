#include <iostream>

using namespace std;

class Grid
{
public:
  //base class will be the environment for the cells
    //default constructor
    Grid();
    //constructor needs arguments!!!
    Grid(int height, int width);
    //destructor
    ~Grid();

    //void method for printing
    void Print();
    void Copy(char** );

    //variables for height and with of 2D arrray
    int height;
    int width;
    //variable for array
    char** Board;
      //would be character matrix
        //initialize in constructor and set default configuration


};
