#ifndef STACK
#define STACK

#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

class stack{
public:
  stack();
  ~stack();
  void push(char);
  char peak();
  char pop();
  
private:
  Node* head;
};
#endif
