#pragma once

#include <iostream>

using namespace std;

struct STaskForCPU
{
	float markNewTask;
	float markCompletionTask;
	STaskForCPU()
	{
		cout << "Enter the threshold for the appearance of new task (0<= a <1)";
		cin >> markNewTask;
		cout << "/n";
		cout << "Enter the threshold for the completion of new task (0<= b <1)";
		cin >> markCompletionTask;
		cout << "/n" << "/n";
	}
};