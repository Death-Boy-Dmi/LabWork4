#pragma once

#include "CQueue.h"

#define t 10000

class CImCPU
{
	unsigned int numTacts;
	unsigned int sizeQueue;
	unsigned int tact;
	bool work;
	double markNewTask;
	double markCompletionTask;
	unsigned int numCopmletedTask;
	unsigned int numTaskQueue;
	unsigned int numIgnoredTasks;
	unsigned int numDowntimeTacts;
public:
	CImCPU(unsigned int nTacts, unsigned int sQueue, double mNewTask, double mCompletionTask);
	CImCPU();
	void Process();
	void Statistics();
};