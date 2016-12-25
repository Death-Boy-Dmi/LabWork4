#include <gtest.h>
#include "CImCPU.h"

TEST(CImCPU, can_create_ImCPU)
{
	ASSERT_NO_THROW(CImCPU CPU);
}

TEST(CImCPU, can_create_ImCPU_2)
{
	ASSERT_NO_THROW(CImCPU CPU(10, 10, 0.5, 0.5));
}

TEST(CImCPU, throw_when_create_ImCPU_with_incorrect_values)
{
	ASSERT_ANY_THROW(CImCPU CPU(-10, 10001, 1, -0.5));
}

TEST(CImCPU, can_use_Process)
{
	CImCPU CPU;
	ASSERT_NO_THROW(CPU.Process());
}

TEST(CImCPU, can_use_Statistics)
{
	CImCPU CPU;
	ASSERT_NO_THROW(CPU.Statistics());
}
