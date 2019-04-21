//hello

#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>
#include "Project.hpp"

using namespace std;
void LL::pair(Node *player[])
{
  for(int i=0; i<6; i++){
    if(player[i]->value == player[i+1]->value){
      player[8]->value = 1;
    }
  }
  cout<<player[8->value];
}
void LL::twopair(Node *player[])
{

}
void LL::threeofakind(Node *player[])
{
  for(int i=0; i<5; i++){
    if(player[i]->value == player[i+1]->value && player[i]->value == player[i+2]->value){
      player[8]->value = 3;
    }
  }
  cout<<player[8->value];
}
void LL::straight(Node *player[])
{
  for(int i=0;i<3;i++){
    if((player[i]->value)+1 == player[i+1]->value && (player[i]->value)+2 == player[i+2]->value) && (player[i]->value)+3 == player[i+3]->value && (player[i]->value)+4 == player[i+4]->value){
      player[8]->value = 4;
    }
  }
}
void LL::flush(Node *player[])
{

}
void LL::fullhouse(Node *player[])
{

}
void LL::fourofakind(Node *player[])
{

}
void LL::straightflush(Node *player[])
{

}
void LL::checkhighcard(Node *player[], Node *player2[])
{

}



void LL::whowins(Node *player1[], Node *player2[])
{
  int playerval1 = 0;
  int playerval2 = 0;

  

  pair(player1);
  pair(player2);

  twopair(player1);
  twopair(player2);

  threeofakind(player1);
  threeofakind(player2);

  straight(player1);
  straight(player2);

  flush(player1);
  flush(player2);

  fullhouse(player1);
  fullhouse(player2);

  fourofakind(player1);
  fourofakind(player2);

  straightflush(player1);
  straightflush(player2);


}

