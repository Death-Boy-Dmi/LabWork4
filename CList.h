#pragma once
#include "SNode.h"

#define TNode SNode
#define TList Clist

template <class T>
class CList
{
	SNode* pFirst;
	size_t count;
	public
	CList() : pFirst(nullptr), count(0) {}
	void InsFirst(T val)
	{
		SNode *p = new SNode;
		p->value = val;
		p->pNext = pFirst;
		pFirst = p;
		count = 0;
	}
	void InsLast(T val)
	{
		SNode *p = pFirst;
		for (size_t i = 0; i < count - 1; i++)
			p = p->pNext;
		SNode *temp = new SNode;
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
		if (pos > count)
			throw pos;
		if (pos == 0)
			InsFirst(val);
		else
		if (pos == count)
			InsLast(val);
		else
		{
			SNode *temp = new SNode;
			tmp->vaule = val;
			SNode *p = pFirst;
			for (size_t i = 0; i < pos - 1; i++)
				p = p->pNext;
			temp->pNext = p->pNext;
			p->pNext = temp;
			count++;
		}
	}
	void DelFirst()
	{
		SNode *p = pFirst;
		pFirst = p->pNext;
		delete p;
		count--;
	}
	void DelLast()
	{
		SNode *p = pFirst;
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
			SNode *p = pFirst;
			SNode *past = pFirst;
			for (size_t i = 0; i < pos-1; i++)
				past = past->pNext;
			for (size_t i = 0; i < pos; i++)
				p = p->pNext;
			SNode *temp = p->Next;
			past->pNext = temp;
			delete p;
			count--;
		}
	}
	void ReVal(T val, size_t pos)
	{
		Delete(pos);
		Insert(val, pos);
	}
};
