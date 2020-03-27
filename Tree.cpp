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
//
void Tree::remove(int a)
{
	//Locate the element
	bool found = false;
	if (root == nullptr)
	{
		cout << " This Tree is empty! " << endl;
		return;
	}

	Node* current;
	Node* parent;
	current = root;
	parent = nullptr;

	while (current != nullptr)
	{
		if (current->val == a)
		{
			found = true;
			break;
		}
		else
		{
			parent = current;
			if (a > current->val)
				current = current->right;
			else
				current = current->left;
		}
	}
	if (found == 0)
	{
		cout << " Data not found! " << endl;
		return;
	}
/*se intalnesc 3 cazuri in operatia de stergere a unui nod:
   1 - se sterge nodul frunza (nodul fara fii)
   2 - se sterge nodul cu un singur fiu 
   3 - se sterge nodul cu 2 fii*/
		
	 //Node mit einem einziger Kind 
		if ((current->left == nullptr && current->right != nullptr) || (current->left != nullptr && current->right == nullptr))
		{
			if (current->left == nullptr && current->right != nullptr)
			{
				if (parent->left == current)
				{
					parent->left = current->right;
					delete current;
				}
				else
				{
					parent->right = current->right;
					delete current;
				}
			}
			else // es gibt ein linkes Kind , aber kein rechtes Kind
			{
				if (parent->left == current)
				{
					parent->left = current->left;
					delete current;
				}
				else
				{
					parent->right = current->left;
					delete current;
				}
			}
			return;
		}

		//leaf Node 
		if (current->left == nullptr && current->right == nullptr)
		{
			if (parent->left == current)
				parent->left = nullptr;
			else parent->right = nullptr;
			delete current;
			return;
		}

		//Node mit 2 Kinder
		//replace node with smallest value in right subtree
		if (current->left != nullptr && current->right != nullptr)
		{
			Node* aux;
			aux = current->right;
			if ((aux->left == nullptr) && (aux->right == nullptr))
			{
				current = aux;
				delete aux;
				current->right = nullptr;
			}
			else // Rechtes Kind hat Kinder
			{
				//wenn das rechte Kind des Knotens ein linkes Kind hat
// gehe ganz nach links, um das kleinste Element zu finden

				if ((current->right)->left != nullptr)
				{
					Node* elem; // elem(valoarea curenta din partea stanga)
					Node* elempos; // 
					elempos = current->right;
					elem = (current->right)->left;
					while (elem->left != nullptr)
					{
						elempos = elem;
						elem = elem->left;
					}
					current->val = elem->val;
					delete elem;
					elempos->left = nullptr;
				}
				else
				{
					Node* b; // b = valoarea din dreapta pe care o sterg
					b = current->right;
					current->val = b->val;
					current->right = b->right;
					delete b;
				}

			}
			return;
		}
}

/* Die Inorder-Funktion:
1 - uberpruft, ob der aktuelle Knoten leer oder null ist.
2. Durchlauft den linken subtree, indem die Funktion in der Reihenfolge rekursiv aufgerufen wird.
3. Zeigt den data part des roots (oder des aktuellen Knotens) an.
4. Durchlauft den rechten subtree, indem die Funktion in der Reihenfolge  rekursiv aufgerufen wird */
void Tree::print_inorder()
{
	inorder(root);
}


void Tree::inorder(Node* p)
{
	if (p != nullptr)
	{
		if (p->left) inorder(p->left);
		cout << " " << p->val << " ";
		if (p->right) inorder(p->right);
	}
	else
		return;
}

/* Die preorder Funktion:
1. uberprufen Sie, ob der aktuelle Knoten leer oder null ist.
2. zeigen Sie den Datenteil des  (oder des aktuellen Knotens) an.
3. durchlaufen Sie den linken subtree, indem Sie die preorder Funktion rekursiv aufrufen.
4. durchlaufen Sie den rechten subtree, indem Sie die preorder Funktion rekursiv aufrufen. */

void Tree::print_preorder()
{
	preorder(root);
}

void Tree::preorder(Node* p)
{
	if (p != nullptr)
	{
		cout << " " << p->val << " ";
		if (p->left) preorder(p->left);
		if (p->right) preorder(p->right);
	}
	else
		return;
}

/* Die postorder function:
1. uberprufen Sie, ob der aktuelle Knoten leer oder null ist.
2. durchlaufen Sie den linken subtree, indem Sie die postorder Funktion rekursiv aufrufen.
3. durchlaufen Sie den rechten subtree, indem Sie die postorder Funktion rekursiv aufrufen.
4. zeigen Sie den data part of the root (oder des aktuellen Knotens) an. */

void Tree::print_postorder()
{
	postorder(root);
}

void Tree::postorder(Node* p)
{
	if (p != nullptr)
	{
		if (p->left) postorder(p->left);
		if (p->right) postorder(p->right);
		cout << " " << p->val << " ";
	}
	else
		return;
}

/*
This function counts, how many nodes are in the tree.
*/

int Tree::countNodes(Node* p)
{
	int count = 1;
	if (p == nullptr)
		return 0;
	else
	{
		count += countNodes(p->left);
		count += countNodes(p->right);
	}
	return count;
}

int Tree::countNodes()
{
	return countNodes(root);
}

/*
This function counts, how many edges are in the tree.
*/

int Tree::countEdges(Node* n)
{
	if (n == nullptr)
		return 0;
	else
		return countNodes() - 1;
}

int Tree::countEdges()
{
	return countEdges(root);
}

/*
The function, which shows the height of a tree.
*/

int Tree::treeHeight(Node* p)
{
	if (p == nullptr)
	{
		return -1;
	}
	int left = treeHeight(p->left);
	int right = treeHeight(p->right);
	return (1 + std::max(left, right));
}

int Tree::treeHeight()
{
	return treeHeight(root);
}

