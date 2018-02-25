/********************************************************************
 ** NAME:  Srizan Gangol         		USERID:sg0440	           	**
 ** ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  process.h											**
 ** Project: Naive Process Scheduler	Program: 4 		          	**
 ** 																**
 ********************************************************************/

class process
{
	int value; 				// Priority value
	int runtime; 			// Duration of process
public:
	process(); 				// Constructor
	process(int v,int t); 	// Constructor
	~process(); 			// Destructor
	int getValue(); 		// Get value
	int getRuntime(); 		// Get time
	void setValue(int v); 
	void setRuntime(int t);
};

process * newprocess(int v, int t);