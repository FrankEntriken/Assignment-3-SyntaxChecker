#include "GenStack.h"
#include <iostream>

using namespace std;

GenStack::GenStack() //default constructor
{
  //initialize variable to default values
  myArray = new char[1];
  size = 1;
  top = -1;
}

GenStack::GenStack(int maxSize) //overloaded constructor
{
  myArray = new char[maxSize];
  size = maxSize;
  top = -1;
}

GenStack::~GenStack() //destructor
{
  //what do we need to do here??
  //LETS build some character
}

void GenStack::push(char d)
{
  //make sure stack is not StackFull
  //you are responsible for error/bound checking
  if(isFull())
  {
    newStack();
    myArray[++top] = d;
  }
  else
  {
    myArray[++top] = d;
  }
}

char GenStack::pop()
{
  //error checking
  if(isEmpty())
  {
    cout << "POP ERROR: Can not pop; stack is empty..." << endl;
    return 0;
  }
  else
  {
    char temp = myArray[top--];
    return temp;
  }
}

char GenStack::peek()
{
  //error checking
  if(isEmpty())
  {
    cout << "PEEK ERROR: Can not peek; stack is empty..." << endl;
    return 0;
  }
  else
  {
    return myArray[top];
  }
}

bool GenStack::isFull()
{
  return (top == size-1);
}

bool GenStack::isEmpty()
{
  return (top == -1);
}

int GenStack::getSize()
{
  return top+1;
}

//https://www.whitman.edu/mathematics/c++_online/section04.03.html
void GenStack::newStack()
{
  char *newArray;
  newArray = new char[size+1];
  for(int i = 0; i < size + 1; i++)
  {
    newArray[i] = myArray[i];
  }
  delete [] myArray;
  myArray = newArray;
  size++;
}
