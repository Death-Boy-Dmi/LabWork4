#pragma once
#include "SNode.h"
#include "CList.h"

#define MaxQ 10000

template <class T>
class CQeue
{
	CList mem;
	size_t top;
	size_t size;
	public
	CQeue() : top(-1), size(MaxQ) {}
	CQeue(size_t s) : top(-1) 
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
		val = mem.GetVal(mem.GetCount());
		mem.DelLast();
		top--;
		return val;
	}
};