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
  this->grid = new char*[height + 2];

  for (int i = 0; i < height + 2; i++)
  {
    this->grid[i] = new char[width + 2];

    for (int j = 0; j < width + 2; j++)
    {
      this->grid[i][j] = '-';
    }
  }

  for (int i = 1; i <= height; i++)
  {
    for (int j = 1; j <= width; j++)
    {
      this->grid[i][j] = init[i][j];
    }
  }
}

Grid::Grid(int height, int width)
{
  this->height = height;
  this->width = width;
  this->grid = new char*[height + 2];

  for (int i = 0; i < height + 2; i++)
  {
    this->grid[i] = new char[width + 2];

    for (int j = 0; j < width + 2; j++)
    {
      this->grid[i][j] = '-';
    }
  }
}

Grid::~Grid()
{
  delete[] grid;
  grid = NULL;
  height = 0;
  width = 0;
}

/*void Grid::Copy(char** gameBoard)
{
  //method will be used to copy array for generations
}; */

//void method for printing the grid
void Grid::Print()
  {
    for (int i = 0; i <= this->height + 1; i++)
    {
      for (int j = 0; j <= this->width + 1; j++)
      {
        //print out each line of elements
        cout << this->grid[i][j];
      }
      cout << endl;
    }
  }

int Grid::CheckNeighbors(int x, int y)
{
  int sum = 0;

  for (int i = -1; i <= 1; i++)
  {
    for (int j = -1; j <= 1; j++)
    {
      //cout << grid[y+i+1][x+j+1] << " ";
      if (grid[y + i + 1][x + j + 1] == 'X')
      {
        sum++;
      }
    }
    //cout << endl;
  }

  if (grid[y + 1][x + 1] == 'X')
  {
    sum-= 1;
  }

  return sum;
  /*else
  {
    return sum;
  } */
}
