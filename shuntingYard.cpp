#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"
#include "node.h"
#include "tNode.h"

using namespace std;


bool isOperator(char);
void printPost(tNode*);
void postWrapper(tNode*);
void printPre(tNode*);
void preWrapper(tNode*);
void printIn(tNode*);
void inWrapper(tNode*);


int main(){

  //create the stack
  stack stack;
  //create the queue
  queue queue;
  //create variable to store input
  char input[100];
  int count = 0;
  char temp;

  //ask the user for the input
  cout << "Enter an equation with parenthesis around each expression (no spaces, single digit numbers)" << endl;

  cin.get(input, 100);
  cin.get();

  //order the input into postfix
  while(input[count] != '\0' && input[count] != '\n'){//go through each character in the input
    if (isOperator(input[count])){//if the character is an operator, push it to the stack
      stack.push(input[count]);
    }
    else if (!isOperator(input[count])){//if the character is an open parenthesis, push it to the stack
      if(input[count] == '('){
	stack.push(input[count]);
      }
      else if(input[count] == ')'){
	//if the character is a closed parenthesis, move operators from stack to queue removing the pair of parenthesis
	temp = stack.pop();
	while(temp != '('){
	  queue.enqueue(temp);
	  temp = stack.pop();
	}
      }
      else{//if it is a number add it to the queue
	queue.enqueue(input[count]);
      }
    }
    //increment count
    count++;
  }

  //move remaining operators from the stack to the queue
  temp = stack.pop();
  while(temp != 'X'){
    queue.enqueue(temp);
    temp = stack.pop();
  }

  //variables and pointers for building a tree
  char Xcheck = '\0';
  tNode* head;
  head = NULL;
  tNode* nodeTemp = head;
  tNode* newnode;
  bool firstTree = 1;
  bool createSub = 0;
  tNode* subHead = NULL;

  //building tree
  //pull the first character out of the queue
  temp = queue.dequeue();
  while (temp != 'X'){
    
    if(!isOperator(temp)){//if the character is a number push it to the stack
      stack.push(temp);
      if(subHead != NULL){//if there is a sub tree
	if(head == NULL){//if there is no main tree
	  //add the sub tree to the main tree
	  head = subHead;
	  subHead = NULL;
	}
	else if(head != NULL){//if there is a main tree
	  //add the sub tree to the main tree (the subHead will always be missing a left child at this point)
	  subHead->setLChild(head);
	  head = subHead;
	  subHead = NULL;
	}
	
      }
    }
    else if(isOperator(temp)){//if the character is an operator, 
      if(subHead == NULL){//if there is no sub tree
	newnode = new tNode();
	newnode->setExp(temp);
	subHead = newnode;
	newnode = new tNode();
	newnode->setExp(stack.pop());
	//cout << "poped: " << newnode->getExp() << endl;
	subHead->setRChild(newnode);
	newnode = new tNode();
	newnode->setExp(stack.pop());
	subHead->setLChild(newnode);
      }
      else if(subHead != NULL){//if a new sub tree has already been created
	//create the new subhead node containing the operator
	nodeTemp = subHead;
	newnode = new tNode();
	newnode->setExp(temp);
	subHead = newnode;
	//connect the new subhead to the rest of the sub tree
	subHead->setRChild(nodeTemp);
	//pull the next number out of the stack
	Xcheck = stack.pop();
        if(Xcheck != 'X'){//if an X was not pulled from the stack (this means there are numbers left)
	  //create a left child and add it to the sub head
	  newnode = new tNode();
	  newnode->setExp(Xcheck);
	  //  cout << "poped: " << newnode->getExp() << endl;
	  subHead->setLChild(newnode);
	}
      }
	      
    }
    //take the next charater out of the queue
    temp = queue.dequeue();
    //cout << "dequeue: " << temp << endl;
  }


  //when there is nothing left in the queue, make sure all the 
  if(subHead != NULL){
    if(head == NULL){
      head = subHead;
      subHead = NULL;
    }
    else if(head != NULL){
      subHead->setLChild(head);
      head = subHead;
      subHead = NULL;
    }
    
  }
  
  //create boolean to check if the program should stop
  bool running = 1;
  
  while (running){//continue until the user quits

    //ask the user for input
    cout << "Enter what form you want to convert your equation (infix, prefix, postfix) or enter quit to stop the program." << endl;

    //clear the input
    for (int i = 0; i < 100; i++){
      input[i] = '\0';
    }

    //get user input
    cin.get(input, 100);
    cin.get();
    
    if (strcmp(input, "postfix") == 0){//if input is "postfix" run the postWrapper
      postWrapper(head);
    }
      
    else if(strcmp(input, "infix") == 0){//if input is "infix" run the inWrapper
      inWrapper(head);
    }
      
    else if(strcmp(input, "prefix") == 0){//if input is "prefix" run the preWrapper
      preWrapper(head);
    }

    else if(strcmp(input, "quit") == 0){//if input is quit, stop the program
      running = 0;
    }
  }
  
  return 0;
}


void printPost(tNode* head){
  if(head){
    //cout << head->getExp(); (prefix)
    printPost(head->getLChild());
    //cout << head->getExp(); (infix)
    printPost(head->getRChild());
    cout << head->getExp();
    return;
  }
  return;
}

void postWrapper(tNode* head){
  printPost(head);
  cout << endl;
  cout << endl;
}

void preWrapper(tNode* head){
  printPre(head);
  cout << endl;
  cout << endl;
}

void printPre(tNode* head){
  if(head){
    cout << head->getExp();
    printPre(head->getLChild());
    //cout << head->getExp(); (infix)
    printPre(head->getRChild());
    //cout << head->getExp();
    return;
  }
  return;
}

void inWrapper(tNode* head){
  printIn(head);
  cout << endl;
  cout << endl;
}

void printIn(tNode* head){
  if(head){
    //cout << head->getExp(); (prefix)
    printIn(head->getLChild());
    cout << head->getExp();
    printIn(head->getRChild());
    //cout << head->getExp();
    return;
  }
  return;
}

bool isOperator(char exp){
  if(exp == '+' || exp == '-' || exp == '/' || exp == '*' || exp == '^'){
    return true;
  }
  return false;
  
}
