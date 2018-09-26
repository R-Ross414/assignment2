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

//used if the user wants to use a randomly generated
int RandomHt();
int RandomWidth();
/*these 2 methods generate the height and width given by the user file*/
int UserFileWidth(string fileName);
int UserFileHeight(string fileName);

string getFileName();
void UserFileLines(string fileName); //iterates through all of the lines at once, no return

char UserFileChar(string inputFileName); //gonna make one that iterates one at atime

//This is the method that will be invoked if the user answer is invalid
  void InvalidInput();

  //variables needed for file processing and prompting user
  char choice;
  string inputFileName;
  fstream gridFile;
}
;
