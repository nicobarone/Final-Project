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
  }

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

}

void LL::straight(Node *player[])
{
  int k=0;
  int m=0;
  int x = player[7]->value;
  int y = player[8]->value;
  player[8]->value = 100;
  for(int i=0; i<3; i++){
    int j=0;
    m = i;
    while(player[i+1]->value == (player[i]->value-1) || player[i+1]->value == player[i]->value){
      if(player[i+1]->value != player[i]->value){
        j++;
      }
      i++;
      if(j == 4){
        player[7]->value = 4;
        k=1;
        break;
      }
    }
    if(k == 1){
      player[7]->suit = player[m]->value;
      break;
    }
    i=m;
  }
  if((player[7]->value != 4) && (player[0]->value == 14)){
    player[7]->value = 1;
    int z = 0,g=0;
    for(int p=0;p<4;p++){
      int n = 0;
      z=p;
      while(player[p+1]->value == (player[p]->value-1) || player[p+1]->value == player[p]->value){
        if(player[p+1]->value != player[p]->value){
          n++;
        }
        p++;
        if(n == 4){
          player[7]->value = 4;
          g=1;
          break;
        }
      }
      if(g == 1){
        player[7]->suit = player[z]->value;
        break;
      }
      p=z;
    }
  }
  if(player[7]->value != 4){
    player[7]->value = x;
  }
  player[8]->value = y;

}



void LL::flush(Node *player[]){
  int count0=0,count1=0,count2=0,count3=0;
  int j=4;
  int l=0;
  for(int i=0;i<7;i++){
    if(player[i]->suit == 0){
      count0++;
      if(count0 == 5){
        j=0;
      }
    }
    else if(player[i]->suit == 1){
      count1++;
      if(count1 == 5){
        j=1;
      }
    }
    else if(player[i]->suit == 2){
      count2++;
      if(count2 == 5){
        j=2;
      }
    }
    else if(player[i]->suit == 3){
      count3++;
      if(count3 == 5){
        j=3;
      }
    }
  }
  if(j != 4){
    player[7]->value = 5;
    for(int k=0;k<7;k++){
      if(player[k]->suit == j){
        if(l==0){
          player[7]->suit = player[k]->value;
          l++;
        }
        else if(l==1){
          player[8]->value = player[k]->value;
          l++;
        }
        else if(l==2){
          player[8]->suit = player[k]->value;
          l++;
        }
        else if(l==3){
          player[9]->value = player[k]->value;
          l++;
        }
        else if(l==4){
          player[9]->suit = player[k]->value;
          l++;
        }
      }
    }
  }

}
void LL::fullhouse(Node *player[])
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
  if(player[7]->value == 3)
  {
    int j=0;
    for(int i=0; i<6; i++){
      if(player[i]->value == player[i+1]->value){
        if(j==0){
          if(player[i]->value == player[7]->suit)
          {
            j = 0;
          }
          else
          {
            player[7]->value = 6;
            player[8]->value = player[i]->value;
          }
        }

      }
    }
  }

}
void LL::fourofakind(Node *player[])
{
  for(int i=0; i<4; i++){
    if(player[i]->value == player[i+1]->value && player[i]->value == player[i+2]->value && player[i]->value == player[i+3]->value){
      player[7]->value = 7;
      player[7]->suit = player[i]->value;
    }
  }

}
void LL::straightflush(Node *player[])
{
  int count0=0,count1=0,count2=0,count3=0;
  int w = 4;
  for(int q=0;q<7;q++){
    if(player[q]->suit == 0){
      count0++;
      if(count0 == 5){
        w=0;
      }
    }
    else if(player[q]->suit == 1){
      count1++;
      if(count1 == 5){
        w=1;
      }
    }
    else if(player[q]->suit == 2){
      count2++;
      if(count2 == 5){
        w=2;
      }
    }
    else if(player[q]->suit == 3){
      count3++;
      if(count3 == 5){
        w=3;
      }
    }
  }
  if(w != 4){
    int k=0;
    int m=0;
    int x = player[7]->value;
    int t = player[7]->suit;
    int y = player[8]->value;
    player[8]->value = 100;
    for(int i=0; i<3; i++){
      int j=0;
      m = i;
    while(player[i+1]->value == (player[i]->value-1) || player[i+1]->value == player[i]->value){
      if(player[i+1]->value == (player[i]->value-1) && player[i]->suit == w){
        j++;
      }
      i++;
      if(j == 4){
        player[7]->value = 8;
        k=1;
        break;
      }
    }
    if(k == 1){
      player[7]->suit = player[m]->value;
      break;
    }
    i=m;
  }
  if((player[7]->value != 8) && (player[0]->value == 14)){
    player[7]->value = 1;
    int z = 0,g=0;
    for(int p=0;p<4;p++){
      int n = 0;
      z=p;
      while(player[p+1]->value == (player[p]->value-1) || player[p+1]->value == player[p]->value){
        if(player[p+1]->value == (player[p]->value-1) && player[p]->suit == w){
            n++;
        }
        p++;
        if(n == 4){
          player[7]->value = 8;
          g=1;
          break;
        }
      }
      if(g == 1){
        player[7]->suit = player[z]->value;
        break;
      }
      p=z;
    }
  }
  if(player[7]->value != 8){
    player[7]->value = x;
    player[7]->value = t;
  }
  player[8]->value = y;
  }
  cout<<"???????????????????????"<<endl;
  cout<<player[7]->value<<endl;
  cout<<player[7]->suit<<endl<<endl;
}
void LL::checkhighcard(Node *player[], Node *player2[])
{

}



