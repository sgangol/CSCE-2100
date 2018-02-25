/********************************************************************
 **        NAME:  Srizan Gangol         USERID:sg0440	           	**
 **  ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  SkipListString.H		Project-2: SkipList		   	**
 **         														**
 ********************************************************************/

#pragma once
#include "NodeString.h"

class SkipListString
{
private:
	// head element of the list
	NodeString* head;
public:
	// default constructor
	SkipListString();
	// function to create elements with random length
	bool coinFlip();
	// function to add element
	bool addElement(std::string value);
	// function to find element
	bool findElement(std::string value);
	// function to delete element
	bool deleteElement(std::string value);
	// function to produce output into console
	void printList();
};