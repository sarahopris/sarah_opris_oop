#pragma once
#include "Node.h"
#include <algorithm>

class Tree
{
private:
	Node* left;
	Node* right;
	Node* root;

public:
	Tree();
	Tree(Node* root, Node* left, Node* right);
	~Tree();

	//Die Methoden
	void insert(int data);
	

};