void LL::whowins(Node *player1[], Node *player2[])
{

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

  if(player1[7]->value > player2[7]->value)
  {
    player1[7]->value = 100;
    cout<<"Player 1 wins"<<endl;
  }
  else if (player2[7]->value > player1[7]->value)
  {
    player2[7]->value = 100;
    cout<<"Player 2 wins"<<endl;
  }
  else if (player1[7]->value == player2[7]->value)
  {
    if (player1[7]->value == 0)
    {
      for (int i = 0; i < 5;i++)
      {
        if(player1[i]->value > player2[i]->value)
        {
          player1[7]->value = 100;
          cout<<"Player 1 wins"<<endl;
          break;
        }
        else if(player1[i]->value < player2[i]->value)
        {
          player2[7]->value = 100;
          cout<<"Player 2 wins"<<endl;
          break;
        }
        else
        {
          if (i == 5)
          {
            cout<<"Tie "<<endl;
            player1[7]->value = 200;
            break;
          }
        }
      }
    }
    else if (player1[7]->value == 1)
    {
      if (player1[7]->suit > player2[7]->suit)
      {
        player1[7]->value = 100;
        cout<<"Player 1 wins"<<endl;
      }
      else if (player1[7]->suit < player2[7]->suit)
      {
        player2[7]->value = 100;
        cout<<"Player 2 wins"<<endl;
      }
      else
      {
        for (int i = 0; i < 5;i++)
        {
          if(player1[i]->value > player2[i]->value)
          {
            player1[7]->value = 100;
            cout<<"Player 1 wins"<<endl;
            break;
          }
          else if(player1[i]->value < player2[i]->value)
          {
            player2[7]->value = 100;
            cout<<"Player 2 wins"<<endl;
            break;
          }
          else
          {
            if (i == 5)
            {
              cout<<"Tie "<<endl;
              player1[7]->value = 200;
              break;
            }
          }
        }
      }
    }
    else if (player1[7]->value == 2)
    {
      if (player1[7]->suit > player2[7]->suit)
      {
        player1[7]->value = 100;
        cout<<"Player 1 wins"<<endl;
      }
      else if (player1[7]->suit < player2[7]->suit)
      {
        player2[7]->value = 100;
        cout<<"Player 2 wins"<<endl;
      }
      else if (player1[8]->value > player2[8]->value)
      {
        player1[7]->value = 100;
        cout<<"Player 1 wins"<<endl;
      }
      else if (player1[8]->value < player2[8]->value)
      {
        player2[7]->value = 100;
        cout<<"Player 2 wins"<<endl;
      }
      else
      {
        for (int i = 0; i < 5;i++)
        {
          if(player1[i]->value > player2[i]->value)
          {
            player1[7]->value = 100;
            cout<<"Player 1 wins"<<endl;
            break;
          }
          else if(player1[i]->value < player2[i]->value)
          {
            player2[7]->value = 100;
            cout<<"Player 2 wins"<<endl;
            break;
          }
          else
          {
            if (i == 5)
            {
              cout<<"Tie "<<endl;
              player1[7]->value = 200;
              break;
            }
          }
        }
      }

    }
    else if (player1[7]->value == 3)
    {
      if (player1[7]->suit > player2[7]->suit)
      {
        player1[7]->value = 100;
        cout<<"Player 1 wins"<<endl;
      }
      else if (player1[7]->suit < player2[7]->suit)
      {
        player2[7]->value = 100;
        cout<<"Player 2 wins"<<endl;
      }
      else
      {
        for (int i = 0; i < 5;i++)
        {
          if(player1[i]->value > player2[i]->value)
          {
            player1[7]->value = 100;
            cout<<"Player 1 wins"<<endl;
            break;
          }
          else if(player1[i]->value < player2[i]->value)
          {
            player2[7]->value = 100;
            cout<<"Player 2 wins"<<endl;
            break;
          }
          else
          {
            if (i == 5)
            {
              cout<<"Tie "<<endl;
              player1[7]->value = 200;
              break;
            }
          }
        }
      }
    }
    else if (player1[7]->value == 4)
    {
      if (player1[7]->suit > player2[7]->suit)
      {
        player1[7]->value = 100;
        cout<<"Player 1 wins"<<endl;
      }
      else if (player1[7]->suit < player2[7]->suit)
      {
        player2[7]->value = 100;
        cout<<"Player 2 wins"<<endl;
      }
      else
      {
        cout<<"Tie "<<endl;
        player1[7]->value = 200;
      }
    }
    else if (player1[7]->value == 5)
    {
      if (player1[7]->suit > player2[7]->suit)
      {
        player1[7]->value = 100;
        cout<<"Player 1 wins"<<endl;
      }
      else if (player1[7]->suit < player2[7]->suit)
      {
        player2[7]->value = 100;
        cout<<"Player 2 wins"<<endl;
      }
      else
      {
        if (player1[8]->value > player2[8]->value)
        {
          player1[7]->value = 100;
          cout<<"Player 1 wins"<<endl;
        }
        else if (player1[8]->value < player2[8]->value)
        {
          player2[7]->value = 100;
          cout<<"Player 2 wins"<<endl;
        }
        else
        {
          if (player1[8]->suit > player2[8]->suit)
          {
            player1[7]->value = 100;
            cout<<"Player 1 wins"<<endl;
          }
          else if (player1[8]->suit < player2[8]->suit)
          {
            player2[7]->value = 100;
            cout<<"Player 2 wins"<<endl;
          }
          else
          {
            if (player1[9]->value > player2[9]->value)
            {
              player1[7]->value = 100;
              cout<<"Player 1 wins"<<endl;
            }
            else if (player1[9]->value < player2[9]->value)
            {
              player2[7]->value = 100;
              cout<<"Player 2 wins"<<endl;
            }
            else
            {
              if (player1[9]->suit > player2[9]->suit)
              {
                player1[7]->value = 100;
                cout<<"Player 1 wins"<<endl;
              }
              else if (player1[9]->suit < player2[9]->suit)
              {
                player2[7]->value = 100;
                cout<<"Player 2 wins"<<endl;
              }
              else
              {
                cout<<"Tie "<<endl;
                player1[7]->value = 200;
              }
            }
          }
        }
      }
    }
    else if (player1[7]->value == 6)
    {
      if (player1[7]->suit > player2[7]->suit)
      {
        player1[7]->value = 100;
        cout<<"Player 1 wins"<<endl;
      }
      else if (player1[7]->suit < player2[7]->suit)
      {
        player2[7]->value = 100;
        cout<<"Player 2 wins"<<endl;
      }
      else
      {
        if (player1[8]->value > player2[8]->value)
        {
          player1[7]->value = 100;
          cout<<"Player 1 wins"<<endl;
        }
        else if (player1[8]->value < player2[8]->value)
        {
          player2[7]->value = 100;
          cout<<"Player 2 wins"<<endl;
        }
        else
        {
          cout<<"Tie "<<endl;
          player1[7]->value = 200;
        }
      }
    }
    else if (player1[7]->value == 7)
    {
      if (player1[7]->suit > player2[7]->suit)
      {
        player1[7]->value = 100;
        cout<<"Player 1 wins"<<endl;
      }
      else if (player1[7]->suit < player2[7]->suit)
      {
        player2[7]->value = 100;
        cout<<"Player 2 wins"<<endl;
      }
      else
      {
        for (int i = 0; i < 5;i++)
        {
          if(player1[i]->value > player2[i]->value)
          {
            player1[7]->value = 100;
            cout<<"Player 1 wins"<<endl;
            break;
          }
          else if(player1[i]->value < player2[i]->value)
          {
            player2[7]->value = 100;
            cout<<"Player 2 wins"<<endl;
            break;
          }
          else
          {
            if (i == 5)
            {
              cout<<"Tie "<<endl;
              player1[7]->value = 200;
              break;
            }
          }
        }
      }
    }
    else if (player1[7]->value == 8)
    {
      if (player1[7]->suit > player2[7]->suit)
      {
        player1[7]->value = 100;
        cout<<"Player 1 wins"<<endl;
      }
      else if (player1[7]->suit < player2[7]->suit)
      {
        player2[7]->value = 100;
        cout<<"Player 2 wins"<<endl;
      }
      else
      {
        cout<<"Tie "<<endl;
        player1[7]->value = 200;
      }
    }
  }
}
