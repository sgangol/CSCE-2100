/********************************************************************
 **        NAME:  Srizan Gangol         USERID:sg0440	           	**
 **  ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  SkipList.H			Project-2: SkipList		   	**
 **         														**
 ********************************************************************/

#pragma once
#include "Node.h"

class SkipList
{
private:
	// head element of the list
	Node* head;
public:
	// default constructor
	SkipList();
	// function to create elements with random length
	bool coinFlip();
	// function to add element
	bool addElement(int value);
	// function to find element
	bool findElement(int value);
	// function to delete element
	bool deleteElement(int value);
	// function to produce output into console
	void printList();
};