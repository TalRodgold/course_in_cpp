//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 9 question 1
//this program implements a tree

#pragma once
#include <iostream>
#include "Queue.h"
#include "QueueVector.h"
using namespace std;

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }
	int height() { return height(root); } //func for hight of tree
	void reflect() { reflect(root); } // func to reflect tree
	void PrintLevel() { QueueVector<T> Q; int level; PrintLevel(root, Q, level); } // func to print level
	void breadthScan(); // func for vertical scan


	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;


private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);
	int height(Node*); //func for hight of tree
	void reflect(Node*); // func to reflect tree
	void PrintLevel(Node* , QueueVector<T>& , int); // func to print level
};



//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

template<class T>
int Tree<T>::height(Node* high) //func for hight of tree
{
	if (high == NULL)
		return -1;
	return max(height(high->left), height(high->right)) + 1;
}

template<class T>
void Tree<T>::reflect(Node* ref) // func to reflect tree
{
	if (ref == NULL)
		return;
	swap(ref->left, ref->right); // swap
	reflect(ref->left); // go left
	reflect(ref->right); // go rigth
}

template<class T>
void Tree<T>::breadthScan() // func for vertical scan
{
	QueueVector<T> tempQ(20);
	for (int i = 1; i <= height() + 1; i++) // scan
		PrintLevel(root, tempQ, i);
}

template<class T>
void Tree<T>::PrintLevel(Node* current, QueueVector<T>& Q, int level) // func to print level
{
	if (current == NULL)
		return;
	if (level == 1)
		Q.enqueue(current->value);
	else
	{
		PrintLevel(current->left, Q, level - 1);
		PrintLevel(current->right, Q, level - 1);
	}
	while (!Q.isEmpty())
		cout << Q.dequeue() << " ";
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}


