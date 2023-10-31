#pragma once

#ifndef LINKED_LIST_NODE_STRUCT__H
#define LINKED_LIST_NODE_STRUCT__H
/* Deps */
#include <string>

template <typename T>
struct LinkedListNode
{
	/*
		# Linked-List Node (struct)
	*/

	/* Type Definitions */
	typedef LinkedListNode<T> node;

	/* Elements */
	T value;
	node* next;
	node* prev;

	/* Methods */

	// Constructors & Destructor
	LinkedListNode()
	{
		this->next = 0;
		this->prev = 0;
		this->value = T();
	};
	LinkedListNode(T value)
	{
		this->next = 0;
		this->prev = 0;
		this->value = value;
	}
	virtual ~LinkedListNode()
	{
		this->next = 0;
		this->prev = 0;
	};

	// Serialization
	std::string toString()
	{
		using namespace std;
		string s = "";
		s += "{";
		//s += "\"previous\":\"" + std::to_string((uint64_t)this->prev) + "\",";
		//s += "\"address\":\"" + std::to_string((uint64_t)(this)) + "\",";
		s += "\"value\":\"" + std::to_string(this->value) + "\"";
		//s += "\"next\":\"" + std::to_string((uint64_t)this->next) + "\"";
		s += "}";
		return s;
	};
};
#endif