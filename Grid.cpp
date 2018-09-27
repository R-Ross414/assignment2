#include "Grid.h"
#include <iostream>

using namespace std;

//default constructor
Grid::Grid()
{
  this->grid = NULL;
}

//constructor to initialize dimensions
Grid::Grid(int height, int width, char** init)
{
  this->height = height;
  this->width = width;
  this->grid = new char*[height];

  for (int i = 0; i < height; i++)
  {
    this->grid[i] = new char[width];

    for (int j = 0; j < width; j++)
    {
      this->grid[i][j] = init[i][j];
    }
  }
}

void Grid::Copy(char** gameBoard)
{
  //method will be used to copy array for generations
};

//void method for printing the grid
void Grid::Print()
  {
    for (int i = 0; i < this->height; i++)
    {
      for (int j = 0; j <this->width; j++)
      {
        //print out each line of elements
        cout << this->grid[i][j];
      }
      cout << endl;
    }
  }
