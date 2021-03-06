// Functions that are used to deal cards, create max heaps, linked lists, and other print statements
#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>
#include "Project.hpp"

using namespace std;
void LL::printCommunity(Node *communityCards[], int i){
  if(communityCards[i]->value == 11){
    cout<<" Jack";
  }
  else if(communityCards[i]->value == 12){
    cout<<" Queen";
  }
  else if(communityCards[i]->value == 13){
    cout<<" King";
  }
  else if(communityCards[i]->value == 14){
    cout<<" Ace";
  }
  else{
    cout<<" "<<communityCards[i]->value;
  }

  cout<< " of ";

  if(communityCards[i]->suit == 0){
    cout<<"Hearts"<<endl;
  }
  else if(communityCards[i]->suit == 1){
    cout<<"Diamonds"<<endl;
  }
  else if(communityCards[i]->suit == 2){
    cout<<"Spades"<<endl;
  }
  else if(communityCards[i]->suit == 3){
    cout<<"Clubs"<<endl;
  }
}
void LL::printHand(Node *firsttwo[]){
  if(firsttwo[0]->value == 11){
    cout<<" Jack";
  }
  else if(firsttwo[0]->value == 12){
    cout<<" Queen";
  }
  else if(firsttwo[0]->value == 13){
    cout<<" King";
  }
  else if(firsttwo[0]->value == 14){
    cout<<" Ace";
  }
  else{
    cout<<" "<<firsttwo[0]->value;
  }

  cout<< " of ";

  if(firsttwo[0]->suit == 0){
    cout<<"Hearts";
  }
  else if(firsttwo[0]->suit == 1){
    cout<<"Diamonds";
  }
  else if(firsttwo[0]->suit == 2){
    cout<<"Spades";
  }
  else if(firsttwo[0]->suit == 3){
    cout<<"Clubs";
  }
  cout<<"  and  ";



  if(firsttwo[1]->value == 11){
    cout<<"Jack";
  }
  else if(firsttwo[1]->value == 12){
    cout<<"Queen";
  }
  else if(firsttwo[1]->value == 13){
    cout<<"King";
  }
  else if(firsttwo[1]->value == 14){
    cout<<"Ace";
  }
  else{
    cout<<firsttwo[1]->value;
  }


  cout<< " of ";


  if(firsttwo[1]->suit == 0){
    cout<<"Hearts"<<endl;
  }
  else if(firsttwo[1]->suit == 1){
    cout<<"Diamonds"<<endl;
  }
  else if(firsttwo[1]->suit == 2){
    cout<<"Spades"<<endl;
  }
  else if(firsttwo[1]->suit == 3){
    cout<<"Clubs"<<endl;
  }
  
}

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
  if(temp == NULL){
    cout<<"List is empty"<<endl;
  }
  else{
    while(temp->next != NULL){
      cout<< temp->value <<" "<< temp->suit<<" -> ";
      temp = temp->next;
    }
    cout<<temp->value<<" "<<temp->suit<<endl;
  }
}

int parent(int index) {return (index-1)/2;}
int leftChild(int index) {return 2*index+1;}
int rightChild(int index) {return 2*index+2;}
void swap(int &x, int &y) {int z = x; x = y; y = z;}

Heap::Heap(int heapSize) {
  currentSize = 0;
  heap = new int[heapSize];
}

Heap::~Heap(){
  delete[] heap;
}

/* Max Heap */

void Heap::addToHeap (int value) {
  heapSize = 100;
  if (currentSize == heapSize) {
    cout << "Heap overflow " << currentSize<< endl;
  }
  else {
    // insert a value in a heap
    currentSize++;
    //cout<< currentSize<<endl;
    heap[currentSize-1] = value;
    int i = currentSize-1;
    while(parent(i) >= 0 && heap[parent(i)] < heap[i]){
      swap(heap[i], heap[parent(i)]);
      i = parent(i);
    }
  }
}

void Heap::repairDownward(int index) {
  int max = index;
  if (leftChild(index) < currentSize) {
    if (heap[max] < heap[leftChild(index)]) max = leftChild(index);
  }
  if (rightChild(index) < currentSize) {
    if (heap[max] < heap[rightChild(index)]) max = rightChild(index);
  }

  if (index == max) {
    // Already heapified
    return;
  }
  else {
    swap(heap[max], heap[index]);
    repairDownward(max);
  }
}

/* Max Heap */

