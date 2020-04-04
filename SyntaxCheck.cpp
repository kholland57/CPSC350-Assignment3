
/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 3
*/

#include "SyntaxCheck.h"


//Default Constructor
SyntaxCheck::SyntaxCheck()
{
  userFile = "";
  errorCheck = new Exception();
}

//Overloaded Constructor
SyntaxCheck::SyntaxCheck(string fileName)
{
  userFile = fileName;
  errorCheck = new Exception();
}

//Destructor
SyntaxCheck::~SyntaxCheck()
{
  cout << "Deleting SyntaxCheck" << endl;
  delete errorCheck;
}



//------------------------------------------------------------------------------
//Other Methods

//This method reads in a file from a given string name. If it cannot open
//successfully, the program exits. The file contents are stored as a string.
void SyntaxCheck::readInFile(string fileName)
{
  ifstream inFS;

  string fileContent = "";
  string totalString = "";
  cout << "Opening " << fileName << endl;
  inFS.open(fileName);

  if (!inFS.is_open())
  {
    errorCheck->errorOpenFile(fileName);
  }

  while (!inFS.eof()) {

    getline(inFS, fileContent);
    if (!inFS.fail()) {
        totalString = totalString + fileContent + "\n";
     }
  }
  inFS.close();
  userString = totalString;
}
//------------



//This asks the user if they wish to continue, and returns true if they
//do or false if they do not.

bool SyntaxCheck::continuePrompt()
{
  string continuePrompt = "";
  cout << "Would you like to read in another file?" << endl;
  cout << "Enter 'yes' to continue or 'no' to quit. " << endl;

  cin >> continuePrompt;
  if (continuePrompt == "yes")
  {
    cout << "Program will continue." << endl;
    return true;
  }
  else if (continuePrompt == "no")
  {
    cout << "Exiting Program." << endl;
    return false;

  }
  else
  {
    cout << "Invalid entry. Program will exit." << endl;
    return false;
  }

  return false;
}
//------------


//This counts the number of brackets in the script
int SyntaxCheck::countBrackets(){
  int numBrackets = 0;
  for (int i = 0; i < userString.length(); ++i)
  {
    if (userString[i] == '(')
      numBrackets += 1 ;
    if (userString[i] == ')')
      numBrackets += 1 ;
    if (userString[i] == '{')
      numBrackets += 1 ;
    if (userString[i] == '}')
      numBrackets += 1 ;
    if (userString[i] == '[')
      numBrackets += 1 ;
    if (userString[i] == ']')
      numBrackets += 1 ;
  }
  return numBrackets;
}
//------------


//This checks the syntax of the file string by creating two stacks. Each time
//and opening bracket is found, it is popped into the stack stackCheck.
//The stack stackNum tracks the line the bracket is on.

//If the stack is empty, there are more closing braces then opening and the
//program will throw an error. In other situations such as a mismatch or missing
//opening brace, the system will throw an error.
bool SyntaxCheck::checkSyntax(string codeFile, int numBrackets)
{
  int lineNumber = 1;

  GenStack<char> *stackCheck = new GenStack<char>(numBrackets);
  GenStack<int> *stackNum = new GenStack<int>(numBrackets);

  for (int i = 0; i < codeFile.length(); ++i)
  {
    if (codeFile[i] == '\n')
    {
      lineNumber += 1;
    }

    if ( (codeFile[i] ==  '(' )|| (codeFile[i] == '{' )||(codeFile[i] ==  '[' ))
    {
      stackCheck->push(codeFile[i]);
      stackNum->push(lineNumber);
    }
    else if ((codeFile[i] == ')' )||(codeFile[i] ==  '}' )||(codeFile[i] ==  ']') )
    {
      //No opening braces to match with the closing one.
      if (stackCheck->isEmpty() == true)
      {

        errorCheck->errorStackEmpty(codeFile[i],lineNumber);
        delete stackNum;
        delete stackCheck;
        return false;
      }

      //This checks if the type of the openign and closing bracket is the same.
      //An error is thrown if there is a mismatch.
      if (checkType(stackCheck->peek(), codeFile[i]) == false)
      {
        errorCheck->errorMismatch(stackCheck->peek(),codeFile[i],getMatch(stackCheck->peek()), stackNum->peek(), lineNumber);
        return false;
      }

      stackCheck->pop();
      stackNum->pop();
    }
  }
  //This if statement runs if there are no errors.
  if (stackCheck->isEmpty() == true)
  {
    delete stackNum;
    delete stackCheck;
    cout << "No errors found." << endl;
    return true;
  }
  else
  {
  //End of file error is thrown here if otherwise
    char misMatched= stackCheck->peek();
    errorCheck->errorEndOfFile(misMatched,getMatch(misMatched), lineNumber);
    delete stackNum;
    delete stackCheck;

    return false;
  }
}
//------------

//This checks if the opening and closing bracket being checked is the same
//type. It returns true if it is, and false if otherwise.
bool SyntaxCheck::checkType (char a, char b)
{
  if (a == '(')
  {
    if (b == ')')
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (a == '{')
  {
    if (b == '}')
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (a == '[')
  {
    if (b == ']')
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  return false;
}
//------------


//This returns what the match of the opening brace entered is.
char SyntaxCheck::getMatch(char a)
{
  if (a == '(')
  {
    return ')';
  }
  else if (a == '{')
  {
    return '}';
  }
  else if (a == '[')
  {
    return ']';
  }
  return '\n';
}

//This returns the file string the user entered.
string SyntaxCheck::getUserString()
{
  return userString;
}
