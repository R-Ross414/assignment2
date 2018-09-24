#include <iostream>

//base class will be the environment for the cells
class Base
{
public:
  //default constructor
  Base();
  //constructor needs arguments!!!
  Base(int height, int width);
  //destructor
  ~Base();

  //assignment operator (we will worry about this later )

  //void method for printing
  void Print();
  void Copy(char** );

  //variables for height and with of 2D arrray
  int height;
  int width;
  //variable for array
  char** Grid;
    //would be character matrix
      //initialize in constructor and set default configuration


};
