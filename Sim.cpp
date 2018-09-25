#include "Sim.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//constructor
Sim::Sim()
{

}

char Sim::Prompt(char userEntry)
{
  char choice;
  //prompt user to ask if they want to insert file or generate random
  cout << "Would you like to use a random file or your own?" << endl;
  cout << "Enter 'R' for random and 'F' for your own" << endl;
  cin >> choice;
  return choice;
}

/*Sim::Random()
{

}
*/

void Sim::UserFileEntry(string fileName)
{
  //This is for inputting the name of a file and opening it
  string inputFileName;
  ifstream gridFile;
  cout << "Enter the name of the file" << endl;
  cin >> inputFileName;
  gridFile.open(inputFileName, ios::in);

  //the file object will read in the first 2 lines as height and width of the game board
  int height;
  int width;
  gridFile >> height;
  gridFile >> width;

  if (gridFile.is_open())
  {
    cout << "Processing file" << endl;
    cout << "Printing height and width" << endl;
    cout << height << endl;
    cout << width << endl;
  }

  string line = "";
  while (getline(gridFile, line))
  {
    cout << line << endl;
  }
}



void Sim::InvalidInput()
{
  cout << "Invalid input" << endl;
  exit(0);
}
