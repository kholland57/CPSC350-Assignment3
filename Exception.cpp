
/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 3
*/



#include "Exception.h"

//Default Constructor
Exception::Exception()
{

}

//Destructor
Exception::~Exception()
{
  cout << "Deleting Exception" << endl;
}


//Error thrown when file cannot be opened, system then exits.
void Exception::errorOpenFile(string fileName)
{
  cout << "\nERROR : Could not open file " << fileName  << endl;
  cout << "Exiting Program." << endl;

  exit(1);
}

//Error thrown when the bracket stack is empty.
void Exception::errorStackEmpty(char a, int lineNum)
{
  cout << "\nERROR : Stack is empty." << endl;
  cout << "Line : " << lineNum << " , There is no match for '" << a <<"'"<< endl;
  cout << "Exiting Program." << endl;

  exit(1);
}

//Error thrown when there is a mismatch in brackets. It tells the user
//the location of the opening bracket and the mismatched closing bracket
//that came after.
void Exception::errorMismatch(char a, char b ,char match, int lineNum, int lineNum2)
{
  cout << "\nERROR : Line " << lineNum << endl;
  cout << "Expected :  '" << match << "' for closing '" << a << "'" << endl;
  cout << "Instead, got : '" << b << "' at line " << lineNum2 <<  endl;
  cout << "Exiting Program." << endl;
  exit(1);
}

//Error thrown when the end of a file is reached and an opening bracket
//is not closed.
void Exception::errorEndOfFile(char a, char match, int lineNum)
{
  cout << "\nERROR : Line " << lineNum << endl;
  cout << "At End of file, expected : '" << match << "' for '" << a <<  "'" << endl;
  cout << "Exiting Program." << endl;
  exit(1);
}
