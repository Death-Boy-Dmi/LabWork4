#include "CImCPU.h"
#include "CImCluster.h"
#include <iostream>

using namespace std;
void main()
{
	CImCPU ImCPU;
	setlocale(LC_ALL, "Russian");
	ImCPU.Process();
	ImCPU.Statistics();
}