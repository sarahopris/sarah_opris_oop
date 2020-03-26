#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree()
{
	root = nullptr;
	left = nullptr;
	right = nullptr;
}
Tree::Tree(Node* root, Node* left, Node* right)
{
	this->root = root;
	this->left = left;
	this->right = right;
}

//Destructor
Tree::~Tree()
{

}

//Eine Methode zum Einfugen eines neuen Wertes in einen Binare Suchbaum
void Tree::insert(int data)
{
	Node *temp = new Node;
	Node* parent;
	temp->val = data;
	temp->right = nullptr;
	temp->left = nullptr;
	parent = nullptr;
	if (root == 0)
	{
		root = temp;
	}
	else
	{
		Node* current;
		current = root;
		while (current != 0)
		{
			parent = current;
			if (temp->val > current->val)
				current = current->right;
			else
				current = current->left;
		}
		if (temp->val < parent->val)
			parent->left = temp;
		else
			parent->right = temp;
	}
}