#pragma once
#include<assert.h>
#include<iostream>
#ifndef DEFAULT_SIZE 
#define DEFAULT_SIZE 16
#endif
template<class T>
class binaryHeap
{


	T* _list;
	int _size;
	int _cap;
public:
	binaryHeap() :_list(nullptr), _size(0), _cap(DEFAULT_SIZE) {}
	void  buildNode()
	{
		_list = new T[_cap]{};
		assert(_list);
	}
	void push(const T& value)
	{

		if (_size >= _cap)
		{
			int cur = _cap;
			T* temp = (T*)realloc(_list, sizeof(T) * 2 * _cap);
			assert(temp);
			_list = temp;
			memset(_list + _cap, 0, sizeof(T) * _cap);
			_list[_cap] = value;
			++_size;
			_cap *= 2;
			siftUp(cur);
			return;
		}
		int cur = _size;
		int up = _size - 1;
		_list[_size] = value;
		if (up)
		{
			if (_list[up] == _list[cur])
				return;
		}
		++_size;
		if (cur)
			siftUp(cur);
	}
	void siftUp(int index)
	{
		int curIndex = index;
		T node = _list[curIndex];
		int upIndex = 0;
		while (curIndex > 0)
		{
			T parentIndex = (curIndex - 1) >> 1;
			T parent = _list[parentIndex];
			if (parent >= node)
				break;
			_list[curIndex] = parent;
			curIndex = parentIndex;
			upIndex++;
		}
		if (upIndex)
			_list[curIndex] = node;
	}
	void pop(T& value)
	{
		if (!_size)
			return;
		int cur = (int)_size - 1;
		_list[0] = _list[cur];
		--_size;
		if (_size)
			siftDown(0);
	}
	void siftDown(int index)
	{
		int curIndex = index;
		T node = _list[curIndex];
		int upIndex = 0;
		while (curIndex < (_size >> 1))
		{
			int leftIndex = (curIndex << 1) + 1;
			int rightIndex = (curIndex << 1) + 2;
			T left = _list[leftIndex];
			T right = _list[rightIndex];
			if (node >= left && node >= right)
				break;
			int lastIndex = left > right ? leftIndex : rightIndex;
			T last = _list[lastIndex];
			_list[curIndex] = last;
			curIndex = lastIndex;
			upIndex++;
		}
		if (upIndex)
			_list[curIndex] = node;
	}
	void foreach()
	{
		for (int i = 0; i < _size; ++i)
			std::cout << _list[i] << " ";
		std::cout << "\n";
	}
	int Size()
	{
		return _size;
	}
	virtual~binaryHeap()
	{
		if (_list)
		{
			free(_list);//delete []_list;
			_list = nullptr;
		}
		std::cout << "binaryHeap is destroy" << "\n";
	}
};
