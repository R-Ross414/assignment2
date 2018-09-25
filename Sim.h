#include <iostream>
#include <fstream>
#include <string>

class Sim
{
public:
  Sim();
  char Prompt(char userEntry);
  //Random();
  //UserFile();
  ~Sim();

  //variables needed for file processing and prompting user
  char choice;
  std::string inputFileName;
  std::fstream gridFile;
}
;
