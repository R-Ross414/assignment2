#include <iostream>
#include "Grid.h"

using namespace std;

class Base
{
public:

  Base(Grid& board1);
  ~Base();

  void Copy(char** gameBoard);

  char** base;

  Grid board1;

}
;
