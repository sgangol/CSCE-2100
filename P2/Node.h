/********************************************************************
 **        NAME:  Srizan Gangol         USERID:sg0440	           	**
 **  ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  Node.H				Project-2: SkipList		   	**
 **         														**
 ********************************************************************/

#pragma once
// class which represents a number in the list
class Node
{
private:
	// number and next values
	int value;
	Node* right;
	Node* below;

public:
	// default and non-default constructors and destructor
	Node();

	Node(int value);

	~Node();
	// getters
	int getValue();

	Node* getRight();

	Node* getBelow();
	// setters
	void setRight(Node* right);

	void setBelow(Node* below);
	// functions to check is there an element on the right or below, or not
	bool rightExist();

	bool belowExist();
};