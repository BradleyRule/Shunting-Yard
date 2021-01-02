#include <iostream>
#include <cstring>
#include "queue.h"

using namespace std;

queue::queue(){
  head = NULL;
  tail = NULL;
}

queue::~queue(){
  if(head){
    Node* current = head;
    while (current){
      head = current->getNext();
      delete current;
      current = head;
    }
  }
}

void queue::enqueue(char exp){
  Node* newnode = new Node();
  newnode->setExp(exp);
  if(head == NULL){
    head = newnode;
    tail = newnode;
  }
  else if(head != NULL){
    tail->setNext(newnode);
    tail = newnode;
  }
}

char queue::dequeue(){
  if (!head){
    return 'X';
  }
  char tempchar = head->getExp();
  Node* temp = head->getNext();
  delete head;
  head = temp;
  return tempchar;
}
