#include <iostream>
#include "Project.hpp"

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
  
}
