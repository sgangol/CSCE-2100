/********************************************************************
 ** NAME:  Srizan Gangol         		USERID:sg0440	           	**
 ** ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  node.h											**
 ** Project: Naive Process Scheduler	Program: 4 		          	**
 ** 																**
 ********************************************************************/


#include "process.h"

class Node
{
public:
	process * data; 			// data
	Node * leftNode; 			// pointer to Left Node
	Node * rightNode; 			// pointer to Right Node
	Node * father; 				// pointer to Parent Node
	int num; 					// number of descendants
	Node(); 					// contructor
	~Node(); 					// destructor
	Node(process p); 			// constructor
	void setData(process * p); 	// set data
	process getData(); 			// get data
};

