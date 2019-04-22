
#include <iostream>
#include "Project.hpp"
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

using namespace std;

int main()
{
  cout<<" ------Welcome to Heads up Poker ------"<<endl;
  cout<<endl;
  cout<<" Each player will start with 500 chips "<<endl;
  bool turnend = 1;
  int chips1 = 500;
  int chips2 = 500;

  while(turnend == 1)
  {
    LL ll;
    int pot = 0;

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
    cout<<" New turn "<<endl;

    cout<<" Each player enter 10 chips into the pot "<<endl;
    getchar();
    chips1 = chips1 - 10;
    chips2 = chips2 - 10;
    bool run = true;
    int v = 0;
    int t = 0;
    int r;
    while(run)
    {
      char choice;

      cout<<" Player 1 its your turn choose what you would like to do"<<endl;
      cout<<" Player 1 has "<< chips1<< " chips"<<endl;
      cout<<" 1. Look at cards"<<endl;
      cout<<" 2. Make a bet"<<endl;
      cout<<" 3. Check"<<endl;
      cin >> choice;

      switch (choice)
      {
        case '1':
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<< playerArray1[0]->value << " "<< playerArray1[0]->suit;
          cout<<"  and  ";
          cout<< playerArray1[1]->value << " "<< playerArray1[1]->suit;
          cout<<endl;
          cout<< " Enter 1 to continue "<<endl;
          cin >> r;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          break;
        case '2':
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

          cout<<" Enter the amount you would like to bet "<<endl;
          cin >> v;
          chips1 = chips1 - v;
          pot = pot + v;
          run = false;
          break;
        case '3':
          run = false;
          break;

        default:
          break;
      }
    }


      run = true;
      while(run)
      {
        char choice;
        cout<<" Player 2 its your turn choose what you would like to do"<<endl;
        cout<<" Player 1 made a bet of "<<v<<" chips";
        cout<<" Player 2 has "<< chips2<< " chips"<<endl;
        cout<<" 1. Look at cards"<<endl;
        cout<<" 2. Call"<<endl;
        cout<<" 3. Raise"<<endl;
        cout<<" 4. Fold"<<endl;
        cin >> choice;
        switch (choice)
        {
          case '1':
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<< playerArray2[0]->value << " "<< playerArray2[0]->suit;
            cout<<"  and  ";
            cout<< playerArray2[1]->value << " "<< playerArray2[1]->suit;
            cout<<endl;
            cout<< " Enter 1 to continue "<<endl;
            cin >> r;
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            break;
          case '2':
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

            cout<<" Player 2 calls"<<endl;
            chips2 = chips2 - v;
            pot = pot + v;
            run = false;
            break;
          case '3':
            cout<<" Enter the amount you would like to bet "<<endl;
            cin >> v;
            chips2 = chips2 - v;
            pot = pot + v;

            cout<< " Player 1 would you like to call? (1 = yes / 2 = no)"<<endl;
            cin >> t;
            if( t == 1){
              chips1 = chips1 - 1;
              pot = pot + v;
            }
            else
            {
              chips2 = chips2 + pot;
              turnend = 0;
            }
            run = false;

            break;
          case '4':
            cout<<" Player 2 decided to fold "<<endl;
            chips1 = chips1 + pot;
            turnend = 0;
            run = false;
          default:
            break;
        }
      }

  }
}
