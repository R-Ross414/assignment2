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

char Sim::ChooseGameMode(char userChoice)
  {
    char mode;
    cout << "Please choose a game mode." << endl;
    cout << "Enter 'C' for classic mode." << endl;
    cout << "Enter 'D' for donut mode." << endl;
    cout << "Enter 'M' for mirror mode." << endl;
    cin >> mode;
    return mode;
  }


int Sim::RandomHt()
{
  int height;
  cout << "Enter a height" << endl;
  cin >> height;
  return height;
}

int Sim::RandomWidth()
{
  int width;
  cout << "Enter a width" << endl;
  cin >> width;
  return width;
}

void Sim::RandomInit(int height, int width, double density, char** randomBoard)
{
  
}
string Sim::getFileName()
{
  //this method is only for the purpose of making a variable for file name
  string inputFileName;
  cout << "Enter the name of the file" << endl;
  cin >> inputFileName;
  return inputFileName;
}

int Sim::UserFileWidth(string inputFileName)
{
  //This is for inputting the name of a file and opening it
  ifstream gridFile;
  gridFile.open(inputFileName, ios::in);

  //iterate through lines to get the width
  int line_no = 0;
  string line = "";
  while (line_no != 1 && getline(gridFile, line))
  {
    line_no++;
  };

  //the file object will read in the width of the game board
  int width;
  if (line_no == 1)
  {
    gridFile >> width;
  }
  return width;
}

int Sim::UserFileHeight(string inputFileName)
{
  ifstream gridFile;
  gridFile.open(inputFileName, ios::in);

  int line_no = 0;
  string line = "";

  //the file object will read in the height of the game board
  int height;
  if (line_no == 0)
  {
    gridFile >> height;
  }

  return height;
}

char** Sim::UserFileBoard(int height, int width, string inputFileName, char** gameBoard)
{
  ifstream gridFile;
  int line_no = 0;
  gridFile.open(inputFileName, ios::in);

  string line = "";

  //skips through the first 2 lines which have the dimensions
  while (line_no < 2 && getline(gridFile, line))
  {
    line_no++;
  };

  int i = 1;

  while (i <= height && getline(gridFile, line))
  {
    for (int j = 1; j <= line.size(); j++)
    {
      gameBoard[i][j] = line[j - 1];
    };
    i++;
  };

  return gameBoard;
}


void Sim::InvalidInput()
{
  cout << "Invalid input" << endl;
  exit(0);
}

char Sim::ChoosePlayMode(char playChoice)
{
  cout << "Choose a play mode" << endl;
  cout << "Enter 'E' to press enter between each generation" << endl;
  cout << "Enter 'L' for it to continue on its own" << endl;
  cin >> playChoice;
  return playChoice;
}
