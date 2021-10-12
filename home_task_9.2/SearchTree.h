//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 9 question 2
//this program holds a database of books and allows user to change database
#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value);
	void remove(T val);
	T successor(T val);
	void deleteDuplicates() { deleteDuplicates(Tree<T>::root); }  // calling the private function
	bool  search(T value)
	{
		return search(Tree<T>::root, value);
	}
private:
	void add(typename Tree<T>::Node* current, T val);
	void remove(typename Tree<T>::Node* current);
	bool  search(typename Tree<T>::Node* current, T val);
	T successor(typename Tree<T>::Node* current);
	typename Tree<T>::Node* findNode(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* findFather(typename Tree<T>::Node*, typename Tree<T>::Node*);
	void deleteDuplicates(typename Tree<T>::Node* current);
};

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);  // calling the 'private' add
}



template<class T>
T SearchTree<T>::successor(typename Tree<T>::Node* current)  // finding a node's successor
{
	if (current->right != NULL) // if his successor is in his sub-tree
	{
		typename Tree<T>::Node* tmp = current->right;  // so we'll go once right and then all the way to the left
		while (tmp->left != NULL)
			tmp = tmp->left;
		return tmp->value; // and return the value
	}
	typename Tree<T>::Node* t = findFather(current, Tree<T>::root); // func will find node's father
	while (t != NULL && current == t->right) // as long as the father exists and the current is still a right son
	{
		current = t;
		t = findFather(current, Tree<T>::root);
	}
	if (t == NULL)
		throw "no successor\n";
	return t->value; // return the value of the father
}

template<class T>
typename Tree<T>::Node* SearchTree<T>::findNode(typename Tree<T>::Node* current, T val)
{
	if (current == NULL || current->value == val)
		return current;
	if (val > current->value)
		return findNode(current->right, val);  // if the val is bigger than current we'll check its right side
	else
		return findNode(current->left, val);
}

template<class T>
inline typename Tree<T>::Node* SearchTree<T>::findFather(typename Tree<T>::Node* lookFor, typename Tree<T>::Node* parent)
{
	if (lookFor == Tree<T>::root)  // if it does'nt have a right and its the root then no successor
		return NULL;
	if (parent->left != lookFor && parent->right != lookFor) // if we havent found the father yet because its not any of the 2 sons
	{
		if (parent->value > lookFor->value)  // if the value of "parent we have'nt found yet" is bigger
			return findFather(lookFor, parent->left);   // then we'll go left
		if (parent->value <= lookFor->value)
			return findFather(lookFor, parent->right);
	}
	else  // meaning if it IS the node's left or right
		return parent; // then we've found the parent
}

template<class T>
inline void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* current) // deleting doubles
{
	if (current) // not empty
	{
		T tmp = current->value;
		typename Tree<T>::Node* seek1 = findNode(current->left, tmp); // it's left
		typename Tree<T>::Node* seek2 = findNode(current->right, tmp); // it's right
		if (seek1 != NULL || seek2 != NULL)
		{
			if (seek1 != NULL)
				remove(seek1); // remove the duplicate
			if (seek2 != NULL)
				remove(seek2);
			deleteDuplicates(current);
		}
		else
		{
			deleteDuplicates(current->left);
			deleteDuplicates(current->right);
		}
	}
	else
		return;
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)

		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else

		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}

template<class T>
void SearchTree<T>::remove(typename Tree<T>::Node* current)
{
	if (current->left == NULL && current->right == NULL) // if its a leaf
	{
		typename Tree<T>::Node* t1 = findFather(current, Tree<T>::root);
		if (t1 == NULL)
		{
			delete current; // if his father is null meaning he has no father, then delete the node
			return;
		}
		if (t1->right == current)  // if he's his father's right son, then make his father's right be null
			t1->right = NULL;
		else if (t1->left == current)  // and if left...
			t1->left = NULL;
		delete current;  // and delete the node
	}
	else if (current->right == NULL && current->left != NULL) // if he has only a left son
	{
		current->value = current->left->value; // appoint his left to him
		remove(current->left);
	}
	else if (current->right != NULL && current->left == NULL) // if he has only a right son
	{
		current->value = current->right->value; // appoint his right to him
		remove(current->right);
	}
	else  // if both sons are not NULL
	{
		T temp = successor(current); // temp holds the value of the successor
		typename Tree<T>::Node* t2 = findNode(current, temp); // t2 is now the node that is the successor
		current->value = temp; // appoint the current's value to the successor's value
		remove(t2); // remove the successor
	}
}

template<class T>
void SearchTree<T>::remove(T val)
{
	typename Tree<T>::Node* t = findNode(Tree<T>::root, val); // t is the node with val
	if (t == NULL)  // if that type of book does'nt exist, then throw and don't even send to remove
		throw "no exist";
	remove(t);  // remove that node
}

template<class T>
T SearchTree<T>::successor(T val)
{
	typename Tree<T>::Node* t = findNode(Tree<T>::root, val); // t is the node with val
	return successor(t); // return the successor of the node with val
}


template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}


