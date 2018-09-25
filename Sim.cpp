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

/*Sim::UserFile()
{

} */
