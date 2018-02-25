/********************************************************************
 ** NAME:  Srizan Gangol         		USERID:sg0440	           	**
 ** ASSIGNMENT:  CSCE2100		  				                  	**
 ** Project: Binary Search Tree							          	**
 ** 																**
 ********************************************************************/
#include "Node.h"


Node::Node()
{
	info = -1;
}


Node::~Node()
{
	delete left;
	delete right;
}

void Node::setData(int data)
{ 
	info = data; 
}

int Node::getData()
{ 
	return info; 
}
