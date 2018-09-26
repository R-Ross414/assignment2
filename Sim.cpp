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

int Sim::RandomHt()
{
  //generates random height
  int height = (rand()%(10)+1);
  cout << height << endl;
  return height;
}

int Sim::RandomWidth()
{
  //generates random wicth
  int width = (rand()%(10)+1);
  cout << width << endl;
  return width;
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

  int width;
  if (line_no == 1)
  {
    gridFile >> width;
  }

  //the file object will read in the width of the game board

  if (gridFile.is_open())
  {
    //insert for loop to iterate throught text lines
    cout << "Printing width" << endl;
    cout << width << endl;
  }

  return width;
}

int Sim::UserFileHeight(string inputFileName)
{
  ifstream gridFile;
  gridFile.open(inputFileName, ios::in);

  int line_no = 0;
  string line = "";
  /*while (line_no != 0 && getline(gridFile, line))
  {
    line_no++;
  }; */

  int height;
  if (line_no == 0)
  {
    gridFile >> height;
  }

  //the file object will read in the height of the game board
  if (gridFile.is_open())
  {
    cout << "Printing height" << endl;
    cout << height << endl;
  }
  return height;
}

void Sim::UserFileLines(string inputFileName)
{
  ifstream gridFile;
  gridFile.open(inputFileName, ios::in);

  int line_no = 0;
  string line = "";
  while (line_no <= 1 && getline(gridFile, line))
  {
    line_no++;
  };

  while (line_no > 1 && getline(gridFile, line))
  {
    cout << line << endl;
  }
}

char Sim::UserFileChar(string inputFileName)
{
  ifstream gridFile;
  gridFile.open(inputFileName, ios::in);
  char l;

  //indexes through file and returns one char at a time
  int line_no = 0;
  string line = "";

  //do not return the dimensionis of the grid
  while (line_no < 2 && getline(gridFile, line))
  {
    line_no++;
  };

  //return the characters
  while (line_no >= 2 && getline(gridFile, line))
  {
    for (int i = 0; i < line.size(); i++)
    {
      l = line[i];
      cout << l << endl;
    };
  };

  return l;
}


void Sim::InvalidInput()
{
  cout << "Invalid input" << endl;
  exit(0);
}
