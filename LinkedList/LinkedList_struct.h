#pragma once

#ifndef LINKED_LIST_STRUCT__H
#define LINKED_LIST_STRUCT__H
/* Deps */
#include <stdint.h>
#include <string>
#include "LinkedListNode_struct.h"

#include <iostream>

/* Helper Functions */
template <typename Node>
inline void linked_list_insert_node(Node* firstNode, Node* secondNode, Node* newNode)
{
	// Make sure the nodes we're inserting between are adjacent,
	if (firstNode->next == secondNode && secondNode->prev == firstNode && newNode != 0)
	{
		// Let's goooooo
		firstNode->next = newNode;
		secondNode->prev = newNode;

		newNode->prev = firstNode;
		newNode->next = secondNode;
	};
};

template <typename Node>
inline void linked_list_insert_node_after(Node* targetNode, Node* newNode)
{
	if (targetNode != 0 && newNode != 0)
	{
		Node* next = targetNode->next;
		linked_list_insert_node(targetNode, next, newNode);
	};
};

template <typename Node>
inline void linked_list_insert_node_before(Node* targetNode, Node* newNode)
{
	if (targetNode != 0 && newNode != 0)
	{
		Node* prev = targetNode->prev;
		linked_list_insert_node(prev, targetNode, newNode);
	};
};

template <typename Node>
inline void linked_list_remove_node(Node* _node)
{
	if (_node != 0)
	{
		Node* prev = _node->prev;
		Node* next = _node->next;

		if (prev != 0)
		{
			prev->next = next;
		};
		
		if (next != 0)
		{
			next->prev = prev;
		};
	};
};

/* Class */
template <typename T>
struct LinkedList
{
	/*
		# Linked-List (struct)
	*/

	/* Type Definitions */
	typedef LinkedListNode<T> node;
	typedef node*(*nodeBuilder)(T);
	typedef void (*nodeDestroyer)(node*);

	// @todo: look into implementing an iterator class.

	/* Elements */

	// General
	node _start;
	node _end;
	uint64_t length;

	// Memory Management
	nodeBuilder createNode;
	nodeDestroyer deleteNode;

	/* Static Methods */
	// Node Life-Cycle Utilities
	static node* _createNode(T value)
	{
		return new node(value);
	};
	static void _deleteNode(node* ptr)
	{
		if (ptr != 0)
		{
			delete ptr;
			ptr = 0;
		};
	};

	/* Methods */

	// Constructors & Destructor
	LinkedList()
	{
		this->_start.prev = 0;
		this->_start.next = &this->_end;
		
		this->_end.prev = &this->_start;
		this->_end.next = 0;

		this->length = 0;

		this->createNode = LinkedList<T>::_createNode;
		this->deleteNode = LinkedList<T>::_deleteNode;
	};
	virtual ~LinkedList()
	{
		this->clear();
	};

	// Metadata
	inline uint64_t size()
	{
		return this->length;
	}

	// Special Node Accessors
	inline node* first()
	{
		return this->_start.next;
	}
	inline node* last()
	{
		return this->_end.prev;
	};

	// Access Operators
	node* getNode(const uint64_t i)
	{
		node* currentNode = this->first();
		for (uint64_t j = 0; j < i; j++)
		{
			if (currentNode != 0)
			{
				currentNode = currentNode->next;
			}
			else
			{
				return 0;
			};
		};

		return currentNode;
	};
	T& operator[](const uint64_t i)
	{
		if (i >= 0 && i < this->size())
		{
			return this->getNode(i)->value;
		};

		// @note: you could make this return a pointer and handle it via nullptr, instead of an exception y'know. Makes a more stable - but less explicit program.
		throw std::out_of_range("Attempted to access an out-of-range index using LinkedList::operator[].");
	};

	// List Operations
	bool insert( T value, uint64_t i )
	{
		node* newNode = this->createNode(value);
		node* pos = this->getNode(i);

		if (pos != 0)
		{
			linked_list_insert_node_before(pos, newNode);
			this->length += 1;
		}
		else
		{
			return false;
		};

		return true;
	};
	bool remove(node* ptr)
	{
		if (ptr != 0)
		{
			linked_list_remove_node(ptr);
			this->length -= 1;
			this->deleteNode(ptr);
		}
		else
		{
			return false;
		};
		return true;
	};
	bool remove(uint64_t i)
	{
		// @warning: If you try using this with passed in 0, it will error. This is because it's vague whether that's an int or nullptr.
		// consider removing this method since it's not used anywhere - or renaming, since it may still be useful.
		if (i >= 0 && i < this->length)
		{
			return this->remove(this->getNode(i));
		};
		return false;
	};
	
	void clear()
	{
		node* currentNode = this->getNode(0);
		while (currentNode != 0 && this->length > 0)
		{
			this->remove(currentNode);
			currentNode = this->getNode(0);
		};
	};

	// Serialization
	std::string toString()
	{
		using namespace std;
		string s = "[start]-";

		node* currentNode = this->first();
		while (currentNode != 0 && currentNode != &this->_end)
		{
			s += currentNode->toString();
			s += "-";
			currentNode = currentNode->next;
		};
		s += "[end]";

		return s;
	};
};

#endif