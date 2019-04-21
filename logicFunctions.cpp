//hello

#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>
#include "Project.hpp"

using namespace std;
void LL::pair(Node *player[])
{

}
void LL::twopair(Node *player[])
{

}
void LL::threeofakind(Node *player[])
{

}
void LL::straight(Node *player[])
{

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

  if(pair(player1) == true)
  {
    playerval1 = 1;
  }
  if(pair(player2) == true)
  {
    playerval2 = 1;
  }
  if(twopair(player1) == true)
  {
    playerval1 = 2;
  }
  if(twopair(player2) == true)
  {
    playerval2 = 2;
  }
  if(threeofakind(player1) == true)
  {
    playerval1 = 3;
  }
  if(threeofakind(player2) == true)
  {
    playerval2 = 3;
  }
  if(straight(player1) == true)
  {
    playerval1 = 4;
  }
  if(straight(player2) == true)
  {
    playerval2 = 4;
  }
  if(flush(player1) == true)
  {
    playerval1 = 5;
  }
  if(flush(player2) == true)
  {
    playerval2 = 5;
  }
  if(fullhouse(player1) == true)
  {
    playerval1 = 6;
  }
  if(fullhouse(player2) == true)
  {
    playerval2 = 6;
  }
  if(fourofakind(player1) == true)
  {
    playerval1 = 7;
  }
  if(fourofakind(player2) == true)
  {
    playerval2 = 7;
  }
  if(straightflush(player1) == true)
  {
    playerval1 = 8;
  }
  if(straightflush(player2) == true)
  {
    playerval2 = 8;
  }

  if(playerval1 == playerval2)
  {
    int highcard = checkhighcard(player1,player2);
    if(highcard == 1)
    {
      //return 10;
    }
    else
    {
      //return 20
    }
  }
  else
  {
    if(playerval1 > playerval2)
    {
      //return 10;
    }
    else
    {
      //return 20;
    }
  }
}
