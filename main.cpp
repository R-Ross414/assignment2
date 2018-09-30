#include "Sim.h"
#include "Classic.h"
#include "Donut.h"
#include "Mirror.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
  int height;
  int width;

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
    Sim* Sim3;

    height = Sim3->RandomHt();
    width = Sim3->RandomWidth();

    cout << "Generating random grid configuration..." << endl;

  }

  //////////////////////////////////////////////////////////////////////////////
  ///////////////////****USER INPUTS FILE CONFIGURATION****/////////////////////
  else if (choice == 'F')
  {
    string fileName;
    Sim* Sim2;

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

    /////////////////////////////////////////////////////////////////////////////////
    /////////////////////////****CHOOSE GAME MODE******////////////////////////////
    Sim* Sim4;
    char inp;
    char mode;
    mode = Sim4->ChooseGameMode(inp);
    char x;
    char playChoice;
    playChoice = Sim4->ChoosePlayMode(x);

    if (mode == 'C')
    {
      cout << "You have chosen classic mode" << endl;
      Classic* Classic1 = new Classic(height, width, boardArray);
      Classic1->Play(playChoice);
    }

    else if (mode == 'D')
    {
      cout << "You have chosen donut mode" << endl;
      Donut* Donut1 = new Donut(height, width, boardArray);
      Donut1->Play(playChoice);
    }

    else if (mode == 'M')
    {
      cout << "You have chosen miror mode" << endl;
      Mirror* Mirror1 = new Mirror(height, width, boardArray);
      Mirror1->Play(playChoice);
    }

    else
    {
      cout << "Invalid response" << endl;
    }
  }

  ///////////////////////////***INVALID RESPONSE****///////////////////////////////
  else
  {
    cout << "Not a valid response" << endl;
    exit(0);
  };
  return 0;
}
