#include <iostream>
#include "Project.hpp"

using namespace std;

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

  while(temp->next != NULL){
    cout<< temp->value <<" "<< temp->suit<<" -> ";
    temp = temp->next;
  }

  cout<<temp->value<<endl;
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
