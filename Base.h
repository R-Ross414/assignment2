#include <iostream>
#include "Grid.h"

using namespace std;

class Base
{
public:

  Base();
  Base(int height, int width, char** grid);
  Base(int height, int width);
  ~Base();

  void Copy(char** gameBoard);
  //void NextGen();

  Grid* grid;
  int height;
  int width;

}
;
