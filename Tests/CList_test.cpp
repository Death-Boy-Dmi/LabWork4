#include "CList.h"
#include <gtest.h>

TEST(CList, can_create_List)
{
	ASSERT_NO_THROW(CList<int> list);
}
