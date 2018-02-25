/********************************************************************
 **        NAME:  Srizan Gangol         USERID:sg0440	           	**
 **  ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  Node.CPP				Project-2: SkipList		   	**
 **         														**
 ********************************************************************/

#include <iostream>
#include "Node.h"

Node::Node() {
	this->value = 0;
	this->right = NULL;
	this->below = NULL;
}

Node::Node(int value) {
	this->value = value;
	this->right = NULL;
	this->below = NULL;
}

Node::~Node() {
	std::cout << "Node destructor called!\n";
}

int Node::getValue() {
	return value;
}

Node* Node::getRight() {
	return right;
}

Node* Node::getBelow() {
	return below;
}

void Node::setRight(Node* right) {
	this->right = right;
}

void Node::setBelow(Node* below) {
	this->below = below;
}

bool Node::rightExist() {
	if (right != NULL)
		return true;
	return false;
}

bool Node::belowExist() {
	if (below != NULL)
		return true;
	return false;
}