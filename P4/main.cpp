/********************************************************************
 ** NAME:  Srizan Gangol         		USERID:sg0440	           	**
 ** ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  main.cpp											**
 ** Project: Naive Process Scheduler	Program: 4 		          	**
 ** 																**
 ********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include"heap.h"

// Greetings Function
void greetings();
using namespace std;
int main()
{
	Heap * tree = new Heap;
	bool type = true;				// type of Heap, true by priority value, false by runtime
	char choice;
	
	greetings();
	
	cout << " Please enter the filename to import the data from>";
	string s;
	cin >> s;
	
	// Import file
	ifstream f(s.c_str()); 
	
	// IF failed to open the file
	while (!f.is_open()) { 
	cout << " Sorry! Unable to open file!\n"; 
	cout << " Please re-enter correct filename> "; 
	cin >> s; f.open(s.c_str()); }
	
	int value, time;
	char comma;
	
	while (f >> value)
	{
		f >> comma;
		f >> time;
		process * s = newprocess(value, time);
		Node * n = newNode();
		n->setData(s);
		tree->addNode(n,type);
	}
	f.close();
	cout << " Data read!\n";
	
	// Main Menu Heading
	cout << "\n###########    MAIN MENU     ###########\n"; 
	cout << " Please select the option [ ] below \n\n";
	
	
	while (1)
	{
		// Main Menu
				
		cout << " [P] Print the list of process\n";
		cout << " [R] Runtime Sort\n";
		cout << " [V] Priority Value Sort \n";
		cout << " [A] Add new process\n";
		cout << " [Q] Quit the program\n";
		cout << " CSCE2100>";
		cin >> choice;
		
		
		if (choice == 'P')
		{
			// Prints the current Tree as imported
			tree->print(type);
		} else
		if (choice == 'R')
		{
			// Sorts & Prints by duration of process
			type = 0;
			tree->sortTime();
			cout << " Tree sorted by Runtimes:\n";
			tree->print(type);
		}
		else
		if (choice == 'V')
		{
			// Sorts & Prints by Priority Value
			type = 1;
			tree->sortPri();
			cout << " Tree sorted by priority value: \n";
			tree->print(type);
		}
		else
		if (choice == 'A')
		{
			// Add new process
			int value, time;
			cout << " Please enter priority value of process: ";
			cin >> value;
			cout << " Please enter Duration of the process: ";
			cin >> time;
			process * s = newprocess(value, time);
			Node * n = newNode();
			n->setData(s);
			tree->addNode(n, type);
		}
		
		else
		if (choice == 'Q')
		{
			cout << " \n\n\n\n Thank you for using Naive Process Scheduler. Have a good day! \n\n\n\n\n\n";
			return 0;
		}
		else
		{
			cout << " \n\n ####Sorry! I could not recognize that Menu, please try again!#### \n\n" ;
		}
	}
	//system("pause");
}


// Greetings Function
void greetings()
{
	cout << "\n \n";
	cout << "+---------------------------------------------------------+" << endl;
	cout << "|              Computer Science and Engineering           |" << endl;
	cout << "|              CSCE 2100 - Computer Foundations I         |" << endl;
	cout << "|   Srizan Gangol     ID: sg0440      srizan@gmail.com    |" << endl;
	cout << "|   Program: Naive Process Scheduler | Program 4          |" << endl;
	cout << "+---------------------------------------------------------+" << endl << endl;
	
	cout << "+---------------------------------------------------------+" << endl;
	cout << "|          Welcome to Naive Process Scheduler             |" << endl;
	cout << "|                         in C++                          |" << endl;
	cout << "+---------------------------------------------------------+" << endl << endl;
	

	cout << " NOTE: \tThis heap will be deleted after EACH Print/Sort\n"	;	
	cout << " Note: \tMenu only accepts UPPERCASE \n\n";

}