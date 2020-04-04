

/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 3
*/


//Libraries included here
#include <iostream>
#include <fstream>
#include <string>
#include "GenStack.h"
#include "Exception.h"

using namespace std;

class SyntaxCheck
{
  public:

    //Constructors
    SyntaxCheck();
    SyntaxCheck(string fileName);
    ~SyntaxCheck();

    //Other Methods
    void readInFile(string fileName);
    bool continuePrompt();
    int countBrackets();
    bool checkSyntax(string codeFile, int numBrackets);
    bool checkType(char a, char b);

    //Accessors/Mutatiors
    char getMatch(char a );
    string getUserString();

//Private Variables
private:
  string userFile;
  string userString;
  Exception *errorCheck;

};
