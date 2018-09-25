#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Sim
{
public:
  Sim();
  ~Sim();

/*Prompt will be used to ask the user if they want to generate a random grid configuration
  or if they would like to input their own */
  char Prompt(char userEntry);

  //Random();
//UserFileEntry will be used to process an input file given by the user
  void UserFileEntry(string fileName);

//This is the method that will be invoked if the user answer is invalid
  void InvalidInput();

  //variables needed for file processing and prompting user
  char choice;
  string inputFileName;
  fstream gridFile;
}
;
