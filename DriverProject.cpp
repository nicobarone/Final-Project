#include <iostream>
#include "Project.hpp"
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

using namespace std;

int main()
{
  LL ll;

	for(int i=2; i<=14; i++)
  {//creates Initial deck
	   for(int j=0; j < 4;j++)
    	{
       		//0 = hearts; 1 = diamonds; 2 = spades; 3 = clubs
		    ll.insertend(i,j);
     	}
    }
	ll.printListstart();
	

	//Deal
	srand(time(0));  // Initialize random number generator.
    Node **playerArray1 = new Node*[7];
    Node **playerArray2 = new Node*[7];
    Node **comCards = new Node*[5];

    Node* temp = new Node;
    temp = root;
    
    for(int i=0; i<2; i++){
    	r = (rand() % 52) + 1;
    	int j=0;
    	Node* temp = new Node;
    	temp = root;
    	while(temp->next != NULL){
			if(j == r){
    			playerArray1[i] = new Node;
    			playerArray1[i]->value = temp->value;
    			playerArray1[i]->suit = temp->suit;
    			//Now call remove r function from the linked list
    			//delete memory too
    		}
    		temp = temp->next;
    		j++;
    	}
    	r = (rand() % 52) + 1;
    	int j=0;
    	temp = root;
    	while(temp->next != NULL){
			if(j == r){
    			playerArray2[i] = new Node;
    			playerArray2[i]->value = temp->value;
    			playerArray2[i]->suit = temp->suit;
    			//Now call remove r function from the linked list
    			//delete memory too
    		}
    		temp = temp->next;
    		j++;
    	}
    }    
	for(int i=2; i<7; i++){
		r = (rand() % 52) + 1;
    	int j=0;
    	temp = root;
		while(temp->next != NULL){
    		if(j == r){
    			playerArray1[i] = new Node;
    			playerArray1[i]->value = temp->value;
    			playerArray1[i]->suit = temp->suit;
    			playerArray2[i] = new Node;
    			playerArray2[i]->value = temp->value;
    			playerArray2[i]->suit = temp->suit;
    			comCards[i-2] = new Node;
    			comCards[i-2]->value = temp->value;
    			comCards[i-2]->suit = temp->suit;
    			//Now call remove r function from the linked list
    			//delete memory too
    		}
    		temp = temp->next;
    		j++;
  		}
	}  
}
