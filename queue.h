#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

class queue{
 public:
  queue();
  ~queue();
  void enqueue(char);
  char dequeue();
 private:
  Node* head;
  Node* tail;
}
