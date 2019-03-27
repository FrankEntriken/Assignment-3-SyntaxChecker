#include "SyntaxChecker.h"
#include "GenStack.h"
#include <iostream>
#include <fstream>


using namespace std;

SyntaxChecker::SyntaxChecker() //constructor
{

}

SyntaxChecker::~SyntaxChecker() //destructor
{

}

void SyntaxChecker::CheckFile(ifstream &inputFile)
{
  //uses stack class to store open parenthesis and brackets
  //instantiate needed variables
  GenStack myStack;
  int open = 0;
  int close = 0;
  char openChar, closeChar;
  int lineNumber = 0;
  string str;

  //for every string in file
  while(getline(inputFile, str))
  {
    lineNumber++;

    //for every character in string
    for(int i = 0; i < str.size(); i++)
    {
      //OPEN-----------------------
      //[
      if(str[i] == ('['))
      {
        myStack.push(1);
        openChar = str[i];
      }

      //{
      if(str[i] == ('{'))
      {
        myStack.push(2);
        openChar = str[i];
      }

      //(
      if(str[i] == ('('))
      {
        myStack.push(3);
        openChar = str[i];
      }

      //CLOSED-----------------------
      //]
      if(str[i] == (']'))
      {
        open = myStack.pop();
        close = 1;
        closeChar = str[i];
      }

      //}
      if(str[i] == ('}'))
      {
        open = myStack.pop();
        close = 2;
        closeChar = str[i];
      }

      //)
      if(str[i] == (')'))
      {
        open = myStack.pop();
        close = 3;
        closeChar = str[i];
      }

      //if delimiters match
      if(open == close)
      {
        continue;
      }
      else
      {
        switch(open)
        {
          case 1:
            openChar = ']';
            break;
          case 2:
            openChar = '}';
            break;
          case 3:
            openChar = ')';
            break;
        }
        cout << "ERROR: Line " << lineNumber << ": ";
        cout << "Expected " << openChar << ", found " << closeChar << endl;

        exit(0);
      }
    }
  }
  cout << "FILE HAS NO ERRORS" << endl;
}
