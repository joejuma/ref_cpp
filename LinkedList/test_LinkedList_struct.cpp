#include "test_LinkedList_struct.h"

#ifndef TEST_LINKED_LIST_STRUCT__CPP
#define TEST_LINKED_LIST_STRUCT__CPP
/* Deps */
#include "LinkedList_struct.h"
#include <iostream>

bool test_LinkedList_first()
{
	std::cout << "test_LinkedList_first():";
	bool result = true;
	LinkedList<int> sample;
	
	result &= sample.first() == &sample._end;
	
	sample.insert(1, 0);
	result &= sample.first()->value == 1;
	
	sample.insert(2, 0);
	result &= sample.first()->value == 2;

	sample.remove(sample.getNode(0));
	result &= sample.first()->value == 1;

	sample.clear();
	result &= sample.first() == &sample._end;

	std::cout << (result ? "Passed" : "Failed") << "\n";
	return result;
};
bool test_LinkedList_last()
{
	std::cout << "test_LinkedList_last():";
	bool result = true;
	LinkedList<int> sample;

	result &= sample.last() == &sample._start;

	sample.insert(1, 0);
	result &= sample.last()->value == 1;

	sample.insert(2, 0);
	result &= sample.last()->value == 1;

	sample.remove(sample.getNode(1));
	result &= sample.last()->value == 2;

	sample.clear();
	result &= sample.last() == &sample._start;
	
	std::cout << (result ? "Passed" : "Failed") << "\n";
	return result;
};

bool test_LinkedList_size()
{
	std::cout << "test_LinkedList_size():";

	bool result = true;
	LinkedList<int> sample;

	for (uint64_t i = 0; i < 10; i++)
	{
		sample.insert((int)i, 0);
		result &= sample.size() == (i+1);
	};

	for (uint64_t i = 0; i < 10; i++)
	{
		sample.remove(sample.getNode(0));
		result &= sample.size() == ((10-1) - i);
	};

	std::cout << (result ? "Passed" : "Failed") << "\n";
	return result;
};
bool test_LinkedList_getNode()
{
	std::cout << "test_LinkedList_getNode():";
	bool result = true;
	LinkedList<int> sample;

	sample.insert(1, 0);
	sample.insert(2, 0);
	sample.insert(3, 1);

	result &= sample.getNode(0)->value == 2;
	result &= sample.getNode(1)->value == 3;
	result &= sample.getNode(2)->value == 1;

	result &= sample.getNode(1000) == 0;

	std::cout << (result ? "Passed" : "Failed") << "\n";
	return result;
};
bool test_LinkedList_accessOperator()
{
	std::cout << "test_LinkedList_accessOperator():";
	bool result = true;
	LinkedList<int> sample;

	sample.insert(1, 0);
	sample.insert(2, 0);
	sample.insert(3, 1);

	result &= sample[0] == 2;
	result &= sample[1] == 3;
	result &= sample[2] == 1;

	try
	{
		result &= sample[100] == 0;
		result &= false;
	}
	catch (...)
	{
		result &= true;
	};

	std::cout << (result ? "Passed" : "Failed") << "\n";
	return result;
};

bool test_LinkedList_insert()
{
	std::cout << "test_LinkedList_insert():";
	bool result = true;
	LinkedList<int> sample;

	sample.insert(1, 0);
	result &= (sample.getNode(0)->value == 1);
	result &= sample.size() == 1;

	sample.insert(2, 0);
	result &= (sample.getNode(0)->value == 2);
	result &= sample.size() == 2;

	std::cout << (result ? "Passed" : "Failed") << "\n";
	return result;
};
bool test_LinkedList_remove()
{
	std::cout << "test_LinkedList_remove():";
	bool result = true;
	LinkedList<int> sample;

	for (uint64_t i = 0; i < 10; i++)
	{
		sample.insert(i, 0);
	};

	uint64_t j = 9;

	for (int64_t i = 9; i >= 0; --i)
	{
		result &= sample.size() == (i+1);
		result &= sample.getNode(0)->value == i;
		result &= sample.remove(sample.getNode(0));
	};
	
	std::cout << (result ? "Passed" : "Failed") << "\n";
	return result;
};
bool test_LinkedList_clear()
{
	std::cout << "test_LinkedList_clear():";

	bool result = true;
	LinkedList<int> sample;

	for (uint64_t i = 0; i < 10; i++)
	{
		sample.insert((int)i, 0);
	};

	result &= sample.size() == 10;
	sample.clear();
	result &= sample.size() == 0;

	std::cout << (result ? "Passed" : "Failed") << "\n";
	return result;
}

bool test_LinkedList_struct()
{
	std::cout << "test_LinkedList()...\n";
	bool result = true;

	result &= test_LinkedList_first();
	result &= test_LinkedList_last();

	result &= test_LinkedList_size();
	result &= test_LinkedList_getNode();
	result &= test_LinkedList_accessOperator();

	result &= test_LinkedList_insert();
	result &= test_LinkedList_remove();
	result &= test_LinkedList_clear();

	std::cout << "test_LinkedList(): " << (result? "Passed":"Failed") << "\n";
	return result;
};

#endif