#pragma once
#include "SNode.h"

#define TNode SNode
#define TList Clist

#define MaxL 10000

template <class T>
class CList
{
	SNode<T>* pFirst;
	size_t count;
public:
	CList() : pFirst(nullptr), count(0) {}
	~CList() 
	{
		while (IsEmpty() != true)
			DelLast();
	}
	bool IsFull()
	{
		return count == MaxL;
	}
	bool IsEmpty()
	{
		return count == 0;
	}
	void InsFirst(T val)
	{
		if (IsFull())
			throw val;
		if (IsEmpty())
		{
			pFirst->value = val;
			pFirst->pNext = nullptr;
		}
		else
		{
			SNode<T> *p = new SNode<T>;
			p->value = val;
			p->pNext = pFirst;
			pFirst = p;
			count = 0;
		}
	}
	void InsLast(T val)
	{
		if (IsFull())
			throw val;
		SNode<T> *p = pFirst;
		for (size_t i = 0; i < count - 1; i++)
			p = p->pNext;
		SNode<T> *temp = new SNode<T>;
		tmp->vaule = val;
		tmp->pNext = nullptr;
		if (p != nullptr)
			p->pNext = tmp;
		else
			pFirst = tmp;
		count++;
	}
	void Insert(T val, size_t pos)
	{
		if (IsFull())
			throw val;
		if (pos > count)
			throw pos;
		if (pos == 0)
			InsFirst(val);
		else
		if (pos == count)
			InsLast(val);
		else
		{
			SNode<T> *temp = new SNode<T>;
			tmp->vaule = val;
			SNode<T> *p = pFirst;
			for (size_t i = 0; i < pos - 1; i++)
				p = p->pNext;
			temp->pNext = p->pNext;
			p->pNext = temp;
			count++;
		}
	}
	void DelFirst()
	{
		SNode<T> *p = pFirst;
		pFirst = p->pNext;
		delete p;
		count--;
	}
	void DelLast()
	{
		SNode<T> *p = pFirst;
		for (size_t i = 0; i < count; i++)
			p = p->pNext;
		delete p;
		count--;
	}
	void Delete(size_t pos)
	{
		if (pos > count)
			throw pos;
		if (pos == 0)
			DelFirst(val);
		else
		if (pos == count)
			DelLast(val);
		else
		{
			SNode<T> *p = pFirst;
			SNode<T> *past = pFirst;
			for (size_t i = 0; i < pos-1; i++)
				past = past->pNext;
			for (size_t i = 0; i < pos; i++)
				p = p->pNext;
			SNode<T> *temp = p->Next;
			past->pNext = temp;
			delete p;
			count--;
		}
	}
	size_t GetCount()
	{
		return count;
	}
	T GetVal(size_t pos)
	{
		if (pos > count)
			throw pos;
		SNode<T> *p = pFirst;
		for (size_t i = 0; i < pos; i++)
			p = p->pNext;
		return p.val;
	}
	void ReVal(T val, size_t pos)
	{
		Delete(pos);
		Insert(val, pos);
	}
};
