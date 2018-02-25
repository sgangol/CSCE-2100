/*********************************************************************
 **        NAME:  Srizan Gangol							           	**
 **  ASSIGNMENT:  CSCE2100		  				                  	**
*********************************************************************/ 
#include <iostream>
#include <cstddef>
#include <cassert>


// NodePtr
class node{
	public: 
		char input;		// Inputs Char
		int counter;
		node *next;	
		node *previous;	// the link pointer to next item
}; 


typedef node* NodePtr;

// Function Prototype Starts here
using namespace std;
// Declaring Global Variables
int choice;
char input;		// input WILL FEED IN VALUE TO ADD

node *head= NULL;
node *tail= NULL;

//@@ADDED CURRENT NODE
node *current= NULL;



// Actual bread & butter of this program


// ======================================================== //
// ================= Function Prototype  ================== //
// ======================================================== //


void greetings ();
void append(node *&head, char input);
void insertAt(node *&head, char input, int position);
void remove(node *&head, char input);
void removeAt(node *&head, int position);
bool search(node *&head, char input);
void print (node *current);
void quit();

bool isEmpty(node *head);
void insertAsFirstElement(node *&head, char input);




// ======================================================== //
// ================= Function Defination ================== //
// ======================================================== //





// Insert 
void append(node *&head, char input)
{
	node *temp;
		if(isEmpty(head))
			insertAsFirstElement(head,input);
		else 
		{  			
			node *it = head;
			while (it->next != NULL) 
					it = it-> next;
			//@@ If the above loop has finished, either the next node is smaller
			//@@ or there is no next node. In either case, insert before *it
			//@@ I am not to sure about this code being correct (TODO)
			temp =new node;
			temp->input=input;
			temp->counter++;
			temp->next=it->next;
			
			//@@ If *it was not the last node (i.e. it->next was not null), connect the prev
			if (it->next) it->next->previous = temp;

			/*@@ TAIL LOGIC WAS NEVER USED ... IGNORE THIS PART
			else {
					//@@ SEEMS TO HAVE BEEN TAIL .. LETS MARK IT
					tail = it;
			}
			*/
			//@@ In any case, temp was inserted after *it, so connect it's prev
			temp->previous = it;

			it->next=temp;
			
			   
		}
		cout << " ADDED: " << input << " \n";
		//@@ Update current pointer to the freshly inserted node
		current = temp;
}

// Remove 
void remove(node *&head, char input)
{
	if (isEmpty(head))
		cout << " The list is already empty. \n";
	else 
	{
		if (!search(head, input))
		{
			cout << " ERROR: Not found for Removal: " << input <<" \n";
			return;
		}

		if (head->input == input)
		{
			node *temp = head->next;
			//@@ CHECK IF current was at head
			if (current == head){
				//@@ Lets say that deletion moves current to the next (right node)
				if (head->next) current = head->next;
				else current = NULL;
			}

			delete head;

			head = temp;
			//@@ Fix temp previous (now being head has no previous)
			head->previous = NULL;
		}
		else
		{
			node *it = head;
			while (it->next != NULL && it->next->input < input)
					it = it->next;
			//@@ If we are here, temp (i.e. *it->next **MAY** matche deletion criteria

			if (it->next->input == input){
				//@@ IT MATCHES ...
				//@@ LETS CHECK CURRENT
				if (current == it->next){
						//@@ MATCHES ...
						if (current->next) current = current->next;
						else current = current->previous; //@@ IT WAS TAIL ...
				}
				node *temp = it->next;

				//@@ Connect the node after the one to be deleted to the one before it
				//@@ If it is not the last node!
				if (temp->next) temp->next->previous = it;

				it->next = temp->next;
				delete temp;
			}
		}
		cout << " Removal successful: " << input <<" \n";		    
	}
}

