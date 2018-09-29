//#include "Base.h"
//#include "Grid.h"
#include "Sim.h"
#include "Classic.h"
//#include "Donut.h"
//#include "Mirror.h"
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

    /*Set the game board using the configuration and dimensions
    from the user file entry */
    Sim2->UserFileBoard(height, width, fileName, boardArray);

    //Grid* Grid1 = new Grid(height, width, boardArray);
  //  Grid1->Print();

    int x = 0;
    int y = 1;
    /* int n = Grid1->CheckNeighbors(x, y);
    cout << n << endl; */

    Base* Base1 = new Base();
  //  Base1 = new Base(height, width);
    /*Base1->Copy(boardArray);
    Base1->grid->Print(); */

    Classic* Classic1 = new Classic(height, width, boardArray);
    /*for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        cout << Classic1->grid->CheckNeighbors(j, i) << " ";
      }
      cout << endl;
    }*/
    Classic1->NextGen();
    int a = Classic1->grid->CheckNeighbors(2, 0);
    int b = Classic1->grid->CheckNeighbors(3, 0);
    //cout << a << " " << b << endl;
    Classic1->grid->Print();
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
