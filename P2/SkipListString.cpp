/********************************************************************
 **        NAME:  Srizan Gangol         USERID:sg0440	           	**
 **  ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  SkipListString.CPP	Project-2: SkipList		   	**
 **         														**
 ********************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "NodeString.h"
#include "SkipListString.h"

SkipListString::SkipListString() {
	head = NULL;
}

// SkipList: Randomizing the SkipList (Level)
bool SkipListString::coinFlip() {
	// 50% chances of returning Head or Tail
	if (rand() % 2 == 0)
		return false;
	return true;
}

// addElement: Adding value
bool SkipListString::addElement(std::string value) {
	// create temporary NodeStrings
	NodeString* temp = new NodeString(value);
	NodeString* levelsadder = new NodeString(value);
	// if list is empty - create a head NodeString
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
			// if not - find a place for a new NodeString
			NodeString* iterator = head;
			while (iterator->rightExist()) {
				// if value is already in the list - exit with a prompt
				if (iterator->getValue() == value) {
					std::cout << "Value already presented!\n";
					return false;
				}
				// stop when next NodeString has greater value
				if (iterator->getRight()->getValue() > value)
					break;
				// while proper position isn`t found - iterate over the list
				iterator = iterator->getRight();
			}
			// if position for the NodeString is in the middle of the list - move the NodeStrings right to it
			if (iterator->rightExist())
				temp->setRight(iterator->getRight());
			// insert new NodeString
			iterator->setRight(temp);
		}
		// start leveling
		levelsadder = temp;
	}
	// create a chain of elements using random
	while (coinFlip()) {
		levelsadder->setBelow(new NodeString(value));
		levelsadder = levelsadder->getBelow();
	}
	std::cout << "Value(s) successfully added!\n";
	return true;
}

// findElement: Searches for the value
bool SkipListString::findElement(std::string value) {
	// variable for result
	bool valueFound = false;
	// if list is empty
	if (head == NULL) {
		std::cout << " Sorry! Value is not presented in the list!\n";
		return valueFound;
	}
	// if not - start iterating over it
	NodeString* iterator = head;
	while (true) {
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
		std::cout << " Value is presented in list!\n";
	else
		std::cout << " Value is not presented in list!\n";
	return valueFound;
}

// deleteElement: Deletes Element
bool SkipListString::deleteElement(std::string value) {
	// if there is no such element
	if (!findElement(value)) {
		std::cout << " Sorry! Can`t delete nonexistent node!\n";
		return false;
	}
	else {
		NodeString* NodeStringToDelete = NULL;
		NodeString* iterator = NULL;
		// check if head is a NodeString to delete
		if (head->getValue() == value) {
			NodeStringToDelete = head;
			head = head->getRight();
		}
		else {
			iterator = head;
			// if not - iterate over the list to find it
			while (iterator->rightExist()) {
				// if NodeString is found
				if (iterator->getRight()->getValue() == value) {
					NodeStringToDelete = iterator->getRight();
					// when NodeString is found - link elements to the and to the right of it
					iterator->setRight(iterator->getRight()->getRight());
					break;
				}
				else {
					iterator = iterator->getRight();
				}
			}
			if (iterator->getValue() == value) {
				NodeStringToDelete = iterator;;
			}
		}
		// delete all NodeStrings in the chain
		while (NodeStringToDelete->belowExist()) {
			NodeString* temp = NodeStringToDelete->getBelow();
			delete NodeStringToDelete;
			NodeStringToDelete = temp;
		}
		// and delete top NodeString
		delete NodeStringToDelete;
		std::cout << " Value(s) successfully deleted!\n";
		return true;
	}
}

// printList: Prints the List
void SkipListString::printList() {
	// if list is empty - prompt and exit
	if (head == NULL)
		std::cout << " Sorry! The list is empty!\n";
	else {
		// if not - iterate over the NodeStrings
		NodeString* iterRight = head;
		do {
			NodeString* iterBelow = iterRight;
			// for every NodeString iterate over it elements and prstringthem
			do {
				std::cout << iterBelow->getValue() << " \t\t\t";
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