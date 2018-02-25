/********************************************************************
 **        NAME:  Srizan Gangol         USERID:sg0440	           	**
 **  ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  Main.CPP				Project-2: SkipList		   	**
 **         														**
 ********************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>		// ran
#include <time.h>		//srand

// Program Headers
#include "SkipList.h"
#include "SkipListString.h"


using namespace std; 


// getNumber: Validates User Input for number
int getNumber()
{
	int number = 0;
	while (true) {
		cin >> number;
		// if input is not a number - clear input and try again
		if (!cin) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << " Sorry!! it`s not a number!! Please, Try again!\n>> ";
		}
		else break;
	}
	return number;
}

// mainMenu: Prints MainMenu & Executes functionality of the menu
bool mainMenu(SkipList* mySkipList, SkipListString* mySkipListString, bool mode) {
	int usersChoice = 0;
	int usersNumber = 0;
	string usersString = "";
	while (true) {
		if (mode)
			cout << "\t\tWelcome to the main menu!\n\t\tThis is skip list for integers.\n\n";
		else
			cout << "\t\tWelcome to the main menu!\n\t\tThis is skip list for strings.\n\n";
		cout << " 1. Add an element\n 2. Find an element\n 3. Delete an element\n";
		cout << " 4. Print the skip-list\n 5. Change mode[String <-> Integer]\n 6. Exit\n\n CSCE2100> ";
		// get users choice 
		usersChoice = getNumber();
		// proceed users choice
		switch (usersChoice)
		{
		case 1:
			// choose correct function for each mode
			if (mode) {
				cout << " Please enter the number to add:\n>> ";
				usersNumber = getNumber();
				mySkipList->addElement(usersNumber);
			}
			else {
				cout << " Please enter the word(string) to add:\n>> ";
				getline(cin, usersString);
				getline(cin, usersString);
				mySkipListString->addElement(usersString);
			}
			break;
		case 2:
			// choose correct function for each mode
			if (mode) {
				cout << " Please enter the number to search:\n>> ";
				usersNumber = getNumber();
				mySkipList->findElement(usersNumber);
			}
			else {
				cout << " Please enter the word to search:\n>> ";
				getline(cin, usersString);
				getline(cin, usersString);
				mySkipListString->findElement(usersString);
			}
			break;
		case 3:
			// choose correct function for each mode
			if (mode) {
				cout << " Please enter the number to delete:\n>> ";
				usersNumber = getNumber();
				mySkipList->deleteElement(usersNumber);
			}
			else {
				cout << " Please enter the word (string) to delete:\n>> ";
				getline(cin, usersString);
				getline(cin, usersString);
				mySkipListString->deleteElement(usersString);
			}
			break;
		case 4:
			// choose correct function for each mode
			if (mode) {
				cout << "\t\tSKIP LIST INTEGER\n\n";
				mySkipList->printList();
			}
			else {
				cout << "\t\tSKIP LIST STRING\n\n";
				mySkipListString->printList();
			}
			break;
		case 5:
			cout << " Changing mode!\n";
			return true;
		case 6:
			cout << " Thank you using this program, GoodBye!\n\n\n\n\n";
			return false;
		default:
			cout << " Invalid command! Please try again...\n>> ";
			break;
		}
	}
}

// enterScreen: Mode Change
void enterScreen(SkipList* mySkipList, SkipListString* mySkipListString) {
	bool mode = true;
	bool changeMode = true;
	while (changeMode) {
		changeMode = mainMenu(mySkipList, mySkipListString, mode);
		if (changeMode) {
			mode = !mode;
			cout << " Mode changed![String <-> Integer]\n\n";
		}
	}
}

// greetings: Prints out Greetings at the beginning of the program
void greetings()
{
	cout << "\n \n";
	cout << "+---------------------------------------------------------+" << endl;
	cout << "|              Computer Science and Engineering           |" << endl;
	cout << "|              CSCE 2100 - Computer Foundations I         |" << endl;
	cout << "|   Srizan Gangol     ID: sg0440      srizan@gmail.com    |" << endl;
	cout << "|   Program: Program 2- Skip List [Integer<->String]      |" << endl;
	cout << "+---------------------------------------------------------+" << endl << endl;
}

int main()
{
	greetings();
	srand(time(NULL));
	SkipList* mySkipList = new SkipList();
	SkipListString* mySkipListString = new SkipListString();
	enterScreen(mySkipList, mySkipListString);
	return 0;
}