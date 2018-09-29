//#include "Base.h"
//#include "Grid.h"
#include "Sim.h"
//#include "Classic.h"
//#include "Donut.h"
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

    char** boardArray = new char*[height + 2];
    for (int i = 0; i <height + 2; i++)
    {
      boardArray[i] = new char[width + 2];
      for (int j = 0; j < width + 2; j++)
      {
        boardArray[i][j] = '-';
      }
    }

    /*Set the game board using the configuration and dimensions
    from the user file entry */
    Sim2->UserFileBoard(height, width, fileName, boardArray);

    Base* Base1 = new Base();

    /*Classic* Classic1 = new Classic(height, width, boardArray);

    int i = 0;
    while (i < 10)
    {
      Classic1->NextGen();
      Classic1->grid->Print();
      cout << endl;
      i++;
    }

    Classic1->grid->Print();
    cout << endl;
    Classic1->NextGen();
    cout << endl;
    Classic1->grid->Print(); */

    /*Donut* Donut1 = new Donut(height, width, boardArray);
    Donut1->grid->Print();
    cout << endl;
    Donut1->NextGen();
    cout << endl;
    Donut1->grid->Print();
    cout << endl; */

    Mirror* Mirror1 = new Mirror(height, width, boardArray);
    Mirror1->grid->Print();
    cout << endl;
    Mirror1->NextGen();
    cout << endl;
    Mirror1->grid->Print();
    cout << endl;
  }

  /////////////////////////////////////////////////////////////////////////////////
  /////////////////////////****CHOOSE GAME MODE******////////////////////////////
  Sim* Sim4;
  char inp;
  char mode;
  mode = Sim4->ChooseGameMode(inp);

  if (mode == 'C')
    {
      cout << "You have chosen classic mode" << endl;
    }

  else if (mode == 'D')
    {
      cout << "You have chosen donut mode" << endl;
    }

  else if (mode == 'M')
    {
      cout << "You have chosen miror mode" << endl;
    }

  ///////////////////////////***INVALID RESPONSE****///////////////////////////////
  else
  {
    cout << "Not a valid response" << endl;
    exit(0);
  }
  return 0;
}
