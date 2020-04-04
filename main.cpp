

/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 3
*/

//Libraries included here
#include "SyntaxCheck.h"
#include <iostream>
using namespace std;

//Main method for the program
int main(int argc, char **argv){

  if (argc <2){
    cout << "Invalid text file input. Exiting program." << endl;
    return 1;
  }
  string fName = argv[1];
  bool stop = true;

//The program will continue in this while loop until an error is found,
//or the user chooses to exit
  while(stop == true){

    SyntaxCheck *check = new SyntaxCheck();

    check->readInFile(fName);
    int numBrackets = check->countBrackets();

    string fileInfo = check->getUserString();
    check->checkSyntax(fileInfo,numBrackets);

    stop = check->continuePrompt();
    if (stop == false)
    {
      delete check;
      break;
    }

    delete check;
    cout << "Enter the name of the file to read in : " << endl;
    cin >> fName;

  }


  return 0;
}
