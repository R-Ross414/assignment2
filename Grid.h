#include <iostream>


using namespace std;

class Grid
{
public:
  //base class will be the environment for the cells
    //default constructor
    Grid();
    //constructor to initialize the grid given dimensions
    Grid(int height, int width, char** init);
    //blank grid constructor
    Grid(int height, int width);
    //destructor
    ~Grid();

    //class variable for the grid
    char** grid;

    //void method for printing the grid
    void Print();
    //void Copy(char** );

    //function to check number of living neighbors
    int CheckNeighbors(int x, int y);

    //variables for height and with of 2D arrray
    int height;
    int width;

};
