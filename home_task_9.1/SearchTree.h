//Name: Tal Rodgold
//ID: 318162344
//Course: Workshop in c++
//Task number: task 9 question 1
//this program implements a tree

#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value);
	bool  search(T value)
	{
		return search(Tree<T>::root, value);
	}
	void remove(T); // remove
	T successor(T); //successor
	void deleteDuplicates() { deleteDuplicates(Tree<T>::root); } // delete
	
private:
	void add(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* findNode(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* findFather(typename Tree<T>::Node*, typename Tree<T>::Node*);
	void remove(typename Tree<T>::Node*); // remove
	T successor(typename Tree<T>::Node*); //successor
	void deleteDuplicates(typename Tree<T>::Node* ); // delete
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
	add(Tree<T>::root, val);
}



template<class T>
T SearchTree<T>::successor(typename Tree<T>::Node* suc) //successor
{
	if (suc->right != NULL) // if right is not null
	{
		typename Tree<T>::Node* tmp = suc->right;
		while (tmp->left != NULL) // as long as left isnt null
			tmp = tmp->left;
		return tmp->value;
	}
	typename Tree<T>::Node* t = findFather(suc, Tree<T>::root);
	while (t != NULL && suc == t->right)
	{
		suc = t;
		t = findFather(suc, Tree<T>::root);
	}
	if (t == NULL)
		throw "no successor\n"; // throw exprecion
	return t->value;
}

template<class T>
typename Tree<T>::Node* SearchTree<T>::findNode(typename Tree<T>::Node* current, T val)
{
	if (current == NULL || current->value == val)
		return current;
	if (val > current->value)
		findNode(current->right, val);
	else
		findNode(current->left, val);
}

template<class T>
inline typename Tree<T>::Node* SearchTree<T>::findFather(typename Tree<T>::Node* lookFor, typename Tree<T>::Node* parent)
{
	if (lookFor == Tree<T>::root)
		return NULL;
	if (parent->left != lookFor && parent->right != lookFor)
	{
		if (parent->value >= lookFor->value)
			return findFather(lookFor, parent->left);
		if (parent->value < lookFor->value)
			return findFather(lookFor, parent->right);
	}
	else
		return parent;
}

template<class T>
inline void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* del) // delete
{
	if (del)
	{
		T temp = del->value;
		typename Tree<T>::Node* search_1 = findNode(del->left, temp);
		typename Tree<T>::Node* search_2 = findNode(del->right, temp);
		if (search_1 != NULL || search_2 != NULL)
		{
			if (search_1 != NULL)
				remove(search_1);
			if (search_2 != NULL)
				remove(search_2);
			deleteDuplicates(del);
		}
		else
		{
			deleteDuplicates(del->left);
			deleteDuplicates(del->right);
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
void SearchTree<T>::remove(typename Tree<T>::Node* rem) // remove
{
	if (rem->left == NULL && rem->right == NULL) // if left and right null
	{
		typename Tree<T>::Node* t1 = findFather(rem, Tree<T>::root);
		if (t1->right == rem)
			t1->right = NULL;
		else
			t1->left = NULL;
		delete rem;
	}
	else if (rem->right == NULL && rem->left != NULL) // if right null but left not
	{
		rem->value = rem->left->value;
		remove(rem->left);
	}
	else if (rem->right != NULL && rem->left == NULL) // if left null but rught not
	{
		rem->value = rem->right->value;
		remove(rem->right);
	}
	else  // if both are not null
	{
		T temp = successor(rem);
		typename Tree<T>::Node* t2 = findNode(rem, temp);
		rem->value = temp;
		remove(t2);
	}
}

template<class T>
void SearchTree<T>::remove(T val) // remove
{
	typename Tree<T>::Node* t = findNode(Tree<T>::root, val);
	remove(t);
}

template<class T>
T SearchTree<T>::successor(T val) //successor
{
	typename Tree<T>::Node* t = findNode(Tree<T>::root, val);
	return successor(t);
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

