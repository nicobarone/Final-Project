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


  while(turnend == 1)//turn if player 1 started
  {
    LL ll;
    int pot = 0;
    int fold = 0;

    for(int i=2; i<=14; i++)
    {//creates Initial deck
      for(int k=0; k < 4;k++)
      {
          //0 = hearts; 1 = diamonds; 2 = spades; 3 = clubs
         ll.insertend(i,k);
      }
    }
    ll.insertend(0,0);
    //ll.printListstart();
    Node **playerArray1 = new Node*[10];
    Node **playerArray2 = new Node*[10];
    Node **communityCards = new Node*[5];
    Node **firsttwo1 = new Node*[2];
    Node **firsttwo2 = new Node*[2];
    ll.deal(playerArray1, playerArray2, communityCards, firsttwo1, firsttwo2);

    cout<<endl<<endl;
    cout<<" New Hand  "<<endl;
    cout<<" Each player enter 10 chips into the pot "<<endl;

    chips1 = chips1 - 10;
    chips2 = chips2 - 10;
    pot = pot + 20;
    bool run = true;
    int v = 0;
    int t = 0;
    int x = 0;
    int r;
    while(run)//first action
    {
      char choice;
      cout<<"----------------------------------------------------------------------------------"<<endl;//Player1 turn
      cout<<" Player 1 its your turn choose what you would like to do."<<endl;
      cout<<" Player 1 has "<< chips1<< " chips"<<endl;
      cout<<" 1. Look at cards"<<endl;
      cout<<" 2. Make a bet"<<endl;
      cout<<" 3. Check"<<endl;
      cin >> choice;

      switch (choice)
      {
        case '1':
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          ll.printHand(firsttwo1);
          cout<< " Enter 1 to continue "<<endl;
          cin >> r;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          break;
        case '2':
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          v=0;
          while(v > chips1 || v==0){
            cout<<" You have "<<chips1<<" chips"<<endl;
            cout<<" Enter the amount you would like to bet "<<endl;
            cin >> v;
          }
          chips1 = chips1 - v;
          pot = pot + v;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
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
    while(run)//player 2 turn 1
    {
      char choice;
      cout<<"----------------------------------------------------------------------------------"<<endl;
      cout<<" Player 2 its your turn choose what you would like to do."<<endl;
      cout<<" Player 1 made a bet of "<<v<<" chips and has "<<chips1<<" chips.";
      cout<<" The pot is now "<<pot<<" "<<endl<<endl;

      cout<<" Player 2 you have "<<chips2<<endl<<endl;
      cout<<" 1. Look at cards"<<endl;
      cout<<" 2. Call"<<endl;
      cout<<" 3. Raise"<<endl;
      cout<<" 4. Fold"<<endl;
      cin >> choice;
      switch (choice)
      {
        case '1'://Look at cards
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          ll.printHand(firsttwo2);
          cout<<endl;
          cout<< " Enter 1 to continue "<<endl;
          cin >> r;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          break;
        case '2'://player 2 is calling first players bet
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          if(chips2 <= v && chips2 != 0){
            chips1 = chips1 + (v - chips2);
            pot = pot + chips2;
            pot = pot - (v - chips2);
            chips2 = 0;
            cout<<" Player 1 has "<<chips1<<endl;
            cout<<" Player 2 is ALL INN!!!"<<endl;
            cout<<" Pot is "<<pot<<endl;
            fold = 3;
            run = false;
            break;
          }
          else if(chips2 == 0){
            cout<<" Player 2 is already out of Chips"<<endl;
            fold = 3;
            run = false;
            break;
          }
          else{
            cout<<" Player 2 calls"<<endl;
            chips2 = chips2 - v;
            pot = pot + v;
            run = false;
            break;
          }
        case '3'://Raise
          if(chips2 <= v && chips2 != 0){
            pot = pot + chips2;
            chips2 = 0;
            cout<<" Player 2 is ALL INN!!!"<<endl;
            cout<<" Pot is "<<pot;
            fold = 3;
            run = false;
            break;
          }
          cout<<" Enter the amount you would like to raise "<<endl;
          chips2 = chips2 - v;
          pot = pot + v;
          v=0;
          cout<<" You have "<<chips2<<endl;
          while(v > chips1 || v==0){
            cin >> v;
          }
          chips2 = chips2 - v;
          pot = pot + v;
          cout<<"----------------------------------------------------------------------------------"<<endl;
          cout<<" Player 1 would you like to call, fold, or reraise?"<<endl;
          cout<<" Pot is now "<<pot<<" and it's "<<v<<" chips to call"<<endl;
          cout<<" 1. Call"<<endl;
          cout<<" 2. ReRaise"<<endl;
          cout<<" 3. Fold"<<endl;
          cin >> t;
          if(t == 1){
            if(chips1 <= v && chips1 != 0){
              pot = pot + chips1;
              chips1 = 0;
              cout<<" Player 1 is ALL INN!!!"<<endl;
              cout<<" Pot is "<<pot;
              fold = 3;
              run = false;
              break;
            }
            else{
              cout << "Player 1 calls "<<endl;
              pot = pot + v;
              chips1 = chips1 - v;
              cout<< " Pot is "<<pot<<endl;
              run = false;
              break;
            }
          }
          else if(t == 2){
            chips1 = chips1 - v;
            pot = pot + v;
            v=0;
            while(v > chips1 || v==0){
              cout<<" You have "<<chips1<<" chips"<<endl;
              cout<<" Enter the amount you would like to bet "<<endl;
              cin >> v;
            }
            chips1 = chips1 - v;
            pot = pot + v;
            cout<<endl<<endl;
            cout<<"----------------------------------------------------------------------------------"<<endl;
            cout<<" Player 2 would you like to call, fold?"<<endl;
            cout<<" 1. Call"<<endl;
            cout<<" 2. Fold"<<endl;
            cin >> x;
            if(x==1){
              if(chips2 <= v && chips2 != 0){
                chips1 = chips1 + (v - chips2);
                pot = pot + chips2;
                pot = pot - (v - chips2);
                chips2 = 0;
                cout<<" Player 1 has "<<chips1<<endl;
                cout<<" Player 2 is ALL INN!!!"<<endl;
                cout<<" Pot is "<<pot<<endl;
                fold = 3;
                run = false;
                break;
              }
              else if(chips2 == 0){
                cout<<" Player 2 is already out of Chips"<<endl;
                fold = 3;
                run = false;
                break;
              }
              else{
                cout<<" Player 2 calls"<<endl;
                chips2 = chips2 - v;
                pot = pot + v;
                run = false;
                break;
              }
            }
            else{
              cout<<" Player 2 decided to fold "<<endl;
              chips1 = chips1 + pot;
              fold = 2;
              run = false;
              break;
            }
          }
          else if(t == 3){
            cout<<" Player 1 decided to fold "<<endl;
            chips2 = chips2 + pot;
            fold = 1;
            run = false;
            break;
          }

          run = false;
          break;
        case '4':
          cout<<" Player 2 decided to fold "<<endl;
          fold = 2;
          chips1 = chips1 + pot;
          run = false;
        default:
        break;
      }
    }
    
    if(fold == 0){
      run = true;
      cout<<"----------------------------------------------------------------------------------"<<endl;
      cout<<" The River:"<<endl;
      ll.printCommunity(communityCards, 0);
      ll.printCommunity(communityCards, 1);
      ll.printCommunity(communityCards, 2);

      cout<<endl;
      cout<<"Player 1's Chips: "<<chips1<<endl;
      cout<<"Player 2's Chips: "<<chips2<<endl;
    }
    else{
      run = false;
    }

    v = 0;
    t = 0;
    x = 0;
    r;
    while(run)//first action
    {
      char choice;
      cout<<"----------------------------------------------------------------------------------"<<endl;//Player1 turn
      cout<<" Player 1 its your turn choose what you would like to do."<<endl;
      cout<<" Player 1 has "<< chips1<< " chips"<<endl;
      cout<<" 1. Look at cards"<<endl;
      cout<<" 2. Make a bet"<<endl;
      cout<<" 3. Check"<<endl;
      cin >> choice;

      switch (choice)
      {
        case '1':
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<" Community Cards"<<endl;
          cout<<endl<<endl;
          ll.printCommunity(communityCards, 0);
          ll.printCommunity(communityCards, 1);
          ll.printCommunity(communityCards, 2);
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          ll.printHand(firsttwo1);
          cout<< " Enter 1 to continue "<<endl;
          cin >> r;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          break;
        case '2':
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          v=0;
          while(v > chips1 || v==0){
            cout<<" You have "<<chips1<<" chips"<<endl;
            cout<<" Enter the amount you would like to bet "<<endl;
            cin >> v;
          }
          chips1 = chips1 - v;
          pot = pot + v;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          run = false;
          break;
        case '3':
          run = false;
          break;

        default:
          break;
      }
    }


    if(fold == 0){
      run = true;
    }
    else{
      run = false;
    }
    while(run)//player 2 turn 1
    {
      char choice;
      cout<<"----------------------------------------------------------------------------------"<<endl;
      cout<<" Player 2 its your turn choose what you would like to do."<<endl;
      cout<<" Player 1 made a bet of "<<v<<" chips and has "<<chips1<<" chips.";
      cout<<" The pot is now "<<pot<<" "<<endl<<endl;

      cout<<" Player 2 you have "<<chips2<<endl<<endl;
      cout<<" 1. Look at cards"<<endl;
      cout<<" 2. Call"<<endl;
      cout<<" 3. Raise"<<endl;
      cout<<" 4. Fold"<<endl;
      cin >> choice;
      switch (choice)
      {
        case '1'://Look at cards
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<" Community Cards"<<endl;
          cout<<endl<<endl;
          ll.printCommunity(communityCards, 0);
          ll.printCommunity(communityCards, 1);
          ll.printCommunity(communityCards, 2);
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          ll.printHand(firsttwo2);
          cout<<endl;
          cout<< " Enter 1 to continue "<<endl;
          cin >> r;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          break;
        case '2'://player 2 is calling first players bet
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          if(chips2 <= v && chips2 != 0){
            chips1 = chips1 + (v - chips2);
            pot = pot + chips2;
            pot = pot - (v - chips2);
            chips2 = 0;
            cout<<" Player 1 has "<<chips1<<endl;
            cout<<" Player 2 is ALL INN!!!"<<endl;
            cout<<" Pot is "<<pot<<endl;
            fold = 3;
            run = false;
            break;
          }
          else if(chips2 == 0){
            cout<<" Player 2 is already out of Chips"<<endl;
            run = false;
            fold = 3;
            break;
          }
          else{
            cout<<" Player 2 calls"<<endl;
            chips2 = chips2 - v;
            pot = pot + v;
            run = false;
            break;
          }
        case '3'://Raise
          if(chips2 <= v && chips2 != 0){
            pot = pot + chips2;
            chips2 = 0;
            cout<<" Player 2 is ALL INN!!!"<<endl;
            cout<<" Pot is "<<pot;
            fold = 3;
            run = false;
            break;
          }
          cout<<" Enter the amount you would like to raise "<<endl;
          chips2 = chips2 - v;
          pot = pot + v;
          v=0;
          cout<<" You have "<<chips2<<endl;
          while(v > chips1 || v==0){
            cin >> v;
          }
          chips2 = chips2 - v;
          pot = pot + v;
          cout<<"----------------------------------------------------------------------------------"<<endl;
          cout<<" Player 1 would you like to call, fold, or reraise?"<<endl;
          cout<<" Pot is now "<<pot<<" and it's "<<v<<" chips to call"<<endl;
          cout<<" 1. Call"<<endl;
          cout<<" 2. ReRaise"<<endl;
          cout<<" 3. Fold"<<endl;
          cin >> t;
          if(t == 1){
            if(chips1 <= v && chips1 != 0){
              pot = pot + chips1;
              chips1 = 0;
              cout<<" Player 1 is ALL INN!!!"<<endl;
              cout<<" Pot is "<<pot;
              fold = 3;
              run = false;
              break;
            }
            else{
              cout << "Player 1 calls "<<endl;
              pot = pot + v;
              chips1 = chips1 - v;
              cout<< " Pot is "<<pot<<endl;
              run = false;
              break;
            }
          }
          else if(t == 2){
            chips1 = chips1 - v;
            pot = pot + v;
            v=0;
            while(v > chips1 || v==0){
              cout<<" You have "<<chips1<<" chips"<<endl;
              cout<<" Enter the amount you would like to bet "<<endl;
              cin >> v;
            }
            chips1 = chips1 - v;
            pot = pot + v;
            cout<<endl<<endl;
            cout<<"----------------------------------------------------------------------------------"<<endl;
            cout<<" Player 2 would you like to call, fold?"<<endl;
            cout<<" 1. Call"<<endl;
            cout<<" 2. Fold"<<endl;
            cin >> x;
            if(x==1){
              if(chips2 <= v && chips2 != 0){
                chips1 = chips1 + (v - chips2);
                pot = pot + chips2;
                pot = pot - (v - chips2);
                chips2 = 0;
                cout<<" Player 1 has "<<chips1<<endl;
                cout<<" Player 2 is ALL INN!!!"<<endl;
                cout<<" Pot is "<<pot<<endl;
                fold = 3;
                run = false;
                break;
              }
              else if(chips2 == 0){
                cout<<" Player 2 is already out of Chips"<<endl;
                fold = 3;
                run = false;
                break;
              }
              else{
                cout<<" Player 2 calls"<<endl;
                chips2 = chips2 - v;
                pot = pot + v;
                run = false;
                break;
              }
            }
            else{
              cout<<" Player 2 decided to fold "<<endl;
              chips1 = chips1 + pot;
              fold = 2;
              run = false;
              break;
            }
          }
          else if(t == 3){
            cout<<" Player 1 decided to fold "<<endl;
            chips2 = chips2 + pot;
            fold = 1;
            run = false;
            break;
          }

          run = false;
          break;
        case '4':
          cout<<" Player 2 decided to fold "<<endl;
          chips1 = chips1 + pot;
          fold = 2;
          run = false;
        default:
        break;
      }
    }


    if(fold == 0){
      run = true;
      ll.printCommunity(communityCards, 0);
      ll.printCommunity(communityCards, 1);
      ll.printCommunity(communityCards, 2);
      ll.printCommunity(communityCards, 3);

      cout<<endl;
      cout<<"Player 1's Chips: "<<chips1<<endl;
      cout<<"Player 2's Chips: "<<chips2<<endl;
    }
    else{
      run = false;
    }
    v = 0;
    t = 0;
    x = 0;
    r;
    while(run)//first action
    {
      char choice;
      cout<<"----------------------------------------------------------------------------------"<<endl;//Player1 turn
      cout<<" Player 1 its your turn choose what you would like to do."<<endl;
      cout<<" Player 1 has "<< chips1<< " chips"<<endl;
      cout<<" 1. Look at cards"<<endl;
      cout<<" 2. Make a bet"<<endl;
      cout<<" 3. Check"<<endl;
      cin >> choice;

      switch (choice)
      {
        case '1':
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<" Community Cards"<<endl;
          cout<<endl<<endl;
          ll.printCommunity(communityCards, 0);
          ll.printCommunity(communityCards, 1);
          ll.printCommunity(communityCards, 2);
          ll.printCommunity(communityCards, 3);
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          ll.printHand(firsttwo1);
          cout<< " Enter 1 to continue "<<endl;
          cin >> r;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          break;
        case '2':
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          v=0;
          while(v > chips1 || v==0){
            cout<<" You have "<<chips1<<" chips"<<endl;
            cout<<" Enter the amount you would like to bet "<<endl;
            cin >> v;
          }
          chips1 = chips1 - v;
          pot = pot + v;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          run = false;
          break;
        case '3':
          run = false;
          break;

        default:
          break;
      }
    }


    if(fold == 0){
      run = true;
    }
    else{
      run = false;
    }
    while(run)//player 2 turn 1
    {
      char choice;
      cout<<"----------------------------------------------------------------------------------"<<endl;
      cout<<" Player 2 its your turn choose what you would like to do."<<endl;
      cout<<" Player 1 made a bet of "<<v<<" chips and has "<<chips1<<" chips.";
      cout<<" The pot is now "<<pot<<" "<<endl<<endl;

      cout<<" Player 2 you have "<<chips2<<endl<<endl;
      cout<<" 1. Look at cards"<<endl;
      cout<<" 2. Call"<<endl;
      cout<<" 3. Raise"<<endl;
      cout<<" 4. Fold"<<endl;
      cin >> choice;
      switch (choice)
      {
        case '1'://Look at cards
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<" Community Cards"<<endl;
          cout<<endl<<endl;
          ll.printCommunity(communityCards, 0);
          ll.printCommunity(communityCards, 1);
          ll.printCommunity(communityCards, 2);
          ll.printCommunity(communityCards, 3);
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          ll.printHand(firsttwo2);
          cout<<endl;
          cout<< " Enter 1 to continue "<<endl;
          cin >> r;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          break;
        case '2'://player 2 is calling first players bet
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          if(chips2 <= v && chips2 != 0){
            chips1 = chips1 + (v - chips2);
            pot = pot + chips2;
            pot = pot - (v - chips2);
            chips2 = 0;
            cout<<" Player 1 has "<<chips1<<endl;
            cout<<" Player 2 is ALL INN!!!"<<endl;
            cout<<" Pot is "<<pot<<endl;
            fold = 3;
            run = false;
            break;
          }
          else if(chips2 == 0){
            cout<<" Player 2 is already out of Chips"<<endl;
            fold = 3;
            run = false;
            break;
          }
          else{
            cout<<" Player 2 calls"<<endl;
            chips2 = chips2 - v;
            pot = pot + v;
            run = false;
            break;
          }
        case '3'://Raise
          if(chips2 <= v && chips2 != 0){
            pot = pot + chips2;
            chips2 = 0;
            cout<<" Player 2 is ALL INN!!!"<<endl;
            cout<<" Pot is "<<pot;
            fold = 3;
            run = false;
            break;
          }
          cout<<" Enter the amount you would like to raise "<<endl;
          chips2 = chips2 - v;
          pot = pot + v;
          v=0;
          cout<<" You have "<<chips2<<endl;
          while(v > chips1 || v==0){
            cin >> v;
          }
          chips2 = chips2 - v;
          pot = pot + v;
          cout<<"----------------------------------------------------------------------------------"<<endl;
          cout<<" Player 1 would you like to call, fold, or reraise?"<<endl;
          cout<<" Pot is now "<<pot<<" and it's "<<v<<" chips to call"<<endl;
          cout<<" 1. Call"<<endl;
          cout<<" 2. ReRaise"<<endl;
          cout<<" 3. Fold"<<endl;
          cin >> t;
          if(t == 1){
            if(chips1 <= v && chips1 != 0){
              pot = pot + chips1;
              chips1 = 0;
              cout<<" Player 1 is ALL INN!!!"<<endl;
              cout<<" Pot is "<<pot;
              fold = 3;
              run = false;
              break;
            }
            else{
              cout << "Player 1 calls "<<endl;
              pot = pot + v;
              chips1 = chips1 - v;
              cout<< " Pot is "<<pot<<endl;
              run = false;
              break;
            }
          }
          else if(t == 2){
            chips1 = chips1 - v;
            pot = pot + v;
            v=0;
            while(v > chips1 || v==0){
              cout<<" You have "<<chips1<<" chips"<<endl;
              cout<<" Enter the amount you would like to bet "<<endl;
              cin >> v;
            }
            chips1 = chips1 - v;
            pot = pot + v;
            cout<<endl<<endl;
            cout<<"----------------------------------------------------------------------------------"<<endl;
            cout<<" Player 2 would you like to call, fold?"<<endl;
            cout<<" 1. Call"<<endl;
            cout<<" 2. Fold"<<endl;
            cin >> x;
            if(x==1){
              if(chips2 <= v && chips2 != 0){
                chips1 = chips1 + (v - chips2);
                pot = pot + chips2;
                pot = pot - (v - chips2);
                chips2 = 0;
                cout<<" Player 1 has "<<chips1<<endl;
                cout<<" Player 2 is ALL INN!!!"<<endl;
                cout<<" Pot is "<<pot<<endl;
                fold = 3;
                run = false;
                break;
              }
              else if(chips2 == 0){
                cout<<" Player 2 is already out of Chips"<<endl;
                fold = 3;
                run = false;
                break;
              }
              else{
                cout<<" Player 2 calls"<<endl;
                chips2 = chips2 - v;
                pot = pot + v;
                run = false;
                break;
              }
            }
            else{
              cout<<" Player 2 decided to fold "<<endl;
              chips1 = chips1 + pot;
              fold = 2;
              run = false;
              break;
            }
          }
          else if(t == 3){
            cout<<" Player 1 decided to fold "<<endl;
            chips2 = chips2 + pot;
            fold = 1;
            run = false;
            break;
          }

          run = false;
          break;
        case '4':
          cout<<" Player 2 decided to fold "<<endl;
          chips1 = chips1 + pot;
          fold = 2;
          run = false;
        default:
        break;
      }
    }

    if(fold == 0){
      run = true;
      ll.printCommunity(communityCards, 0);
      ll.printCommunity(communityCards, 1);
      ll.printCommunity(communityCards, 2);
      ll.printCommunity(communityCards, 3);
      ll.printCommunity(communityCards, 4);
      cout<<endl;
      cout<<"Player 1's Chips: "<<chips1<<endl;
      cout<<"Player 2's Chips: "<<chips2<<endl;
    }
    else{
      run = false;
    }

    v = 0;
    t = 0;
    x = 0;
    r;
    while(run)//first action
    {
      char choice;
      cout<<"----------------------------------------------------------------------------------"<<endl;//Player1 turn
      cout<<" Player 1 its your turn choose what you would like to do."<<endl;
      cout<<" Player 1 has "<< chips1<< " chips"<<endl;
      cout<<" 1. Look at cards"<<endl;
      cout<<" 2. Make a bet"<<endl;
      cout<<" 3. Check"<<endl;
      cin >> choice;

      switch (choice)
      {
        case '1':
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<" Community Cards "<<endl;
          cout<<endl<<endl;
          ll.printCommunity(communityCards, 0);
          ll.printCommunity(communityCards, 1);
          ll.printCommunity(communityCards, 2);
          ll.printCommunity(communityCards, 3);
          ll.printCommunity(communityCards, 4);
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          ll.printHand(firsttwo1);
          cout<< " Enter 1 to continue "<<endl;
          cin >> r;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          break;
        case '2':
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          v=0;
          while(v > chips1 || v==0){
            cout<<" You have "<<chips1<<" chips"<<endl;
            cout<<" Enter the amount you would like to bet "<<endl;
            cin >> v;
          }
          chips1 = chips1 - v;
          pot = pot + v;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          run = false;
          break;
        case '3':
          run = false;
          break;

        default:
          break;
      }
    }


    if(fold == 0){
      run = true;
    }
    else{
      run = false;
    }
    while(run)//player 2 turn 1
    {
      char choice;
      cout<<"----------------------------------------------------------------------------------"<<endl;
      cout<<" Player 2 its your turn choose what you would like to do."<<endl;
      cout<<" Player 1 made a bet of "<<v<<" chips and has "<<chips1<<" chips.";
      cout<<" The pot is now "<<pot<<" "<<endl<<endl;

      cout<<" Player 2 you have "<<chips2<<endl<<endl;
      cout<<" 1. Look at cards"<<endl;
      cout<<" 2. Call"<<endl;
      cout<<" 3. Raise"<<endl;
      cout<<" 4. Fold"<<endl;
      cin >> choice;
      switch (choice)
      {
        case '1'://Look at cards
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<" Community Cards"<<endl;
          cout<<endl<<endl;
          ll.printCommunity(communityCards, 0);
          ll.printCommunity(communityCards, 1);
          ll.printCommunity(communityCards, 2);
          ll.printCommunity(communityCards, 3);
          ll.printCommunity(communityCards, 4);
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          ll.printHand(firsttwo2);
          cout<<endl;
          cout<< " Enter 1 to continue "<<endl;
          cin >> r;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          break;
        case '2'://player 2 is calling first players bet
          cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
          if(chips2 <= v && chips2 != 0){
            chips1 = chips1 + (v - chips2);
            pot = pot + chips2;
            pot = pot - (v - chips2);
            chips2 = 0;
            cout<<" Player 1 has "<<chips1<<endl;
            cout<<" Player 2 is ALL INN!!!"<<endl;
            cout<<" Pot is "<<pot<<endl;
            fold = 3;
            run = false;
            break;
          }
          else if(chips2 == 0){
            cout<<" Player 2 is already out of Chips"<<endl;
            fold = 3;
            run = false;
            break;
          }
          else{
            cout<<" Player 2 calls"<<endl;
            chips2 = chips2 - v;
            pot = pot + v;
            run = false;
            break;
          }
        case '3'://Raise
          if(chips2 <= v && chips2 != 0){
            pot = pot + chips2;
            chips2 = 0;
            cout<<" Player 2 is ALL INN!!!"<<endl;
            cout<<" Pot is "<<pot;
            fold = 3;
            run = false;
            break;
          }
          cout<<" Enter the amount you would like to raise "<<endl;
          chips2 = chips2 - v;
          pot = pot + v;
          v=0;
          cout<<" You have "<<chips2<<endl;
          while(v > chips1 || v==0){
            cin >> v;
          }
          chips2 = chips2 - v;
          pot = pot + v;
          cout<<"----------------------------------------------------------------------------------"<<endl;
          cout<<" Player 1 would you like to call, fold, or reraise?"<<endl;
          cout<<" Pot is now "<<pot<<" and it's "<<v<<" chips to call"<<endl;
          cout<<" 1. Call"<<endl;
          cout<<" 2. ReRaise"<<endl;
          cout<<" 3. Fold"<<endl;
          cin >> t;
          if(t == 1){
            if(chips1 <= v && chips1 != 0){
              pot = pot + chips1;
              chips1 = 0;
              cout<<" Player 1 is ALL INN!!!"<<endl;
              cout<<" Pot is "<<pot;
              fold = 3;
              run = false;
              break;
            }
            else{
              cout << "Player 1 calls "<<endl;
              pot = pot + v;
              chips1 = chips1 - v;
              cout<< " Pot is "<<pot<<endl;
              run = false;
              break;
            }
          }
          else if(t == 2){
            chips1 = chips1 - v;
            pot = pot + v;
            v=0;
            while(v > chips1 || v==0){
              cout<<" You have "<<chips1<<" chips"<<endl;
              cout<<" Enter the amount you would like to bet "<<endl;
              cin >> v;
            }
            chips1 = chips1 - v;
            pot = pot + v;
            cout<<endl<<endl;
            cout<<"----------------------------------------------------------------------------------"<<endl;
            cout<<" Player 2 would you like to call, fold?"<<endl;
            cout<<" 1. Call"<<endl;
            cout<<" 2. Fold"<<endl;
            cin >> x;
            if(x==1){
              if(chips2 <= v && chips2 != 0){
                chips1 = chips1 + (v - chips2);
                pot = pot + chips2;
                pot = pot - (v - chips2);
                chips2 = 0;
                cout<<" Player 1 has "<<chips1<<endl;
                cout<<" Player 2 is ALL INN!!!"<<endl;
                cout<<" Pot is "<<pot<<endl;
                fold = 3;
                run = false;
                break;
              }
              else if(chips2 == 0){
                cout<<" Player 2 is already out of Chips"<<endl;
                fold = 3;
                run = false;
                break;
              }
              else{
                cout<<" Player 2 calls"<<endl;
                chips2 = chips2 - v;
                pot = pot + v;
                run = false;
                break;
              }
            }
            else{
              cout<<" Player 2 decided to fold "<<endl;
              chips1 = chips1 + pot;
              fold = 2;
              run = false;
              break;
            }
          }
          else if(t == 3){
            cout<<" Player 1 decided to fold "<<endl;
            chips2 = chips2 + pot;
            fold = 1;
            run = false;
            break;
          }

          run = false;
          break;
        case '4':
          cout<<" Player 2 decided to fold "<<endl;
          chips1 = chips1 + pot;
          fold = 2;
          run = false;
        default:
        break;
      }
    }
    if(fold == 1)
    {
      cout<< "Player 1 folded"<<endl;
      cout<<" Player 2 gets "<<pot<<" chips"<<endl;

    }
    else if (fold == 2)
    {
      cout<< "Player 2 folded"<<endl;
      cout<<" Player 1 gets "<<pot<<" chips"<<endl;

    }
    else
    {
      cout<<endl<<endl<<endl<<endl<<endl<<endl;
      cout<<" Showdown!!"<<endl;
      cout<<endl<<endl<<endl<<endl<<endl<<endl;
      cout<<" Community Cards"<<endl;
      cout<<endl<<endl;
      ll.printCommunity(communityCards, 0);
      ll.printCommunity(communityCards, 1);
      ll.printCommunity(communityCards, 2);
      ll.printCommunity(communityCards, 3);
      ll.printCommunity(communityCards, 4);
      cout<<endl<<endl<<endl;
      cout<<" Player 1's Hand"<<endl;
      cout<<endl<<endl;
      ll.printHand(firsttwo1);
      cout<<endl<<endl;
      cout<<" Player 2's Hand"<<endl;
      cout<<endl<<endl;
      ll.printHand(firsttwo2);
      cout<<endl;
      if (playerArray1[7]->value == 100)
      {
        cout<<" Player 1 wins! "<<endl;
        cout<<" Player 1 gets "<<pot<<" chips"<<endl;
        chips1 = chips1 + pot;
      }
      else if (playerArray2[7]->value == 100)
      {
        cout<<" Player 2 wins! "<<endl;
        cout<<" Player 2 gets "<<pot<<" chips"<<endl;
        chips2 = chips2 + pot;
      }
      else
      {
        cout<<" It's a tie! Split pot "<<endl;
        int tie = 0;
        tie = pot / 2;
        chips1 = chips1 + tie;
        chips2 = chips2 + tie;
      }
    }
    int turn = 0;
    cout<<endl;
    cout<<"Player 1's Chips: "<<chips1<<endl;
    cout<<"Player 2's Chips: "<<chips2<<endl;
    cout<<endl;
    cout<<" Would you like to play another turn? (1 = yes / 2 = no) "<<endl;
    cin >> turn;
    if (turn == 1)
    {
      turnend = 1;
    }
    else
    {
      turnend = 0;
      cout << " Thanks for playing! "<<endl;
    }

  }
}
