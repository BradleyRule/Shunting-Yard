#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node() {
  expression = '\0';
  next = NULL;
}

Node::~Node(){
  next = NULL;
}

void Node::setExp(char exp) {
  expression = exp;
}

char Node::getExp(){
  return expression;
}

void Node::setNext(Node* newnext){
  next = newnext;
}

Node* Node::getNext() {
  return next;
}
