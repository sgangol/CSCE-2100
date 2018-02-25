/********************************************************************
 ** NAME:  Srizan Gangol         		USERID:sg0440	           	**
 ** ASSIGNMENT:  CSCE2100		  				                  	**
 ** Project: Binary Search Tree							          	**
 ** 																**
 ********************************************************************/

#ifndef _BST_H_
#define _BST_H_
#include <iostream>
#include "Node.h"
#pragma once

using namespace std;
class BST
{
public:
	BST();
	~BST();

	void addElement(Node *tree, Node *newnode);

	void findElement(int, Node **, Node **);

	void removeElement(int);

	void printTree(Node *, int);

	void case_a(Node *, Node *);

	void case_b(Node *, Node *);

	void case_c(Node *, Node *);

	Node * getRoot() { return root; }

private:

	Node *root;
};
#endif //_BST_H_
