#ifndef NODE
#define NODE

#include <iostream>
#include <cstring>

using namespace std;

class Node{
 public:
  Node();
  ~Node();
  void setExp(char);
  char getExp();
  void setNext(Node*);
  Node* getNext();
 private:
  Node* next;
  char expression;
};
#endif
