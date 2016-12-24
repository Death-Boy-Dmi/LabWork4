#include <iostream>
#include "CImCPU.h"

using namespace std;

void main()
{
	unsigned int nTacts;
	unsigned int sQueue;
	double mNewTask;
	double mCompletionTask;
	setlocale(LC_ALL, "Russian");
	cout << "Enter the number of tacts\n\t";
	cin >> nTacts;
	cout << "\n";
	cout << "Enter the size of queue\n\t";
	cin >> sQueue;
	cout << "\n";
	cout << "Enter the threshold for the appearance of new task (0<= a <1)\n\t";
	cin >> mNewTask;
	cout << "\n";
	cout << "Enter the threshold for the completion of new task (0<= b <1)\n\t";
	cin >> mCompletionTask;
	cout << "\n\n";
	CImCPU ImCPU(nTacts, sQueue, mNewTask, mCompletionTask);
	//CImCPU ImCPU;
	setlocale(LC_ALL, "Russian");
	ImCPU.Process();
	ImCPU.Statistics();
}