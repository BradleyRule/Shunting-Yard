#ifndef TNODE
#define TNODE

#include <iostream>
#include <cstring>

using namespace std;

class tNode{
 public:
  tNode();
  ~tNode();
  void setRChild(tNode*);
  void setLChild(tNode*);
  tNode* getLChild();
  tNode* getRChild();
  void setExp(char);
  char getExp();
  
 private:
  tNode* lChild;
  tNode* rchild;
  char exp;
  
}
