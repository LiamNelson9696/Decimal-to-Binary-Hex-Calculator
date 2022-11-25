#ifndef STACK_CPP
#define STACK_CPP

#include <iostream>
using namespace std;
#include "stack.h"
#include <cstdlib>

Stack::Stack()
{
  topIndex = -1;
}

void Stack::push(el_t e)
{
  if(isFull() == false)
    {
      topIndex++;
      array[topIndex] = e;
    }
  else
    {
       stackError("Overflow");
    }
}

el_t Stack::pop()
{
  el_t temp;
  temp = array[topIndex];
  if(isEmpty() == false)
    {     
      topIndex--;
      return temp;
    }
  else
    {
        stackError("Underflow");
    }
  
  return temp;
}

el_t Stack::topElem() const
{
  return array[topIndex];
}

void Stack::displayAll() const
{
  for(int i = topIndex; i >= 0; i--)
    {
      cout << array[i] << endl;
    }
}

void Stack::clearIt()
{
  topIndex = -1;
}

bool Stack::isEmpty() const
{
  return (topIndex == -1)? true : false;
}

bool Stack::isFull() const
{
  return (topIndex == MAX-1)? true : false;
}

void Stack::stackError(string msg)
{
  cout << msg << endl;
  exit(1);
}

#endif
