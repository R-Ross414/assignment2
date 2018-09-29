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
    //int cells = 1;
    for (int i = 1; i <= this->height; i++)
    {
      for (int j = 1; j <= this->width; j++)
      {
        int cells = grid->CheckNeighbors(j - 1, i - 1);
        //cout << cells << " ";

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

      //cout << endl;

    };
    Grid* grid1 = new Grid(height, width, newBoard);
    //grid1->Print();
    this->Copy(newBoard);

  };

}
;
