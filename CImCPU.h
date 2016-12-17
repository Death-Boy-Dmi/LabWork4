#pragma once

#include "CQueue.h"
#include "STaskForCPU.h"

#define T0 1000

class CImCPU
{
	unsigned int tact;
	CQueue<int> tasks;
	unsigned int numCopmletedTask;
	unsigned int numTaskQueue;
	unsigned int numFailure;
	unsigned int downtimeTacts;
public:
	void Statistics();
	void Process();
};