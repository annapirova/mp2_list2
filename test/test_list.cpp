#include "list.h"
#include "gtest.h"

TEST(List, can_create)
{
	ASSERT_NO_THROW(List l);
}

TEST(List, isEmpty)
{
	List l;
	EXPECT_EQ(true, l.isEmpty());
}

TEST(List, insertFirst1)
{
	List l;
	l.InsertToHead(5);
	int k;
	ASSERT_NO_THROW(k = l.ViewHead());
}

TEST(List, insertFirst2)
{
	List l;
	l.InsertToHead(5);
	int k = l.ViewHead();
	EXPECT_EQ(5, k);
}

TEST(List, insertFirst3)
{
	List l;
	l.InsertToHead(5);
	l.InsertToHead(6);
	int k = l.ViewHead();
	EXPECT_EQ(6, k);
}

TEST(List, insertLast1)
{
	List l;
	l.InsertToHead(5);
	l.InsertToHead(6);
	l.InsertToTail(4);
	EXPECT_EQ(4, l.ViewTail());
}

TEST(List, insertLast2)
{
	List l;
	l.InsertToHead(5);
	l.InsertToHead(6);
	l.InsertToTail(4);
	ASSERT_NO_THROW(l.ViewTail());
}

TEST(List, insertLast3)
{
	List l;
	ASSERT_NO_THROW(l.InsertToTail(4));
}

TEST(List, insertFirst4)
{
	List l;
	ASSERT_ANY_THROW(l.ViewHead());
}

TEST(List, insertLast4)
{
	List l;
	ASSERT_ANY_THROW(l.ViewTail());
}

TEST(listIterator, test1)
{
	List l;
	l.InsertToHead(6);
	l.InsertToHead(5);
	l.InsertToHead(1);
	l.InsertToHead(5);
	listIterator i = l.begin();
	EXPECT_EQ(5, *i);
}

TEST(listIterator, test2)
{
	List l;
	l.InsertToHead(6);
	l.InsertToHead(5);
	l.InsertToHead(1);
	l.InsertToHead(5);
	listIterator i = l.begin();
	++i; // это "указатель" на 2й
	EXPECT_EQ(1, *i);
}

TEST(listIterator, test3)
{
	List l;
	l.InsertToHead(6);
	l.InsertToHead(5);
	l.InsertToHead(1);
	l.InsertToHead(5);
	listIterator i = l.tail();
	EXPECT_EQ(6, *i);
}

TEST(List, delete1)
{
	List l;
	l.InsertToHead(6);
	l.InsertToHead(5);
	l.InsertToHead(1);
	l.InsertToHead(5);

	l.Delete(1);

	listIterator i1 = l.begin();
	listIterator i2 = i1++;
	listIterator i3 = i2++;
	EXPECT_EQ(5, *i1);
	EXPECT_EQ(5, *i2);
	EXPECT_EQ(6, *i3);
	//EXPECT_EQ(6, l.ViewTail());
	listIterator i4 = i3++;
	EXPECT_EQ(i4, l.end());
}

TEST(List, delete2)
{
	List l;
	l.InsertToHead(6);
	l.InsertToHead(5);
	l.InsertToHead(1);
	l.InsertToHead(5);

	ASSERT_NO_THROW(l.Delete(5));
}

TEST(List, delete3)
{
	List l;
	l.InsertToHead(6);
	l.InsertToHead(5);
	l.InsertToHead(1);
	l.InsertToHead(5);

	l.Delete(5);
	EXPECT_EQ(1, l.ViewHead());
}

TEST(List, delete4)
{
	List l;
	l.InsertToHead(6);
	l.InsertToHead(5);
	l.InsertToHead(1);
	l.InsertToHead(5);

	ASSERT_NO_THROW(l.Delete(7));
}