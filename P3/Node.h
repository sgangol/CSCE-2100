/********************************************************************
 ** NAME:  Srizan Gangol         		USERID:sg0440	           	**
 ** ASSIGNMENT:  CSCE2100		  				                  	**
 ** Project: Binary Search Tree							          	**
 ** 																**
 ********************************************************************/
#ifndef _NODE_H_
#define _NODE_H_
#pragma once
class Node
{
public:
	Node();
	~Node();
	void setData(int data);
	int getData();
	struct Node *left;
	struct Node *right;
private:
	int info;
};

#endif //_NODE_H_

