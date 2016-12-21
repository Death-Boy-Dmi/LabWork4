#include "CImCPU.h"
#include <ctime>
#include <iostream>

using namespace std;


CImCPU::CImCPU(): tact(0), numCopmletedTask(0), numTaskQueue(0), numIgnoredTasks(0), numDowntimeTacts(0), work(false)
{
	
	setlocale(LC_ALL, "Russian");
	cout << "Enter the number of tacts\n\t";
	cin >> numTacts;
	cout << "\n";
	cout << "Enter the size of queue\n\t";
	cin >> sizeQueue;
	cout << "\n";
	cout << "Enter the threshold for the appearance of new task (0<= a <1)\n\t";
	cin >> markNewTask;
	cout << "\n";
	cout << "Enter the threshold for the completion of new task (0<= b <1)\n\t";
	cin >> markCompletionTask;
	cout << "\n\n";
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