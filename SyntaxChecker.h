#include <iostream>

using namespace std;

class SyntaxChecker
{
  public:
    SyntaxChecker(); //constructor
    ~SyntaxChecker(); //destructor
    void CheckFile(ifstream &inputFile);
};
