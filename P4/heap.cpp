/********************************************************************
 ** NAME:  Srizan Gangol         		USERID:sg0440	           	**
 ** ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  heap.cpp											**
 ** Project: Naive Process Scheduler	Program: 4 		          	**
 ** 																**
 ********************************************************************/


#include<iostream>
#include<algorithm>
#include"heap.h"

Node *newNode()
{
	Node * tmp = new Node;
	return tmp;
}
Heap::Heap()
{
	top = NULL;
}

Heap::~Heap()
{
	delete top;
}
void Heap::addNode(Node *n, bool type)
{
	addNode(n, top, type);
}

void Heap::addNode(Node *n, Node * cur, bool type)
{
	if (top == NULL)
	{
		top = newNode();
		std::swap(top->data , n->data);
		top->father = NULL;
	} else
	if (cur->leftNode == NULL) 						// if no left child 
	{
		cur->leftNode = newNode();
		cur->num++;
		std::swap(cur->leftNode->data , n->data);
		cur->leftNode->father = cur;
		updateUP(cur->leftNode, type);
	} else 
	if (cur->rightNode == NULL) 					// if no right child
	{
		cur->rightNode = newNode();
		cur->num++;
		std::swap(cur->rightNode->data , n->data);
		cur->rightNode->father = cur;
		updateUP(cur->rightNode, type);
	}
	else  											// if we have left and right child
	{
		cur->num++;
		int k1 = cur->leftNode->num + 1; 			// number of descendants for left child
		int k2 = cur->rightNode->num + 1; 			// number of descendants for right child
		if (k1 & (k1 + 1) != 0)	addNode(n, cur->leftNode, type); else 	
													// if left tree no cmpleted we go there else go right
		if (k2 & (k2 + 1) != 0)	addNode(n, cur->rightNode, type); 
		else addNode(n, cur->leftNode, type); 		// if both completed going to left child
	}
}

void Heap::updateUP(Node * cur, bool type)
{
	if (cur->father == NULL) return; 				// if top
	if (type){
		if (cur->data->getValue() > cur->father->data->getValue()) 
													// if current value > parent's value
		{
			std::swap(cur->data, cur->father->data);
			updateUP(cur->father, type);
		}
		else return;
	}
	else
	{
		if (cur->data->getRuntime() > cur->father->data->getRuntime()) 
														// if current runtime > parent's runtime
		{
			std::swap(cur->data, cur->father->data);
			updateUP(cur->father, type);
		}
	}
}

// Print Function
void Heap::print(bool type)
{
	if (top == NULL) std::cout << "\n\n  ####Sorry! No list found! :( ####\n\n\n";
	else
	{
		std::cout << " ####Printing the list####\n";
	while (top != NULL)
	{ 
		
		std::cout << " Priority Value: ";
		std::cout << top->data->getValue() << " \t Runtime: " <<top->data->getRuntime() << "\n";
		top=updateDOWN(top,type);
	}
		std::cout << " \n\n";
	}
}

Node *findLast(Node * cur, bool type)
{
	if (cur->rightNode == NULL && cur->leftNode == NULL)
	{
		return cur;
	}
	else
	if (cur->rightNode == NULL)
	{
		std::swap(cur->data, cur->leftNode->data);
		return cur->leftNode;
	}
	else
	if (cur->leftNode == NULL)
	{
		std::swap(cur->data, cur->rightNode->data);
		return cur->rightNode;
	}
	else
	{
		int k1, k2;
		if (type){
			k1 = cur->leftNode->data->getValue();
			k2 = cur->rightNode->data->getValue();
		}
		else{
			k1 = cur->leftNode->data->getRuntime();
			k2 = cur->rightNode->data->getRuntime();
		}
		if (k1 > k2)
		{
			std::swap(cur->data, cur->leftNode->data);
			findLast(cur->leftNode, type);
		}
		else
		{
			std::swap(cur->data, cur->rightNode->data);
			findLast(cur->rightNode,type);
		}
	}
}

// Delete
Node * Heap::updateDOWN(Node * cur, bool type)
{
	if (cur->rightNode == NULL && cur->leftNode == NULL)
	{
		delete cur;
		Node * tmp = NULL;
		return tmp;
	} else
	if (cur->rightNode == NULL)
	{
		Node * tmp = newNode();
		std::swap(tmp->data, cur->leftNode->data);
		delete cur;
		return tmp;
	} else 
	if (cur->leftNode == NULL)
	{
		Node * tmp = newNode();
		std::swap(tmp->data, cur->rightNode->data);
		delete cur;
		return tmp;
	}
	else
	{
		Node * tmp = findLast(cur, type);
		if (tmp->father->rightNode == tmp)
		{
			tmp->father->rightNode = NULL;
		}
		else tmp->father->leftNode = NULL;
		delete tmp;
		return cur;
	}
}
// Sorty Priority
void Heap::sortPri()
{
	Heap * tmp = new Heap;
	while (top != NULL)
	{
		Node * tmp1 = newNode();
		std::swap(tmp1, top);
		tmp->addNode(tmp1, 1);
		top = updateDOWN(tmp1,1);
	}
	top = tmp->top;
}

//Sort Time
void Heap::sortTime()
{
	Heap * tmp = new Heap;
	while (top != NULL)
	{
		Node * tmp1 = newNode();
		std::swap(tmp1, top);
		tmp->addNode(tmp1, 0);
		top = updateDOWN(tmp1,1);
	}
	top = tmp->top;
}