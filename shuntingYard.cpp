#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"
#include "node.h"
#include "tNode.h"

using namespace std;

int main(){

  stack stack = new stack();
  queue queue = new queue();
  char input[100];
  int count = 0;
  char temp;

  cout << "Enter an equation with parenthesis around each expression (no spaces)" << endl;

  cin.get(input, 100);
  cin.get();

  while(input[count] != '\0'){
    if (isOperator(input[count])){
      stack.push(input[count]);
    }
    else if (!isOperator(input[count])){
      if(input[count] == '('){
	stack.push(input[count]);
      }
      else if(input[count] == ')'){
	temp = stack.pop();
	while(temp != '('){
	  queue.enqueue(temp);
	  temp = stack.pop();
	}
      }
      else{
	queue.enqueue(input[count]);
      }
    }
  }

  temp = stack.pop();
  while(temp != 'X'){
    queue.enqueue(temp);
    temp = stack.pop();
  }

  tNode* head;
  head = NULL;
  tNode* nodeTemp = head;
  tNode* newnode;
  bool firstTree = 1;
  bool createSub = 0;
  tNode* subHead = NULL;
  
  temp = queue.dequeue();
  while (temp != 'X'){
    
    if(!isOperator(temp)){
      stack.push(temp);
      if(subHead != NULL){
	if(head == NULL){
	  head = subHead;
	}
	else if(head != NULL){
	  subHead->setLChild(head);
	  head = subHead;
	  subHead = NULL;
	}
	
      }
    }
    else if(isOperator(temp)){
      if(subHead == NULL){
	newnode = new tNode();
	newnode->setExp(temp);
	subHead = newnode();
	newnode = new tNode();
	newnode->setExp(stack.pop());
	subHead->setRChild(newnode);
	newnode = new tNode();
	newnode->setExp(stack.pop());
	subHead->setLChild(newnode);
      }
      else if(subHead != NULL){
	nodeTemp = subHead;
	newnode = new tNode();
	newnode->setExp(temp);
	subHead = newnode;
	
      }
	      
    }
    temp = queue.dequeue();
  }

  

  /*
  temp = stack.pop();
  while(temp != 'X'){
    if(isOperator(temp)){
      if (head == NULL){
	head = new tNode();
	head->setExp(temp);
	nodeTemp = head;
      }
      else{
	if(isOperator(tempNode->getLChild()->getExp())){
	  if(nodeTemp->getLChild() == NULL){
	    newnode = new tNode();
	    newnode->setExp(temp);
	    nodeTemp->setLChild(newnode);
	    
	  }
	  else if(nodeTemp->getRChild() == NULL){
	    newnode = new tNode();
	    newnode->setExp(temp);
	    nodeTemp->setRChild(newnode);
	  }
	    
	}
      }
    }
    else{

    }


    temp = stack.pop();
  }
  */




  
  return 0;
}


bool isOperator(char exp){
  if(exp == '+' || exp == '-' || exp == '/' || exp == '*' || exp == '^'){
    return true;
  }
  return false;
  
}
