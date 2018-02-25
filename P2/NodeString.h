/********************************************************************
 **        NAME:  Srizan Gangol         USERID:sg0440	           	**
 **  ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  NodeString.H			Project-2: SkipList		   	**
 **         														**
 ********************************************************************/

#pragma once
// class which represents a std::string in the list
class NodeString
{
private:
	// number and next values
	std::string value;
	NodeString* right;
	NodeString* below;

public:
	// default and non-default constructors and destructor
	NodeString();

	NodeString(std::string value);

	~NodeString();
	// getters
	std::string getValue();

	NodeString* getRight();

	NodeString* getBelow();
	// setters
	void setRight(NodeString* right);

	void setBelow(NodeString* below);
	// functions to check is there an element on the right or below, or not
	bool rightExist();

	bool belowExist();
};