#include "tNode.h"
#include <iostream>
#include <cstring>

using namespace std;

tNode::tNode(){
  lChild = NULL;
  rChild = NULL;
  exp = '\0';
}

tNode::~tNode(){
  
  delete lChild;
  lChild = NULL;
  delete rChild;
  rChild = NULL;
}

void tNode::setRChild(tNode* newnode){
  rChild = newnode;
}

void tNode::setLChild(tNode* newnode){
  lChild = newnode;
}

tNode* tNode::getLChild(){
  return lChild;
}

tNode* tNode::getRChild(){
  return rChild;
}

void tNode::setExp(char expression){
  exp = expression;
}

char tNode::getExp(){
  return exp;
}
