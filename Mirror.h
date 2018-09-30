#include "Base.h"
#include <iostream>

using namespace std;

class Mirror : public Base
{
public:
  Mirror() : Base() {};
  Mirror(int height, int width, char** grid) : Base(height, width, grid)
  {
    this->Boundary();
  };
  Mirror(int height, int width) : Base(height, width) {};
  ~Mirror() {};

  bool NextGen()
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

    if(this->Stable(newBoard))
    {
      return false;
    }

    this->Copy(newBoard);
    this->Boundary();

    if (this->Dead())
    {
      return false;
    }

    return true;
  };
/////////////////////////////////////////////////////////////////
  void Boundary()
  {
    for (int i = 1; i <= height;i++)
    {
      if (this->grid->grid[i][1] == 'X')
      {
        this->grid->grid[i - 1][0] = 'X';
        this->grid->grid[i][0] = 'X';
        this->grid->grid[i + 1][0] = 'X';
      }
    };

    for (int i = 1; i <= height; i++)
    {
      if (this->grid->grid[i][width] == 'X')
      {
        this->grid->grid[i - 1][width + 1] = 'X';
        this->grid->grid[i][width + 1] = 'X';
        this->grid->grid[i + 1][width + 1] = 'X';
      }
    };

    for (int j = 1; j <= width; j++)
    {
      if (this->grid->grid[1][j] == 'X')
      {
        this->grid->grid[0][j - 1] = 'X';
        this->grid->grid[0][j] = 'X';
        this->grid->grid[0][j + 1] = 'X';
      }

    };

    for (int j = 1; j <= width; j++)
    {
      if (this->grid->grid[height][j] == 'X')
      {
        this->grid->grid[height + 1][j - 1] = 'X';
        this->grid->grid[height + 1][j] = 'X';
        this->grid->grid[height + 1][j + 1] = 'X';
      }
    };
  }

  void Play(char playMode)
  {
    int gen = 0;
    cout << "Generation: " << gen << endl;
    this->grid->Print();
    cout << endl;
    while (this->NextGen())
    {
      gen++;
      cout << "Generation: " << gen << endl;
      this->grid->Print();
      cout << endl;
    }
    this->grid->Print();
  }

};
