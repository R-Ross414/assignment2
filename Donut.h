#include "Base.h"
#include <iostream>

using namespace std;

class Donut : public Base
{
public:
  Donut() : Base() {};
  Donut(int height, int width, char** grid) : Base(height, width, grid)
  {
    this->Boundary();
  };
  Donut(int height, int width) : Base(height, width) {};
  ~Donut() {};

  void NextGen()
  {
    //initialize board for new generation
    char** newBoard = new char*[height + 2];
    for (int i = 0; i < height + 2; i++)
    {
      newBoard[i] = new char[width + 2];

      for (int j = 0; j < width + 2; j++)
      {
        newBoard[i][j] = '-';
      }
    }

    //nested for loop over the board checking neighbors
    for (int i = 1; i <= this->height; i++)
    {
      for (int j = 1; j <= this->width; j++)
      {
        int cells = grid->CheckNeighbors(j - 1, i - 1);

        //if statements to determine alive or dead next gen
        if (cells <= 1)
        {
          newBoard[i][j] = '-';//dead
        }
        else if (cells == 2)
        {
          newBoard[i][j] = grid->grid[i][j];//stays dead or stays alive
        }
        else if (cells == 3)
        {
          newBoard[i][j] = 'X';//stays alive or becomes alive
        }
        else if (cells >= 4)
        {
          newBoard[i][j] = '-';//cell dies
        }
      }

    };
    Grid* grid1 = new Grid(height, width, newBoard);
    this->Copy(newBoard);
    this->Boundary();

  };

void Boundary()
{
  for (int i = 1; i <= height;i++)
  {
    this->grid->grid[i][0] = this->grid->grid[i][width];
  };

  for (int i = 1; i <= height; i++)
  {
    this->grid->grid[i][width + 1] = this->grid->grid[i][1];
  };

  for (int j = 1; j <= width; j++)
  {
    this->grid->grid[0][j] = this->grid->grid[height][j];
  };

  for (int j = 1; j <= width; j++)
  {
    this->grid->grid[height+1][j] = this->grid->grid[1][j];
  };
}

}
;