int Heap::removeFromHeap() { // just for min heaps
  if (currentSize <= 0) {
    cout << " Heap is empty: returning garbage" << endl;
    return -1;
  }
  else {
    int result = heap[0];
    heap[0] = heap[currentSize-1];
    currentSize = currentSize - 1;
    repairDownward(0);
    return result;
  }
}


void LL::deleteAtIndex(int n)
{


  if(head == NULL){
    cout<< "List is already empty"<<endl;

  }

  Node *pres = head;
  Node *prev = NULL;
  for(int i = 0;i<n;i++)
  {
    prev = pres;
    pres = pres -> next;
  }
  if(pres->next == NULL){
   prev->next = NULL;
   delete pres;
  }
  else{
   prev->next = pres -> next;
   delete pres;
  }

}

void LL::deleteAtHead()
{


  if(head == NULL){
    cout<< "List is already empty"<<endl;

  }

  Node *temp = head;
  head = temp->next;
  delete temp;

}



void LL::deal(Node *playerArray1[], Node *playerArray2[], Node *communityCards[], Node *firsttwo1[], Node *firsttwo2[])
{
  //Deal
    srand(time(0));  // Initialize random number generator.


    Node* temp = new Node;
    temp = head;
    int r,j;
    int m = 52;
    for(int i=0; i<2; i++){
      r = (rand() % m) + 1;
      m = m - 1;
      //cout<<"rand num "<<r<<endl;
      j=1;
      Node* temp = new Node;
      temp = head;
      while(temp->next != NULL){
      if(j == r){
          playerArray1[i] = new Node;
          playerArray1[i]->value = temp->value;
          playerArray1[i]->suit = temp->suit;
          firsttwo1[i] = new Node;
          firsttwo1[i]->value = temp->value;
          firsttwo1[i]->suit = temp->suit;
          if(r==1){
            deleteAtHead(); // deleting from deck
          }
          else{
            deleteAtIndex(r-1);
          }
            //Now call remove r function from the linked list
          //delete memory too
        }
        temp = temp->next;
        j++;
      }
      r = (rand() % m) + 1;
      //cout<<"rand num "<<r<<endl;
      m = m - 1;
      j=1;
      temp = head;
      while(temp->next != NULL){
      if(j == r){
          playerArray2[i] = new Node;
          playerArray2[i]->value = temp->value;
          playerArray2[i]->suit = temp->suit;
          firsttwo2[i] = new Node;
          firsttwo2[i]->value = temp->value;
          firsttwo2[i]->suit = temp->suit;
          if(r==1){
            deleteAtHead();
          }
          else{
            deleteAtIndex(r-1);
          }
        }
        temp = temp->next;
        j++;
      }
    }
  for(int i=2; i<7; i++){
    r = (rand() % m) + 1;
    m = m - 1;
      j=1;
      temp = head;
    while(temp->next != NULL){
        if(j == r){
          playerArray1[i] = new Node;
          playerArray1[i]->value = temp->value;
          playerArray1[i]->suit = temp->suit;
          playerArray2[i] = new Node;
          playerArray2[i]->value = temp->value;
          playerArray2[i]->suit = temp->suit;
          communityCards[i-2] = new Node;
          communityCards[i-2]->value = temp->value;
          communityCards[i-2]->suit = temp->suit;
          if(r==1){
            deleteAtHead();
          }
          else{
            deleteAtIndex(r-1);
          }
        }
        temp = temp->next;
        j++;
      }
  }

  cout<<"player 1 hand"<<endl;

  for(int i = 0; i<7;i++)
  {
    cout<<playerArray1[i]->value<<" "<<playerArray1[i]->suit<<endl;
  }

  cout<<"player 2 hand"<<endl;
  for(int i = 0; i<7;i++)
  {
    cout<<playerArray2[i]->value<<" "<<playerArray2[i]->suit<<endl;
  }

  int testarray[7]; // in order to sort and keep the suit with value
  int testarray2[7];

  for(int i =0; i < 7;i++)
  {
    if(playerArray1[i]->suit == 0)
    {
      testarray[i] = (playerArray1[i]->value * 10) + playerArray1[i]->suit + 2 ;
    }
    else if(playerArray1[i]->suit == 1)
    {
      testarray[i] = (playerArray1[i]->value * 10) + playerArray1[i]->suit + 2 ;
    }
    else if(playerArray1[i]->suit == 2)
    {
      testarray[i] = (playerArray1[i]->value * 10) + playerArray1[i]->suit + 2 ;
    }
    else if(playerArray1[i]->suit == 3)
    {
      testarray[i] = (playerArray1[i]->value * 10) + playerArray1[i]->suit + 2 ;
    }
  }

  for(int i =0; i < 7;i++)
  {
    if(playerArray2[i]->suit == 0)
    {
      testarray2[i] = (playerArray2[i]->value * 10) + playerArray2[i]->suit + 2 ;
    }
    else if(playerArray2[i]->suit == 1)
    {
      testarray2[i] = (playerArray2[i]->value * 10) + playerArray2[i]->suit + 2 ;
    }
    else if(playerArray2[i]->suit == 2)
    {
      testarray2[i] = (playerArray2[i]->value * 10) + playerArray2[i]->suit + 2 ;
    }
    else if(playerArray2[i]->suit == 3)
    {
      testarray2[i] = (playerArray2[i]->value * 10) + playerArray2[i]->suit + 2 ;
    }
  }


  cout<<endl;

  Heap p1(20); // max heaps used for sorting
  Heap p2(20);


  for(int i =0; i<7;i++)
  {
    p1.addToHeap(testarray[i]);
  }


  for(int i =0; i<7;i++)
  {
    p2.addToHeap(testarray2[i]);
  }


  for(int i = 0; i < 10;i++)
  {
    playerArray1[i] = new Node;
    if (i >= 7)
    {
      playerArray1[i]->value = 0;
      playerArray1[i]->suit = 0;
    }
    else {
    playerArray1[i]->value = p1.removeFromHeap();
    playerArray1[i]->suit = 0;
   }
  }

  for(int i = 0; i < 10;i++)
  {
    playerArray2[i] = new Node;
    if (i >= 7)
    {
      playerArray2[i]->value = 0;
      playerArray2[i]->suit = 0;
    }
    else {
    playerArray2[i]->value = p2.removeFromHeap();
    playerArray2[i]->suit = 0;
   }
  }
  cout<<endl;
  cout<<"New array"<<endl;

  for(int i = 0; i < 10;i++)
  {
    float rem = playerArray1[i]->value % 5;


    if(rem == 0)
    {
      playerArray1[i]->value = (playerArray1[i]->value - 5) / 10;
      playerArray1[i]->suit = 3;
    }
    else if(rem == 4)
    {
      playerArray1[i]->value = (playerArray1[i]->value - 4) / 10;
      playerArray1[i]->suit = 2;
    }
    else if(rem == 3)
    {
      playerArray1[i]->value = (playerArray1[i]->value - 3) / 10;
      playerArray1[i]->suit = 1;
    }
    else
    {
      playerArray1[i]->value = (playerArray1[i]->value - 2) / 10;
      playerArray1[i]->suit = 0;
    }

    cout<<playerArray1[i]->value<<" "<<playerArray1[i]->suit<<"  ";
  }
  cout<<endl;

  cout<<endl;
  cout<<"New array"<<endl;

  for(int i = 0; i < 10;i++)
  {
    float rem = playerArray2[i]->value % 5;

    if(rem == 0)
    {
      playerArray2[i]->value = (playerArray2[i]->value - 5) / 10;
      playerArray2[i]->suit = 3;
    }
    else if(rem == 4)
    {
      playerArray2[i]->value = (playerArray2[i]->value - 4) / 10;
      playerArray2[i]->suit = 2;
    }
    else if(rem == 3)
    {
      playerArray2[i]->value = (playerArray2[i]->value - 3) / 10;
      playerArray2[i]->suit = 1;
    }
    else
    {
      playerArray2[i]->value = (playerArray2[i]->value - 2) / 10;
      playerArray2[i]->suit = 0;
    }
    cout<<playerArray2[i]->value<<" "<<playerArray2[i]->suit<<"  ";
  }
  cout<<endl;

  playerArray1[7]->suit = 0;
  playerArray2[7]->suit = 0;
  playerArray1[8]->suit = 0;
  playerArray2[8]->suit = 0;
  playerArray1[9]->suit = 0;
  playerArray2[8]->suit = 0;

  whowins(playerArray1, playerArray2);


  for(int i = 0; i<44;i++)
  {
    deleteAtHead(); // delets the whole list of cards in order to create a new one for next turn
  }
  //printListstart();
}
