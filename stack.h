#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;
int const MAX = 30;

typedef char el_t;

class Stack
{
  
 private:
  int topIndex;
  el_t array[MAX];
  void stackError(string msg);

 public:
  Stack();
  void push(el_t e);
  el_t pop();
  el_t topElem() const;
  void displayAll() const;
  void clearIt();
  bool isEmpty() const;
  bool isFull() const;
  

};


#endif
