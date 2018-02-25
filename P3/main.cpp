/********************************************************************
 ** NAME:  Srizan Gangol         		USERID:sg0440	           	**
 ** ASSIGNMENT:  CSCE2100		  				                  	**
 ** Project: Binary Search Tree							          	**
 ** 																**
 ********************************************************************/
# include <iostream>
# include <cstdlib>
#include "BST.h"

using namespace std;

int main()

{

	int choice, num;

	BST bst;

	Node *temp;

	while (1)

	{

		cout << "-----------------" << endl;

		cout << "Operations on BST" << endl;

		cout << "-----------------" << endl;

		cout << "1.Add Element " << endl;

		cout << "2.Remove Element " << endl;

		cout << "3.Print tree" << endl;

		cout << "4.Quit" << endl;

		cout << "Enter your choice : ";

		cin >> choice;

		switch (choice)

		{
			int val;
		case 1:
		{
			temp = new Node;

			cout << "Enter the number to be inserted : ";

			cin >> val;
			temp->setData(val);

			bst.addElement(bst.getRoot(), temp);

		}
		break;
		case 2:
		{

			if (bst.getRoot() == NULL)

			{

				cout << "Tree is empty, nothing to delete" << endl;

				continue;

			}

			cout << "Enter the number to be deleted : ";
			cin >> val;

			bst.removeElement(val);

		}
			break;

		case 3:
		{
			cout << "Display BST:" << endl;

			bst.printTree(bst.getRoot(), 1);

			cout << endl;


		}
			break;

		case 4:
		{
			exit(1);

		}
		break;
		default:
		{
			cout << "Wrong choice" << endl;

		}
		break;
			
		}

	}

}

