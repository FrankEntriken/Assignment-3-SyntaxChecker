#include "GenStack.h"
#include "SyntaxChecker.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  //instantiate class and needed variables
  SyntaxChecker s;
  char input;
  string userFile;

  //while true used to ask user if they would like to check another file
  while(true)
  {
    cout << "Please enter the name of the file... ";
    cin >> userFile;

    ifstream inputFile;
    inputFile.open(userFile);

    if(!inputFile)
    {
      cout << "Unable to find file" << endl;
      exit(1);
    }

    //run the syntax checking method
    s.CheckFile(inputFile);

    //ask user for another file
    cout << "Would you like to syntax check another file? (y/n)... ";
    cin >> input;
    cout << endl;

    //yes
    if(input == 'y' || input == 'Y')
    {
      continue;
    }

    //no
    if(input == 'n' || input == 'N')
    {
      exit(1);
    }

    //invalid
    else
    {
      cout << "Input is not valid" << endl;
      exit(1);
    }
  }
}
