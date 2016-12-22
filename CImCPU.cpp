#include "CImCPU.h"
#include <ctime>
#include <iostream>

using namespace std;

CImCPU::CImCPU() : tact(0), numCopmletedTask(0), numTaskQueue(0), numIgnoredTasks(0), numDowntimeTacts(0), work(false)
{
	numTacts = t;
	sizeQueue = MaxQ;
	markNewTask = 0.5;
	markCompletionTask = 0.5;
}

CImCPU::CImCPU(unsigned int nTacts, unsigned int sQueue, double mNewTask, double mCompletionTask) : tact(0), numCopmletedTask(0), numTaskQueue(0), numIgnoredTasks(0), numDowntimeTacts(0), work(false)
{
	if (nTacts > t || sQueue > MaxQ || mCompletionTask >= 1 || mNewTask >= 1 || nTacts < 0 || sQueue < 0 || mCompletionTask < 0 || mNewTask < 0)
		throw "Incorrect values";
	numTacts = nTacts;
	sizeQueue = sQueue;
	markNewTask = mNewTask;
	markCompletionTask = mCompletionTask;
}

void CImCPU::Process()
{
	CQueue<unsigned int> queueTasks(sizeQueue);
	srand(time(0));
	for (tact; tact < numTacts; tact++)
	{
		if (work == true)
			if ((1.0*(rand() % 10)) / 10 > markCompletionTask)
			{
				work = false;
				numCopmletedTask++;
			}
		if ((1.0*(rand() % 10)) / 10 > markNewTask)
			if (queueTasks.IsEmpty())
				if (work == false)
				{
					work = true;
					continue;
				}
				else
				{
					queueTasks.Put(tact);
					continue;
				}
			else
				if (queueTasks.IsFull())
				{
					numIgnoredTasks++;
					continue;
				}

				else
				{
					queueTasks.Put(tact);
					continue;
				}
		else
			if (work == false)
				if (queueTasks.IsEmpty())
				{
					numDowntimeTacts++;
					continue;
				}
				else
				{
					queueTasks.Get();
					work = true;
					continue;
				}
	}
	if (work==true)
		numCopmletedTask++;
	while (!queueTasks.IsEmpty())
	{
		queueTasks.Get();
		numTaskQueue++;
	}
}

void CImCPU::Statistics()
{
	cout << "The number of completed tasks:\t" << numCopmletedTask << "\n";
	cout << "The number of ignored tasks:\t" << numIgnoredTasks << "\n";
	cout << "The number of tasks in the queue:\t" << numTaskQueue << "\n";
	cout << "The number of downtime tacts:\t" << numDowntimeTacts << "\n";
}