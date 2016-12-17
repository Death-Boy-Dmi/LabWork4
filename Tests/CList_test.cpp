#include "CList.h"
#include <gtest.h>

TEST(CList, can_create_List)
{
	ASSERT_NO_THROW(CList<int> list);
}

TEST(CList, can_use_IsEmpty)
{
	CList<int> list;

	ASSERT_NO_THROW(list.IsEmpty());
}

TEST(CList, can_use_IsFull)
{
	CList<int> list;

	ASSERT_NO_THROW(list.IsFull());
}

TEST(CList, can_use_InsFirst)
{
	CList<int> list;

	ASSERT_NO_THROW(list.InsFirst(5));
}

TEST(CList, can_use_InsLast)
{
	CList<int> list;
	list.InsFirst(5);
	ASSERT_NO_THROW(list.InsLast(5));
}

TEST(CList, can_use_Insert)
{
	CList<int> list;
	list.InsFirst(5);
	list.InsLast(5);
	ASSERT_NO_THROW(list.Insert(5, 1));
}

TEST(CList, can_use_DelFirst)
{
	CList<int> list;
	list.InsFirst(5);

	ASSERT_NO_THROW(list.DelFirst());
}

TEST(CList, can_use_DelLast)
{
	CList<int> list;
	list.InsFirst(5);

	ASSERT_NO_THROW(list.DelLast());
}

TEST(CList, can_use_Delete)
{
	CList<int> list;
	list.InsFirst(5);
	list.InsLast(5);

	ASSERT_NO_THROW(list.Delete(1));
}

TEST(CList, can_use_GetCount)
{
	CList<int> list;

	ASSERT_NO_THROW(list.GetCount());
}

TEST(CList, can_use_ReVal)
{
	CList<int> list;
	list.InsFirst(5);

	ASSERT_NO_THROW(list.ReVal(3, 0));
}

TEST(CList, can_use_GetVal)
{
	CList<int> list;
	list.InsFirst(5);

	ASSERT_NO_THROW(list.GetVal(0));
}

TEST(CList, throw_when_use_InsFirst_when_list_is_full)
{
	CList<int> list;
	for (size_t i = 0; i < MaxL; i++)
		list.InsFirst(0);

	ASSERT_ANY_THROW(list.InsFirst(5));
}

TEST(CList, throw_when_use_InsLast_when_list_is_full)
{
	CList<int> list;
	for (size_t i = 0; i < MaxL; i++)
		list.InsFirst(0);

	ASSERT_ANY_THROW(list.InsLast(5));
}

TEST(CList, throw_when_use_Insert_when_list_is_full)
{
	CList<int> list;
	for (size_t i = 0; i < MaxL; i++)
		list.InsFirst(0);

	ASSERT_ANY_THROW(list.Insert(5, 5));
}

TEST(CList, throw_when_use_Insert_when_pos_bigger_count)
{
	CList<int> list;

	ASSERT_ANY_THROW(list.Insert(0, 5));
}

TEST(CList, throw_when_use_Delete_when_pos_bigger_count)
{
	CList<int> list;

	ASSERT_ANY_THROW(list.Delete(5));
}

TEST(CList, throw_when_use_Delete_when_list_is_empty)
{
	CList<int> list;

	ASSERT_ANY_THROW(list.Delete(5));
}

TEST(CList, throw_when_use_DelFirst_when_list_is_empty)
{
	CList<int> list;

	ASSERT_ANY_THROW(list.DelFirst());
}

TEST(CList, throw_when_use_DelLast_when_list_is_empty)
{
	CList<int> list;

	ASSERT_ANY_THROW(list.DelLast());
}

TEST(CList, throw_when_use_GetVal_when_pos_bigger_count)
{
	CList<int> list;

	ASSERT_ANY_THROW(list.GetVal(5));
}

TEST(CList, throw_when_use_ReVal_when_pos_bigger_count)
{
	CList<int> list;

	ASSERT_ANY_THROW(list.ReVal(5,5));
}

TEST(CList, can_right_use_IsEmpty)
{
	CList<int> list;

	ASSERT_TRUE(list.IsEmpty());
}

TEST(CList, can_right_use_IsFull)
{
	CList<int> list;
	for (size_t i = 0; i < MaxL; i++)
		list.InsFirst(0);
	ASSERT_TRUE(list.IsFull());
}

TEST(CList, can_right_use_InsFirst_and_GetVal)
{
	CList<int> list;
	list.InsFirst(5);

	ASSERT_TRUE(list.GetVal(0) == 5);
}

TEST(CList, can_right_use_InsLast)
{
	CList<int> list;
	list.InsLast(5);
	list.InsLast(3);
	ASSERT_TRUE(list.GetVal(0) == 5);
	ASSERT_TRUE(list.GetVal(1) == 3);
}

TEST(CList, can_right_use_Insert)
{
	CList<int> list;
	list.InsLast(5);
	list.InsLast(3);
	list.Insert(13, 1);
	ASSERT_TRUE(list.GetVal(1) == 13);
}

TEST(CList, can_right_use_DelFirst)
{
	CList<int> list;
	list.InsFirst(5);
	list.InsFirst(3);
	list.InsFirst(13);

	list.DelFirst();
	ASSERT_TRUE(list.GetVal(0) == 3);
}

TEST(CList, can_right_use_DelLast)
{
	CList<int> list;
	list.InsFirst(5);
	list.InsFirst(3);
	list.InsFirst(13);

	list.DelLast();
	ASSERT_TRUE(list.GetVal(1) == 3);
}

TEST(CList, can_right_use_Delete)
{
	CList<int> list;
	list.InsFirst(5);
	list.InsLast(3);
	list.InsLast(13);

	list.Delete(1);
	ASSERT_TRUE(list.GetVal(1) == 13);
}
TEST(CList, can_right_use_GetCount)
{
	CList<int> list;
	list.InsFirst(5);
	list.InsLast(3);
	list.InsLast(13);

	ASSERT_TRUE(list.GetCount() == 3);
}

TEST(CList, can_right_use_ReVal)
{
	CList<int> list;
	list.InsFirst(5);
	list.ReVal(3, 0);

	ASSERT_TRUE(list.GetVal(0) == 3);
}