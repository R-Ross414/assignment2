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
  or if they would like to input their own. ChooseGameMode is a method that will prompt the user in order to allow choice of game mode */
char Prompt(char userEntry);
char ChooseGameMode(char userChoice);

//Method #1 will generate a random height and method #2 will generate a random width
int RandomHt(); //method #1
int RandomWidth(); //method #2

//Methods #1 and #2 will create variables for height and width based on user file data
int UserFileWidth(string fileName); //method #1
int UserFileHeight(string fileName); //method #2

/*these methods deal directly with the file. Method #1 turns the file name into a
variable to use as a parameter for the other methods. Method #2 uses inputs given by
file and creates a game board */
string getFileName(); //method #1
char** UserFileBoard(int height, int width, string inputFileName, char** gameBoard); //method #2

//This is the method that will be invoked if the user answer is invalid
void InvalidInput();
}
;
