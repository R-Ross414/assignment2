#include "Grid.h"
#include <iostream>

using namespace std;

//default constructor
Grid::Grid()
{
  Board = NULL;
}

//constructor to initialize dimensions
Grid::Grid(int height, int width)
{
  this->height = height;
  this->width = width;

  //setting grid height
  Board = new char*[height];
  for (int i = 0; i < height; i++)
  {
    //setting grid width
    Board[i] = new char[width];

    //initializes empty cell for all grid locations
    for (int j = 0; j < width; j++)
    {
      Board[i][j] = '-';
    }
  }
}


//void method for printing the grid
void  Grid::Print()
  {
    for (int i = 0; i < this->height; i++)
    {
      for (int j = 0; j <this->width; j++)
      {
        //print out each line of elements
        cout << Board[i][j];
      }
      cout << endl;
    }
  }
