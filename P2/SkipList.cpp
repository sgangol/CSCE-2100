/********************************************************************
 **        NAME:  Srizan Gangol         USERID:sg0440	           	**
 **  ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  SkipList.CPP			Project-2: SkipList		   	**
 **         														**
 ********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Node.h"
#include "SkipList.h"

SkipList::SkipList() {
	head = NULL;
}

// SkipList: Randomizing the SkipList (Level)
bool SkipList::coinFlip() {
	// 50% chances of returning Head or Tail
	if (rand() % 2 == 0)
		return false;
	return true;
}

// addElement: Adding value
bool SkipList::addElement(int value) {
	// create temporary nodes
	Node* temp = new Node(value);
	Node* levelsadder = new Node(value);
	// if list is empty - create a head node
	if (head == NULL) {
		head = temp;
		levelsadder = head;
	}
	else {
		if (head->getValue() > value) {
			temp->setRight(head);
			head = temp;
		}
		else {
			// if not - find a place for a new node
			Node* iterator = head;
			while (iterator->rightExist()) {
				// if value is already in the list - exit with a prompt
				if (iterator->getValue() == value) {
					std::cout << " Sorry!! Duplicate values are not allowed\n";
					return false;
				}
				// stop when next node has greater value
				if (iterator->getRight()->getValue() > value)
					break;
				// while proper position isn`t found - iterate over the list
				iterator = iterator->getRight();
			}
			// if position for the node is in the middle of the list - move the nodes right to it
			if (iterator->rightExist())
				temp->setRight(iterator->getRight());
			// insert new node
			iterator->setRight(temp);
		}
		// start leveling
		levelsadder = temp;
	}
	// create a chain of elements using random
	while (coinFlip()) {
		levelsadder->setBelow(new Node(value));
		levelsadder = levelsadder->getBelow();
	}
	std::cout << " Value(s) successfully added!\n";
	return true;
}

// findElement: Searches for the value
bool SkipList::findElement(int value) {
	// variable for result
	bool valueFound = false;
	// if list is empty
	if (head == NULL) {
		std::cout << " Sorry! Value is not presented in the list!\n";
		return valueFound;
	}
	// if not - start iterating over it
	Node* iterator = head;
	while(true) {
		// if value is found
		if (iterator->getValue() == value) {
			valueFound = true;
			break;
		}
		// if not - move to next element
		else {
			if (iterator->rightExist())
				iterator = iterator->getRight();
			else
				break;
		}
	}
	if (valueFound)
		std::cout << " Value is presented in the list!\n";
	else
		std::cout << " Value is not presented in the list!\n";
	return valueFound;
}

// deleteElement: Deletes Element
bool SkipList::deleteElement(int value) {
	// if there is no such element
	if (!findElement(value)) {
		std::cout << " Sorry! Can`t delete nonexistent node!\n";
		return false;
	}
	else {
		Node* nodeToDelete = NULL;
		Node* iterator = NULL;
		// check if head is a node to delete
		if (head->getValue() == value) {
			nodeToDelete = head;
			head = head->getRight();
		}
		else {
			iterator = head;
			// if not - iterate over the list to find it
			while (iterator->rightExist()) {
				// if node is found
				if (iterator->getRight()->getValue() == value) {
					nodeToDelete = iterator->getRight();
					// when node is found - link elements to the and to the right of it
					iterator->setRight(iterator->getRight()->getRight());
					break;
				}
				else {
					iterator = iterator->getRight();
				}
			}
			if (iterator->getValue() == value) {
				nodeToDelete = iterator;;
			}
		}
		// delete all nodes in the chain
		while (nodeToDelete->belowExist()) {
			Node* temp = nodeToDelete->getBelow();
			delete nodeToDelete;
			nodeToDelete = temp;
		}
		// and delete top node
		delete nodeToDelete;
		std::cout << " Value(s) successfully deleted!\n";
		return true;
	}
}

// printList: Prints the List
void SkipList::printList() {
	// if list is empty - prompt and exit
	if (head == NULL)
		std::cout << " Sorry! The list is empty!\n";
	else {
		// if not - iterate over the nodes
		Node* iterRight = head;
		do {
			Node* iterBelow = iterRight;
			// for every node iterate over it elements and print them
			do {
				std::cout << iterBelow->getValue() << " \t";
				if (iterBelow->belowExist())
					iterBelow = iterBelow->getBelow();
				else
					break;
			} while (true);
			std::cout << std::endl;
			if (iterRight->rightExist())
				iterRight = iterRight->getRight();
			else 
				break;
		} while (true);
	}
}