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
};
