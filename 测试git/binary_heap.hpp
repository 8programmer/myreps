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
	size_t _size;
	size_t _cap;
public:
	binaryHeap() :_list(nullptr), _size(0), _cap(DEFAULT_SIZE) {}
	void  buildNode()
	{
		_list = new T[_cap]{};
		assert(_list);
	}
	void push(const T&value)
	{
		
		if(_size>=_cap)
		{
			int cur =(int) _cap;
			_list = (T*)realloc(_list, sizeof(T) * 2 * _cap);
			assert(_list);
			memset(_list + _cap, 0, sizeof(T) * _cap);
			_list[_cap] = value;
			++_size;
			_cap *= 2;
			siftUp(cur);
			return;
		}
		int cur = _size;
		_list[_size] = value;
		++_size;
		siftUp(cur);
	}
	void siftUp(int index)
	{
		int curIndex = index;
		T node = _list[curIndex];
		while (curIndex > 0)
		{
			T parentIndex = (curIndex - 1) >> 1;
			T parent = _list[parentIndex];
			if (parent >= node)
				break;
			_list[curIndex] = parent;
			curIndex = parentIndex;
		}
		_list[curIndex] = node;
	}
};
