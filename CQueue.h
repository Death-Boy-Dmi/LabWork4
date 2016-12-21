#pragma once
#include "SNode.h"
#include "CList.h"

#define MaxQ 300

template <class T>
class CQueue
{
	CList<T> mem;
	size_t top;
	size_t size;
public:
	CQueue() : top(-1), size(MaxQ) {}
	CQueue(size_t s) : top(-1) 
	{
		if (s > MaxQ || s < 1)
			throw s;
		size = s;
	}
	bool IsEmpty()
	{
		return top == (-1);
	}
	bool IsFull()
	{
		return top == (size - 1);
	}
	void Put(T val)
	{
		if (IsFull())
			throw val;
		mem.InsFirst(val);
		top++;
	}
	T Get()
	{
		if (IsEmpty())
			throw 0;
		T val;
		val = mem.GetVal(mem.GetCount()-1);
		mem.DelLast();
		top--;
		return val;
	}
	T GetVal()
	{
		if (IsEmpty())
			throw 0;
		T val;
		val = mem.GetVal(mem.GetCount() - 1);
		return val;
	}
};