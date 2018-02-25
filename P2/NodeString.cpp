/********************************************************************
 **        NAME:  Srizan Gangol         USERID:sg0440	           	**
 **  ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  NodeString.cpp		Project-2: SkipList		   	**
 **         														**
 ********************************************************************/
#include <iostream>
#include "NodeString.h"

NodeString::NodeString() {
	this->value = "";
	this->right = NULL;
	this->below = NULL;
}

NodeString::NodeString(std::string value) {
	this->value = value;
	this->right = NULL;
	this->below = NULL;
}

NodeString::~NodeString() {
	std::cout << "NodeString destructor called!\n";
}

std::string NodeString::getValue() {
	return value;
}

NodeString* NodeString::getRight() {
	return right;
}

NodeString* NodeString::getBelow() {
	return below;
}

void NodeString::setRight(NodeString* right) {
	this->right = right;
}

void NodeString::setBelow(NodeString* below) {
	this->below = below;
}

bool NodeString::rightExist() {
	if (right != NULL)
		return true;
	return false;
}

bool NodeString::belowExist() {
	if (below != NULL)
		return true;
	return false;
}