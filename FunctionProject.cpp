#include <iostream>
#include "Project.hpp"

using namespace std;

void LL::insertend(int v, int s){
  //1. ALLOCATE NODE
  Node* newNode = new Node;

  //2. PUT IN THE DATA
  newNode->value = v;
  newNode->suit = s;

  //3. Make next of newNode as NULL
  newNode->next = NULL;

  //4. Check if head is not Null
  if(head == NULL){
    head = newNode;
    return;
  }

  //4. Traverse the LinkedList till end
  Node* temp = head;

  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
  return;
}

void LL::printListstart(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->value <<" "<< temp->suit<<" -> ";
    temp = temp->next;
  }

  cout<<temp->value<<endl;
}

/*void LL::createcards();
{
  for(int i=2; i<=14; i++)
  {//creates Initial deck
	   for(int j=0; j < 4;j++)
     {
       //0 = hearts; 1 = diamonds; 2 = spades; 3 = clubs
		   insertend(i,j);
     }
   }
}*/
