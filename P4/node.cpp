/********************************************************************
 ** NAME:  Srizan Gangol         		USERID:sg0440	           	**
 ** ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  node.cpp											**
 ** Project: Naive Process Scheduler	Program: 4 		          	**
 ** 																**
 ********************************************************************/

#include<iostream>
#include"node.h";

Node::Node()
{
	data = new process;
	leftNode = NULL;
	rightNode = NULL;
	father = NULL;
	num = 0;
}

Node::~Node()
{
	delete data;
	delete leftNode;
	delete rightNode;
}

Node::Node(process p)
{
	data = &p;
	leftNode = NULL;
	rightNode = NULL;
	father = NULL;
	num = 0;
}

void Node::setData(process * p)
{
	data = p;
}

process Node::getData()
{
	return *data;
}

