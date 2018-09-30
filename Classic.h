#include <iostream>
#include "Base.h"

using namespace std;

class Classic : public Base
{
public:
  Classic() : Base() {};
  Classic(int height, int width, char** grid) : Base(height, width, grid) {};
  Classic(int height, int width) : Base(height, width) {};
  ~Classic() {};

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
    }
    ;
    if(this->Stable(newBoard))
    {
      return false;
    }
    this->Copy(newBoard);
    if (this->Dead())
    {
      return false;
    }
    return true;

  };

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

      if(playMode == 'E')
      {
        cin.get();
      }
    }

    this->grid->Print();
  }
}
;
