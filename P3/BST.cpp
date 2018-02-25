/********************************************************************
 ** NAME:  Srizan Gangol         		USERID:sg0440	           	**
 ** ASSIGNMENT:  CSCE2100		  				                  	**
 ** Project: Binary Search Tree							          	**
 ** 																**
 ********************************************************************/
 
#include "BST.h"

BST::BST()
{
	root = NULL;
}


BST::~BST()
{
}


void BST::addElement(Node *tree, Node *newnode)

{

	if (root == NULL)

	{

		root = new Node;

		root->setData(newnode->getData());

		root->left = NULL;

		root->right = NULL;

		cout << "Root Node is Added" << endl;

		return;

	}

	if (tree->getData() == newnode->getData())

	{

		cout << "Element already in the tree" << endl;

		return;

	}

	if (tree->getData() > newnode->getData())

	{

		if (tree->left != NULL)

		{

			addElement(tree->left, newnode);

		}

		else

		{

			tree->left = newnode;

			(tree->left)->left = NULL;

			(tree->left)->right = NULL;

			cout << "Node Added To Left" << endl;

			return;

		}

	}

	else

	{

		if (tree->right != NULL)

		{

			addElement(tree->right, newnode);

		}

		else

		{

			tree->right = newnode;

			(tree->right)->left = NULL;

			(tree->right)->right = NULL;

			cout << "Node Added To Right" << endl;

			return;

		}

	}

}


void BST::findElement(int item, Node **par, Node **loc)
{

	Node *ptr, *ptrsave;

	if (root == NULL)

	{

		*loc = NULL;

		*par = NULL;

		return;

	}

	if (item == root->getData())

	{

		*loc = root;

		*par = NULL;

		return;

	}

	if (item < root->getData())

		ptr = root->left;

	else

		ptr = root->right;

	ptrsave = root;

	while (ptr != NULL)

	{

		if (item == ptr->getData())

		{

			*loc = ptr;

			*par = ptrsave;

			return;

		}

		ptrsave = ptr;

		if (item < ptr->getData())

			ptr = ptr->left;

		else

			ptr = ptr->right;

	}

	*loc = NULL;

	*par = ptrsave;

}

void BST::removeElement(int item)

{

	Node *parent, *location;

	if (root == NULL)

	{

		cout << "Tree empty" << endl;

		return;

	}

	findElement(item, &parent, &location);

	if (location == NULL)

	{

		cout << "Item not present in tree" << endl;

		return;

	}

	if (location->left == NULL && location->right == NULL)

		case_a(parent, location);

	if (location->left != NULL && location->right == NULL)

		case_b(parent, location);

	if (location->left == NULL && location->right != NULL)

		case_b(parent, location);

	if (location->left != NULL && location->right != NULL)

		case_c(parent, location);

	//free(location);

}

void BST::case_a(Node *par, Node *loc)

{

	if (par == NULL)

	{

		root = NULL;

	}

	else

	{

		if (loc == par->left)

			par->left = NULL;

		else

			par->right = NULL;

	}

}

void BST::case_b(Node *par, Node *loc)

{

	Node *child;

	if (loc->left != NULL)

		child = loc->left;

	else

		child = loc->right;

	if (par == NULL)

	{

		root = child;

	}

	else

	{

		if (loc == par->left)

			par->left = child;

		else

			par->right = child;

	}

}

void BST::case_c(Node *par, Node *loc)

{

	Node *ptr, *ptrsave, *suc, *parsuc;

	ptrsave = loc;

	ptr = loc->right;

	while (ptr->left != NULL)

	{

		ptrsave = ptr;

		ptr = ptr->left;

	}

	suc = ptr;

	parsuc = ptrsave;

	if (suc->left == NULL && suc->right == NULL)

		case_a(parsuc, suc);

	else

		case_b(parsuc, suc);

	if (par == NULL)

	{

		root = suc;

	}

	else

	{

		if (loc == par->left)

			par->left = suc;

		else

			par->right = suc;

	}

	suc->left = loc->left;

	suc->right = loc->right;

}


void BST::printTree(Node *ptr, int level)
{

	int i;

	if (ptr != NULL)

	{

		printTree(ptr->right, level + 1);

		cout << endl;

		if (ptr == root)

			cout << "Root->:  ";

		else

		{

			for (i = 0; i < level; i++)

				cout << "       ";

		}

		cout << ptr->getData();

		printTree(ptr->left, level + 1);

	}

}
