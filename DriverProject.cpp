
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
	   for(int k=0; k < 4;k++)
    	{
       		//0 = hearts; 1 = diamonds; 2 = spades; 3 = clubs
		    ll.insertend(i,k);
     	}
    }
	ll.insertend(0,0);
	ll.printListstart();
	Node **playerArray1 = new Node*[10];
	Node **playerArray2 = new Node*[10];
	ll.deal(playerArray1, playerArray2);
}
