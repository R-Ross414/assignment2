#include "Base.h"
#include <iostream>
#include <fstream>

using namespace std;

//building out the base class

Base::Base()
{
  this->height = 0;
  this->width = 0;
  this->grid = NULL;
}

Base::Base(int height, int width, char** grid)
{
  this->height = height;
  this->width = width;
  this->grid = new Grid(height, width, grid);
}

Base::Base(int height, int width)
{
  this->height = height;
  this->width = width;
  this->grid = new Grid(height, width);
}

void Base::Copy(char** gameBoard)
{
  delete grid;
  grid = NULL;
  grid = new Grid(height, width, gameBoard);
  //Base1 = boardArray;
  //set old board = new board
}


bool Base::Dead()
{
  for(int i = 1; i <= height; i++)
  {
    for(int j =1; j <= width; j++)
    {
      if (this->grid->grid[i][j] == 'X')
      {
        return false;
      }
    }
  }
  return true;
}

bool Base::Stable(char** newBoard)
{
  bool stable = true;
  for(int i = 1; i<= height; i++)
  {
    for(int j = 1; j <= width; j++)
    {
      if (this->grid->grid[i][j] != newBoard[i][j])
      {
        stable = false;
      }
    }
  }
  return stable; 
}
