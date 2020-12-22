#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

stack::stack(){
  head = NULL;
}

stack::~stack(){
  if(head){
    Node* current = head;
    while (current){
      head = current->getNext();
      delete current;
      current = head;
    }
  }
}

void stack::push(char exp){
  Node* newnode = new Node();
  Node* temp = head;
  newnode->setExp(exp);
  head = newnode;
  newnode->setNext(temp);
}

char stack::peak(){
  if(head == NULL){
    return 'X';
  }
  return head->getExp();
}

char stack::pop(){
  if(head == NULL){
    return 'X';
  }
  char tempchar = head->getExp();
  Node* temp = head->getNext();
  delete head;
  head = temp;
  return tempchar;
}
