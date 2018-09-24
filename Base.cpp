#include "Base.h"
#include <iostream>
#include <fstream>

using namespace std;

//building out the base class

//default constructor
Base::Base()
{
  Grid = NULL;
}

//constructor to initialize dimensions
Base::Base(int height, int width)
{
  this->height = height;
  this->width = width;

  //setting grid height
  Grid = new char*[height];
  for (int i = 0; i < height; i++)
  {
    //setting grid width
    Grid[i] = new char[width];

    //initializes empty cell for all grid locations
    for (int j = 0; j < width; j++)
    {
      Grid[i][j] = '-';
    }
  }
}


//void method for printing the grid
void  Base::Print()
  {
    for (int i = 0; i < this->height; i++)
    {
      for (int j = 0; j <this->width; j++)
      {
        //print out each line of elements
        cout << Grid[i][j];
      }
      cout << endl;
    }
  }

void Base::Copy(char** boardArray)
{
  //delete this->Base1;
  //Base1 = boardArray;
  //set old board = new board
}

/*Base::CheckNeighbors(int x, int y)
{

  return numAlive;
} */
