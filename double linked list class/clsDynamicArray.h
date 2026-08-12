#pragma once
#include <iostream>
#include <utility>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray;

public:
	T* OriginalArr;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			_Size = 0;
		else
			_Size = Size;

		OriginalArr = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[]OriginalArr;
		OriginalArr = NULL;
	}

	bool SetItem(int indx, T value)
	{
		if (indx >= _Size || indx < 0 || _Size < 0)
			return false;

		OriginalArr[indx] = value;
		return true;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArr[i] << " ";
		}
		cout << endl;
	}


	void Resize(int newSize)
	{
		if (newSize < 0)
			newSize = 0;

		_TempArray = new T[newSize];

		if (newSize < _Size)
			_Size = newSize;

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArr[i];
		}
		_Size = newSize;
		delete[] OriginalArr;
		OriginalArr = _TempArray;
	}

	T GetItem(int indx)
	{
		return OriginalArr[indx];
	}

	void Reverse()
	{
		for (int i = 0; i < _Size / 2; i++)
			swap(OriginalArr[i], OriginalArr[_Size - 1 - i]);
	}

	void Clear()
	{
		delete[]OriginalArr;
		OriginalArr = NULL;
		_Size = 0;
	}

	bool DeleteItemAt(int indx)
	{

		if (indx >= _Size || indx < 0)
			return false;

		_TempArray = new T[_Size - 1];
		int Count = 0;
		for (int i = 0; i < _Size; i++)
		{
			if (i != indx)
			{
				_TempArray[Count] = OriginalArr[i];
				Count++;
			}
		}
		delete[] OriginalArr;
		OriginalArr = _TempArray;
		_Size--;
		return true;
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T Value)
	{

		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArr[i] == Value)
				return i;
		}
		return -1;
	}

	bool DeleteItem(T Value)
	{
		int indx = Find(Value);
		if (indx == -1)
			return false;
		DeleteItemAt(indx);
		return true;
	}

	bool InsertAt(int indx, T Value)
	{
		if (indx > _Size || indx < 0)
			return false;

		_Size++;

		_TempArray = new T[_Size];

		///*	int counter = 0;
		//	for (int i = 0; i < _Size; i++)
		//	{
		//		if (i == indx)
		//		{
		//			_TempArray[i] = Value;
		//		}
		//		else
		//		{
		//			_TempArray[i] = OriginalArr[counter];
		//			
		//			counter++;
		//		}
		//	}*/
		for (int i = 0; i < indx; i++)
		{
			_TempArray[i] = OriginalArr[i];
		}
		_TempArray[indx] = Value;

		for (int i = indx + 1; i < _Size; i++)
		{
			_TempArray[i] = OriginalArr[i - 1];
		}
		delete[]OriginalArr;
		OriginalArr = _TempArray;
		return true;
	}

	void InsertAtBeginning(T Value)
	{
		InsertAt(0, Value);
	}

	bool InsertBefore(int indx, T Value)
	{
		return InsertAt(indx - 1, Value);
	}

	bool InsertAfter(int indx, T Value)
	{
		return InsertAt(indx + 1, Value);

	}

	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);

	}
};