// Function QUIT: Quits the Program after printing out Thank you message
void insertAt(node *&head, char input, int position)
{
	node *it = head;
	int halfLife, maxNo=0;
	while (it != NULL)
	{
		it = it->next;
		maxNo++;
	}
	
	if (position <= maxNo) 				// Validates where position is legit
	{
		if ((maxNo-position)<(maxNo/2))	// Checks if it faster to start from head
		{
			node *it = head;
			while (it != NULL)
			{
				if (it->next-> counter == position)
				{
					
				}
				
				it = it->next;
			}
			
		}
		//else ()							// Runs if it is faster to start from tail
		{
			
		}
	
	
	}	
		
	
	
	
}
void removeAt(node *&head, int position)
{
	if (isEmpty(head))
		cout << " The list is already empty. \n";
	else 
	{
		if (!search(head, input))
		{
			cout << " ERROR: Not found for Removal: " << input <<" \n";
			return;
		}
	
	
	/*	
		if (head->input == input)
		{
			node *temp = head->next;
			//@@ CHECK IF current was at head
			if (current == head){
				//@@ Lets say that deletion moves current to the next (right node)
				if (head->next) current = head->next;
				else current = NULL;
			}

			delete head;

			head = temp;
			//@@ Fix temp previous (now being head has no previous)
			head->previous = NULL;
		}
		else
		{
			node *it = head;
			while (it->next != NULL && it->next->input < input)
					it = it->next;
			//@@ If we are here, temp (i.e. *it->next **MAY** matche deletion criteria

			if (it->next->input == input){
				//@@ IT MATCHES ...
				//@@ LETS CHECK CURRENT
				if (current == it->next){
						//@@ MATCHES ...
						if (current->next) current = current->next;
						else current = current->previous; //@@ IT WAS TAIL ...
				}
				node *temp = it->next;

				//@@ Connect the node after the one to be deleted to the one before it
				//@@ If it is not the last node!
				if (temp->next) temp->next->previous = it;

				it->next = temp->next;
				delete temp;
			}
		}*/
		cout << " Removal successful: " << input <<" \n";		    
	}	;
	
}


// SEARCH: Searches through Linked list
bool search(node *&head, char input)
{
	node *it = head;
	while (it != NULL)
	{
		if (it->input == input)
				return true;
		it = it->next;
	}
	return false;
}
// Verifying Character
bool verifychar(char input)
{
	if ( ((int)input<65)||((int)input>122))
		return false;
	else 
		return true;
	
}
// PRINT
// Print the Linked-list
void print (node *head)
{
		node *current = head;
		if (isEmpty(current))
		{
				cout << "\n LIST IS EMPTY \n";
		}
		else
		{
			//@@ I have uncommented this line, since I want to print the list both ways
			//@@ To ensure that the doubly linked list works. Please cleanup after my mess. Thank you.
			cout << " The list contains: \n";
			while(current != NULL)
			{
					cout << "\t" << current->input << endl;
					current = current->next;
			}

			//@@ Lets have some fun ...
			cout << "Printing backwards: \n";
			current = head;
			while(current->next) current = current->next;
			//@@ Now current should be the tail node ... just confirming your code - don't take it personally
			//@@ Lets print backwards ...
			while (current) {
					cout << "\t" << current->input << endl;
					current = current->previous;
			}
			cout << "Done! Good job!! \n";

		}
}


// QUIT: Simply quits program!
void quit()
{
	cout << "\n Thank you for using this Program \n";
	cout << " Exiting the program \n\n GOODBYE! \n";

}

// ======================================================== //
// ============ Other Function Defination  ================ //
// ======================================================== //

//** NOT MANDATORY **//

// Function Greetings: Prints greetings, Menu & Instruction
void greetings()
{
	cout << "\n \n";
	cout << "+---------------------------------------------------------+" << endl;
	cout << "|              Computer Science and Engineering           |" << endl;
	cout << "|              CSCE 2100 - Computer Foundations I         |" << endl;
	cout << "|   Srizan Gangol     ID: sg0440      srizan@gmail.com    |" << endl;
	cout << "|   Program: Double Linked List [Character]               |" << endl;
	cout << "+---------------------------------------------------------+" << endl;

	cout << "\n>>> INSTRUCTION \n \n";

	cout << "1 > APPEND \n";
	cout << "2 > INSERTAT \n";
	cout << "3 > REMOVE \n";
	cout << "4 > REMOVEAT \n";
	cout << "5 > SEARCH \n";
	cout << "6 > PRINT \n";
	cout << "7 > QUIT \n";
	
	cout << "\n INSTRUCTION: \n To use this program, Choose the input of the <function> from table above hit <space> \n and type in the <character> or/and <input> seperated by space when applicable \n";
}
// If head is empty
bool isEmpty(node *head)
{
		if(head == NULL)
				return true;
		else
				return false;
}

// Insert as the First Element
void insertAsFirstElement(node *&head, char input)
{
		node *temp =new node;		// Creating New Pointer Temp which points to NEW NODE
		temp->input=input;			// ASSIGNS TEMP TO THE INPUT input
		temp->counter=1;
		temp->next=NULL;			// ASSIGNS TEMP TO NEXT PINTER TO NULL
		temp->previous=NULL;		//@@ Assign previous pointer null value
		head = temp;				// MAKES HEAD POINT TO THE TEMP
		current = head;				//@@ MAKE THE CURRENT NODE THE HEAD
}

