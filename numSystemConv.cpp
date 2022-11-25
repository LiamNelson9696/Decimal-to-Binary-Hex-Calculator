#include <iostream>
using namespace std;
#include "stack.cpp"
#include "checkInput.h"

//prototypes
int getBase();
char convertToChar(int n);
void convertRec(int n, int b);
void convertStack(int n, int b);

int main()
{
  int dec; //Stores the number in base 10
  int base; //Stores the base to convert baseNum to

  cout << "Enter a number in base 10: ";
  dec = getData(1, 999999, "Enter a number between 1 and 999999. Enter again: ");
  base = getBase();

  cout << "----------- Using recursion -----------" << endl;
  convertRec(dec, base);
  cout << endl;

  cout << "----------- Using a stack -------------" << endl;
  convertStack(dec, base);
  cout << endl;

  return 0;
}

//This function prompts the user for a base to convert the decimal number into.
//If the base isn't 2, 8, or 16, it tells the user that their base is not valid
//and prompts them to enter another
int getBase()
{
  int base; //stores the base
  bool isValid = false; //keeps track of whether the input is valid, invalid by default

  cout << "Enter a base to convert the base 10 number to: ";
  cin >> base;

  while(isValid == false) //while the number is not a valid base i.e. '3'
    {
      if(base == 2 || base == 8 || base == 16) //if the base is valid (2, 8, or 16)
	{
	  isValid = true; //changes to true so that we can exit the loop
	  return base;
	}
      else //if the base is not valid (not 2, 8, or 16)
	{
	  cout << base << " is invalid. Enter 2, 8, or 16 only: ";
	  cin >> base;
	}
    }
}

//This function converts integers into their char equivalent. It also converts 10-15 to their hexadecimal equivalent
//n = a number in base 10
char convertToChar(int n)
{
  char newChar; //stores the char equivalent of n
  newChar = (char) n%10; //gets the remainder of n/10 and typecasts it as a char for the if statement

  if(n >= 10 && n <= 15) //numbers 10-15 (anything that needs to be converted to a hexadecimal number)
    {
      newChar = newChar + 'A'; //adds the typecasted value to 'A' to get the correct letter for hexadecimal
                               //('0' + 'A' = 'A', '1' + 'A' = 'B', '2' + 'A' = 'C',... etc.)
      return newChar;
    }
  else //numbers 0-9 (everything else)
    {
      newChar = n + '0'; //converts n into a char and stores it in newChar
      return newChar;
    }
}

//This function uses recursion to convert a decimal number to a different number
//and prints it.
//n = a decimal number
//b = a number base which n is converted to (2, 8, or 16)

void convertRec(int n, int b)
{  
  if(n == 0) //if n = 0, we have fully converted the number (base case)
    {
      return;
    }
  else //if n > 0
    {
      convertRec((n/b),b); //we call the function again with the next number and the same base
      cout << convertToChar(n%b); //This prints all of the results in reverse order. It does this because
                                  //it starts calling convertToChar with the number on top of the runtime stack
    }
}

//This function uses a stack to convert a decimal number to a different number
//base and prints it.
//n = a decimal number
//b = a number base which n is converted to (2, 8, or 16)
void convertStack(int n, int b)
{
  Stack s; //creates the stack that we will be pushing the number places into

  while(n != 0) //loop continues until we have fully converted the number (n=0)
    {
      if(s.isFull() == false) //checks in the client to make sure we don't hit overflow
	{
	  s.push(convertToChar(n%b)); //pushes the value into the stack
	  n = n/b; //changes the value for the next iteration
	}
      else //we should never technically hit this (the stack is large enough to handle 2^30) but it's still good to have
	{
	  cout << "Number it too large for conversion." << endl;
	  return;
	}
    }
  
  while(s.isEmpty() == false) //loop continues until we have fully printed all items (the full number) from the stack
    {
      cout << s.pop();
    }
}
