
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

using namespace std;

class Exception
{
  public:
    //Constructors
    Exception();
    ~Exception();

    //Other methods
    void errorOpenFile(string fileName);
    void errorStackEmpty(char a, int lineNum);
    void errorEndOfFile(char a, char match, int lineNum);
    void errorMismatch(char a, char b, char match, int lineNum, int lineNum2);

};
