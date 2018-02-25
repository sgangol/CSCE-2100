/********************************************************************
 ** NAME:  Srizan Gangol         		USERID:sg0440	           	**
 ** ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  heap.h											**
 ** Project: Naive Process Scheduler	Program: 4 		          	**
 ** 																**
 ********************************************************************/



#include"node.h"

class Heap
{
private:
	Node * top; 									// top of the Heap (Max value)
	void addNode(Node * n, Node * cur, bool type); 
	Node * updateDOWN(Node * cur, bool type); 		// updating after removing element
	void updateUP(Node * cur, bool type); 			// updating tree after adding new element
public:
	Heap(); 										// constructor
	~Heap(); 										// destructor
	void addNode(Node *n, bool type); 				// adding new node to tree
	void print(bool type); 							// print list of process
	void sortTime(); 								// sorting by duration of process
	void sortPri(); 								// sorting by priority value of process
};

Node * newNode(); 