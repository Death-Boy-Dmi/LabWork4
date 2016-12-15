#include "CQueue.h"
#include <gtest.h>

TEST(CQueue, can_create_Queue)
{
	ASSERT_NO_THROW(CQueue<int> queue(5));
}
