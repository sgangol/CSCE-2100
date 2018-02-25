/*********************************************************************
 **        NAME:  Srizan Gangol							           	**
 **  ASSIGNMENT:  CSCE2100		  				                  	**
*********************************************************************/ 
 
#include <iostream>
#include <cstddef>
#include <cassert>

#include "node.h"	
using namespace std;

int main ()
{
	
	greetings ();
	LOOP:do 
	{
		cout << "\n CSCE2100> ";
		cin >> choice;

		// ** Append
		if (choice==1)
		{
			cin >> input;
			append(head, input);
		}	
		
		// ** InsertAt
		if (choice==2)
		{
			int number;
			cin >> input;
			cin >> number;
			insertAt(head, input, number);
		}	
		
		// ** REMOVE
		if (choice==3)
		{	
			cin >> input;
			remove(head, input);
		}
		
		// ** REMOVEAT
		if (choice==4)
		{	
			int number;
			cin >> input;
			cin >> number;
			removeAt(head, number);
		}
		// ** SEARCH
		if (choice==5)
		{
			cin >> input;
			if (search(head, input))		    
				cout << " TRUE: " << input << endl;
			else
				cout << " FALSE: " << input << endl;
		}	


		// ** PRINT
		if (choice==6)
		{
			print(head);
		}	
		
		// ** QUIT
		if (choice==7)
		{
			quit();
		}	
		
		
		else if ((choice<1)||(choice>7))
		{
			cout << " >>> ERROR!! Invalid Input \n";
			break;	
		}

	
	}while(choice!=7);
	return 0;
}
