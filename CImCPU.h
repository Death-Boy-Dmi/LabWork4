#pragma once

#include "CQueue.h"

#define t 1000

class CImCPU
{
	unsigned int tact;
	bool work;
	CQueue<int> queueTasks;
	double markNewTask;
	double markCompletionTask;
	unsigned int numCopmletedTask;
	unsigned int numTaskQueue;
	unsigned int numIgnoredTasks;
	unsigned int numDowntimeTacts;
public:
	CImCPU();
	void Process();
	void Statistics();
};