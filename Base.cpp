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

/*void Base::NextGen()
{

} */
