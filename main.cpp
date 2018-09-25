#include "Base.h"
#include "Grid.h"
#include "Sim.h"
#include "Classic.h"
#include "Donut.h"
#include "Mirror.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

  /////////////////////////////////////////////////////////////////////////////
  //////////////////////****PROMPTING USER****/////////////////////////////////
  //variables needed for file processing and prompting user

  /*char choice;
  string inputFileName;
  ifstream gridFile;

  //prompt user to ask if they want to insert file or generate random

  cout << "Would you like to use a random file or your own?" << endl;
  cout << "Enter 'R' for random and 'F' for your own" << endl;
  cin >> choice; */

//variable for what the user will enter
  char*  userEntry;
  userEntry.Prompt(userEntry);


  //if generate random
  if (choice == 'R')
  {
    cout << "Generating random grid configuration..." << endl;
  }
  //if read in file
  else if (choice == 'F') ////
  {
    ///////cout << "Your file" << endl;
    cout << "Enter the name of the file" << endl;
    cin >> inputFileName;
    gridFile.open(inputFileName, ios::in);

    if (gridFile)
    {
      cout << "Processing file..." << endl;
    }

    ////////////////////////////////////
    int height;
    int width;
    gridFile >> height;
    gridFile >> width;
    //boardFile[height][width];
    char** boardArray = new char*[height];

    for (int i = 0; i<height; i++)
    {
      boardArray[i] = new char[width];
      for (int j = 0; j<width; j++)
      {
        boardArray[i][j] = 'X';
      }
    }

    if (gridFile.is_open())
    {
      cout << "Printing height and width" << endl;
      cout << height << endl;
      cout << width << endl;
    }

    string line = "";
    while (getline(gridFile, line))
    {
      cout << "Printing lines" << endl;
      cout << line << endl;
    }  /////


    for (int i = 0; i<height; i++)
    {
      cout << "Printing made array " << endl;
      for (int j = 0; j<width; j++)
      {
        cout << boardArray[i][j];
      }
      cout << endl;
    }
  }

  else
  {
    cout << "Not a valid response" << endl;
    exit(0);
  }


  /////////////////////////////////////////////////////////////////////////////
  ////////////////////**TESTING constructor**/////////////////////////////////
  //testing constructor

  //create board arrray
  //pick locations for 4,5 = x


  /*int height = 10;
  int width = 10;
  char** boardArray = new char*[height];
  Base* Base1 = new Base(height, width);

  for (int i = 0; i< height; i++)
  {
    boardArray[i] = new char[width];
    for (int j = 0; j<width; j++)
    {
      boardArray[i][j] = '-';
    }
  }

  //boardArray[4][5] = 'X';
  //Base1->Copy(boardArray);
  Base1->Print(); */
  return 0;

}
