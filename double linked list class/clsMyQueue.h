#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

template<class T>
class clsMyQueue 
{
protected:
	clsDblLinkedList<T>_MyList;
public:

	void push(T value) 
	{
		_MyList.InsertAtEnd(value);
	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}
	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T GetItem(int indx)
	{
		return _MyList.GetItem(indx);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int indx, T value)
	{
		_MyList.UpdateItem(indx,value);
	}

	void InsertAfter(int indx, T value)
	{
		_MyList.InsertAfter(indx,value);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Clear()
	{
		_MyList.Clear();
	}
};

