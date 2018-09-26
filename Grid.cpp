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

char** Grid::BoardDimensions(int height, int width)
{
  char** boardArray = new char*[height];
  for (int i = 0; i < height; i++)
  {
    boardArray[i] = new char[width];
    for (int j = 0; j<width; j++)
    {
      boardArray[i][j] = '-';
    }
  }
  return boardArray;
}

char** Grid::CreateBoard(int height, int width)
{
  /*int cellX;
  int cellY;
  int cell; */
  char** gameBoard; /*
  for (int i =0; i < height; i++)
  {
    gameBoard[i] = new char[cellY];
    //>> gameBoard[i];
    for(int j = 0; j < width ; j++)
    {
      gameBoard[j] = new char[cellX];
      cin >> gameBoard[j];
    }
  } */

  return gameBoard;
}


void Grid::Copy(char** gameBoard)
{

  //method will be used to copy array for generations
};

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
