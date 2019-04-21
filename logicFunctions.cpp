#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>
#include "Project.hpp"

using namespace std;
void LL::pair(Node *player[])
{
  int j=0;
  for(int i=0; i<6; i++){
    if(player[i]->value == player[i+1]->value){
      if(j==0){
        player[7]->suit = player[i]->value;
        j = 1;
      }
      player[7]->value = 1;
    }
  }
  cout<<player[7]->value<<endl;
  cout<<player[7]->suit<<endl;
}

void LL::twopair(Node *player[])
{
  int j=0;
  for(int i=0; i<6; i++){
    if(player[i]->value == player[i+1]->value){
      if(j==0){
        player[7]->suit = player[i]->value;
        j++;
      }
      if(player[7]->suit != player[i]->value){
        player[7]->value = 2;
        if(j == 1){
          player[8]->value = player[i]->value;
          j++;
        }
      }
    }
  }/*
  cout<<"------------------"<<endl;
  cout<<player[7]->value<<endl;
  cout<<player[7]->suit<<endl;
  cout<<player[8]->value<<endl;
  cout<<"------------------"<<endl;*/
}
void LL::threeofakind(Node *player[])
{
  int j=0;
  for(int i=0; i<5; i++){
    if(player[i]->value == player[i+1]->value && player[i]->value == player[i+2]->value){
      if(j==0)
      {
        player[7]->suit = player[i]->value;
        j = 1;
      }
      player[7]->value = 3;
    }
  }
  cout<<player[7]->value<<endl;
  cout<<player[7]->suit<<endl;
}

void LL::straight(Node *player[])
{
  //for(int i = 0; i<3;i++)
}
void LL::flush(Node *player[]){
  int count=0;
  int j=0;
  for(int i=0;i<3;i++){
    if(player[i]->suit == player[i+1]->suit && player[i]->suit == player[i+2]->suit && player[i]->suit == player[i+3]->suit && player[i]->suit == player[i+4]->suit){
      if(j==0){
        player[7]->suit = player[i]->value;
        player[8]->value = player[i+1]->value;
        player[8]->suit = player[i+2]->value;
        player[9]->value = player[i+3]->value;
        player[9]->suit = player[i+4]->value;
        j++;
      }
      player[7]->value = 5;
    }
  }
  cout<<"---------*---------"<<endl;
  cout<<player[7]->value<<endl;
  cout<<player[7]->suit<<endl;
  cout<<player[8]->value<<endl;
  cout<<player[8]->suit<<endl;
  cout<<player[9]->value<<endl;
  cout<<player[9]->suit<<endl;
  cout<<"---------*---------"<<endl;
}
void LL::fullhouse(Node *player[])
{

}
void LL::fourofakind(Node *player[])
{
  for(int i=0; i<4; i++){
    if(player[i]->value == player[i+1]->value && player[i]->value == player[i+2]->value && player[i]->value == player[i+3]->value){
      player[7]->value = 7;
      player[7]->suit = player[i]->value;
    }
  }/*
  cout<<"------------------"<<endl;
  cout<<player[7]->value<<endl;
  cout<<player[7]->suit<<endl;
  //cout<<player[8]->value<<endl;
  cout<<"------------------"<<endl;*/
}
void LL::straightflush(Node *player[])
{
  for(int i=0;i<3;i++){
    if((player[i]->value)+1 == player[i+1]->value && (player[i]->value)+2 == player[i+2]->value && (player[i]->value)+3 == player[i+3]->value && (player[i]->value)+4 == player[i+4]->value){
      if(player[i]->suit == player[i+1]->suit && player[i]->suit == player[i+2]->suit && player[i]->suit == player[i+3]->suit && player[i]->suit == player[i+4]->suit){
        player[7]->value = 9;
      }
    }
  }
  cout<<player[7]->value<<endl;
}
void LL::checkhighcard(Node *player[], Node *player2[])
{

}



void LL::whowins(Node *player1[], Node *player2[])
{
  int playerval1 = 0;
  int playerval2 = 0;



  Node **playeroof1 = new Node*[10];
  Node **playeroof2 = new Node*[10];

  playeroof2[0] = new Node;
  playeroof2[0]->value = 9;
  playeroof2[0]->suit = 0;
  playeroof2[1] = new Node;
  playeroof2[1]->value = 8;
  playeroof2[1]->suit = 1;
  playeroof2[2] = new Node;
  playeroof2[2]->value = 8;
  playeroof2[2]->suit = 1;
  playeroof2[3] = new Node;
  playeroof2[3]->value = 8;
  playeroof2[3]->suit = 1;
  playeroof2[4] = new Node;
  playeroof2[4]->value = 8;
  playeroof2[4]->suit = 1;
  playeroof2[5] = new Node;
  playeroof2[5]->value = 3;
  playeroof2[5]->suit = 0;
  playeroof2[6] = new Node;
  playeroof2[6]->value = 2;
  playeroof2[6]->suit = 1;
  playeroof2[7] = new Node;
  playeroof2[7]->value = 0;
  playeroof2[7]->suit = 0;
  playeroof2[8] = new Node;
  playeroof2[8]->value = 0;
  playeroof2[8]->suit = 0;
  playeroof2[9] = new Node;
  playeroof2[9]->value = 0;
  playeroof2[9]->suit = 0;





  pair(player1);
  pair(player2);

  twopair(player1);
  twopair(player2);

  threeofakind(player1);
  threeofakind(player2);

  straight(player1);
  straight(player2);

  flush(playeroof2);
  flush(playeroof2);

  //fullhouse(player1);
  //fullhouse(player2);

  fourofakind(playeroof2);
  fourofakind(playeroof2);

  straightflush(player1);
  straightflush(player2);


}
