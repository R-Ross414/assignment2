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

  /////////////////////////////////////////////////////////////////////////////
  //////////////////////******RANDOM CONFIGURATION*******///////////////////////
  if (choice == 'R')
  {
    int height;
    int width;
    Sim* Sim3;

    height = Sim3->RandomHt();
    width = Sim3->RandomWidth();

    cout << "Generating random grid configuration..." << endl;
    
    //char** boardArray = new char*[height];
    //Grid* Grid1 = new Grid(height, width, boardArray);
    //Grid1->Print();
  }

  //////////////////////////////////////////////////////////////////////////////
  ///////////////////****USER INPUTS FILE CONFIGURATION****/////////////////////
  else if (choice == 'F')
  {
    string fileName;
    int height;
    int width;
    Sim* Sim2;
    char s;
    Grid* Grid2;

    fileName = Sim2->getFileName();
    height = Sim2->UserFileHeight(fileName);
    width = Sim2->UserFileWidth(fileName);

    char** boardArray = new char*[height];
    for (int i = 0; i <height; i++)
    {
      boardArray[i] = new char[width];
      for (int j = 0; j < width; j++)
      {
        boardArray[i][j] = '-';
      }
    }

    Sim2->UserFileBoard(height, width, fileName, boardArray);
    Grid* Grid1 = new Grid(height, width, boardArray);
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
