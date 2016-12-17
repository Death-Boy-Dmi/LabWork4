#include "CQueue.h"
#include <gtest.h>

TEST(CQueue, can_create_Queue)
{
	ASSERT_NO_THROW(CQueue<int> queue(5));
}

TEST(CQueue, can_create_Queue_2)
{
	ASSERT_NO_THROW(CQueue<int> queue);
}

TEST(CQueue, can_use_IsEmpty)
{
	CQueue<int> queue;

	ASSERT_NO_THROW(queue.IsEmpty());
}

TEST(CQueue, can_use_IsFull)
{
	CQueue<int> queue;

	ASSERT_NO_THROW(queue.IsFull());
}

TEST(CQueue, can_use_Put)
{
	CQueue<int> queue;

	ASSERT_NO_THROW(queue.Put(5));
}

TEST(CQueue, can_use_Get)
{
	CQueue<int> queue;
	queue.Put(5);

	ASSERT_NO_THROW(queue.Get());
}

TEST(CQueue, can_use_GetVal)
{
	CQueue<int> queue;
	queue.Put(5);

	ASSERT_NO_THROW(queue.GetVal());
}

TEST(CQueue, throw_when_create_Queue_with_incorrect_lengh)
{
	ASSERT_ANY_THROW(CQueue<int> queue(-5));
	ASSERT_ANY_THROW(CQueue<int> queue(100005));
}

TEST(CQueue, throw_when_use_Put_when_queue_is_full)
{
	CQueue<int> queue(1);
	queue.Put(5);

	ASSERT_ANY_THROW(queue.Put(5));
}

TEST(CQueue, throw_when_use_Get_when_queue_is_empty)
{
	CQueue<int> queue(1);
	
	ASSERT_ANY_THROW(queue.Get());
}

TEST(CQueue, throw_when_use_GetVal_when_queue_is_empty)
{
	CQueue<int> queue(1);

	ASSERT_ANY_THROW(queue.GetVal());
}

TEST(CQueue, can_use_Put_and_Get)
{
	CQueue<int> queue;
	queue.Put(5);
	int res = queue.Get();

	EXPECT_EQ(res, 5);
}

TEST(CQueue, can_use_Put_and_GetVal)
{
	CQueue<int> queue;
	queue.Put(5);
	int res = queue.GetVal();

	EXPECT_EQ(res, 5);
}