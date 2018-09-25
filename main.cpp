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
  //prompt user to ask if they want to insert file or generate random

  Sim* Sim1;
  char input;
  char choice;
  choice = Sim1->Prompt(input);

  //////////////////////if the user chose to generate random///////////////////////
  if (choice == 'R')
  {
    cout << "Generating random grid configuration..." << endl;
  }
  ///////////////////////if user chose to read in file//////////////////////////
  else if (choice == 'F') ////
  {
    string fileName;
    Sim* Sim2;
    Sim2->UserFileEntry(fileName);
    ////////////////////////////////////////////////////////
    /*
    string inputFileName; //variable for file name
    ifstream gridFile; //ifstream object for file content
    cout << "Enter the name of the file" << endl;
    cin >> inputFileName;
    gridFile.open(inputFileName, ios::in);

    ////////////////////////////////////
    int height;
    int width;
    gridFile >> height;
    gridFile >> width;
    //boardFile[height][width];
    //char** boardArray = new char*[height];

    if (gridFile.is_open())
    {
      cout << "Processing file..." << endl;
      cout << "Printing height and width" << endl;
      cout << height << endl;
      cout << width << endl;
    }
    string line = "";
    while (getline(gridFile, line))
    {
      cout << line << endl;
    } */

    char** boardArray = new char*[height];
    Grid* Grid1 = new Grid(height, width);

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
    //Grid1->Print();

///////////probably will delete this set of loops
    /*for (int i = 0; i<height; i++)
    {
      boardArray[i] = new char[width];
      for (int j = 0; j<width; j++)
      {
        boardArray[i][j] = 'X';
      }
    }



    for (int i = 0; i<height; i++)
    {
      cout << "Printing made array " << endl;
      for (int j = 0; j<width; j++)
      {
        cout << boardArray[i][j];
      }
      cout << endl;
    } */
  }

/////////////////////////////if response is invalid///////////////////////////////
  else
  {
    cout << "Not a valid response" << endl;
    exit(0);
  }


  /////////////////////////////////////////////////////////////////////////////
  ////////////////////**TESTING constructor**/////////////////////////////////
  //testing constructor

  //create board arrray


/*  int height = 10;
  int width = 10;
  char** boardArray = new char*[height];
  Grid* Grid1 = new Grid(height, width);

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
  Grid1->Print();*/
  return 0;

}
