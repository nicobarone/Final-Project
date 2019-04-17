#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>
#include "Project.hpp"

using namespace std;
void LL::shuffle(){
  Node* temp = head;
  Node* next = head;
  while(temp != NULL){
    next = temp->next;
    delete temp;
    temp = next;
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


void Heap::printHeap() {
  for(int i = 0; i < currentSize; i++) cout<< heap[i] << endl;
}

/* Max Heap */

void Heap::addToHeap (int value) {
  if (currentSize == heapSize) {
    cout << "Heap overflow" << endl;
  }
  else {
    // insert a value in a heap
    currentSize++;
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

int Heap::peekValue() {
  if (currentSize <= 0) {
    cout << " Heap is empty: returning garbage" << endl;
    return -1;
  }
  else return heap[0];
}

bool Heap::isFull() {
  if (currentSize == heapSize) {
    cout << " Heap is Full " << endl;
    return true;
  }
  else {
    return false;
  }
}

bool Heap::isEmpty() {
  if (currentSize <= 0) {
    cout << " Heap is empty " << endl;
    return true;
  }
  else {
    return false;
  }
}


void LL::createhands(int* array1, int* array2)
{

	Heap hand1(7);
	int newarray1[7];

	for(int i =0; i<7;i++)
	{
		hand1.addToHeap(array1[i]);
	}
	hand1.printHeap();
	cout<<endl;

	for(int i = 0; i < 7;i++)
	{
		newarray1[i] = hand1.removeFromHeap();
	}


	Heap hand2(7);
	int newarray2[7];

	for(int i =0; i<7;i++)
	{
		hand2.addToHeap(array2[i]);
	}
	hand2.printHeap();

	for(int i = 0; i < 7;i++)
	{
		newarray2[i] = hand2.removeFromHeap();
	}
}
/*void LL::newprint()
{
  for(int i = 0; i<7;i++)
  {
    cout<<playerArray1[i]->value<<" "<<playerArray1[i]->suit<<endl;
  }
  for(int i = 0; i<7;i++)
  {
    cout<<playerArray2[i]->value<<" "<<playerArray2[i]->suit<<endl;
  }
}*/
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
  prev->next = pres -> next;
  delete pres;

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



void LL::deal()
{
  //Deal
    srand(time(0));  // Initialize random number generator.
    Node **playerArray1 = new Node*[7];
    Node **playerArray2 = new Node*[7];
    Node **comCards = new Node*[5];

    Node* temp = new Node;
    temp = head;
    int r,j;
    int m = 52;
    for(int i=0; i<2; i++){
      r = (rand() % m) + 1;
      m--;
      cout<<"rand num "<<r<<endl;
      j=1;
      Node* temp = new Node;
      temp = head;
      while(temp->next != NULL){
      if(j == r){
          playerArray1[i] = new Node;
          playerArray1[i]->value = temp->value;
          playerArray1[i]->suit = temp->suit;
          if(r==1){
            deleteAtHead();
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
      cout<<"rand num "<<r<<endl;
      m--;
      j=1;
      temp = head;
      while(temp->next != NULL){
      if(j == r){
          playerArray2[i] = new Node;
          playerArray2[i]->value = temp->value;
          playerArray2[i]->suit = temp->suit;
          if(r==1){
            deleteAtHead();
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
    }
  for(int i=2; i<7; i++){
    r = (rand() % m) + 1;
    cout<<"rand num "<<r<<endl;
    m--;
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
          comCards[i-2] = new Node;
          comCards[i-2]->value = temp->value;
          comCards[i-2]->suit = temp->suit;
          if(r==1){
            deleteAtHead();
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

}

