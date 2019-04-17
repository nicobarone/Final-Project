#include <iostream>

using namespace std;

struct Node{
	int value;//Jack = 11 Queen = 12 King = 13 Aces = 14
	int suit;
	Node *next;
};

class LL
{
  private:
    Node *head;

  public:
    LL(){
    	head = NULL;
    }
    void insertend(int value, int suit);
		void printListstart();
		void createhands(int* array1, int* array2);
		void deleteAtIndex(int n);
		void deleteAtHead();
		void deal();
};

#ifndef HEAP_HPP
#define HEAP_HPP

class Heap
{
	public:

	Heap(int heapSize);
	~Heap();
	void printHeap();
	void addToHeap (int value);
	int removeFromHeap();
	int peekValue();
	bool isFull();
	bool isEmpty();

	private:

	//void repairUpward(int nodeIndex);
	void repairDownward(int nodeIndex);

	int* heap; //pointer to the array
	int currentSize; //current number of students in heap
	int heapSize; //maximum capacity of the heap
};
#endif
