#pragma once

#include "CQueue.h"

#define T 1000

class ImCPU
{
	unsigned int tact;
	CQeue<int> tasks;
	unsigned int numCopmletedTask;
	unsigned int numTaskQeue;
	unsigned int numFailure;
	unsigned int downtimeTacts;
public:
	void Statistics();
	void Process();
};