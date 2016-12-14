#pragma once

#include "CQueue.h"
#include "STaskForCPU.h"

#define T 1000

class ImCPU
{
	unsigned int tact;
	CQeue<int> tasks;
	unsigned int numCopmletedTask;
	unsigned int numTaskQueue;
	unsigned int numFailure;
	unsigned int downtimeTacts;
public:
	void Statistics();
	void Process();
};