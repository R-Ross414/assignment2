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
    int height;
    int width;
    Sim* Sim3;

    height = Sim3->RandomHt();
    width = Sim3->RandomWidth();

    cout << "Generating random grid configuration..." << endl;
    char** boardArray = new char*[height];
    Grid* Grid1 = new Grid(height, width);
    Grid1->BoardDimensions(height, width);

    Grid1->Print();

  }

  ///////////////////////if user chose to read in file//////////////////////////
  else if (choice == 'F')
  {
    string fileName;
    int height;
    int width;
    Sim* Sim2;
    char s;

    fileName = Sim2->getFileName();
    height = Sim2->UserFileHeight(fileName);
    width = Sim2->UserFileWidth(fileName);

    char** boardArray = new char*[height];
    Grid* Grid1 = new Grid(height, width);
    Grid1->BoardDimensions(height, width);

    
    s = Sim2->UserFileChar(fileName);
    cout << s << endl;
    //Sim2->UserFileLines(fileName);

    //int cellLocation;
    //Grid1->CreateBoard(height, width);
    //boardArray[4][5] = 'X';
    //Grid1->Copy(boardArray);
    Grid1->Print();
  }

/////////////////////////////if response is invalid///////////////////////////////
  else
  {
    cout << "Not a valid response" << endl;
    exit(0);
  }
  return 0;

}
