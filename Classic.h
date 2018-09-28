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
    //nested for loop over the board checking neighbors
      /*initialize the new board according to conditions for number of neighbors 
      in the old board */
  };

}
;
