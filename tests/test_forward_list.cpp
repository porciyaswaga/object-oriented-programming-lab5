#include <gtest/gtest.h>
#include "memory/MapMemoryResource.h"
#include "container/ForwardList.h"

TEST(ForwardListTest, PushFrontInt) {
    MapMemoryResource memory;
    ForwardList<int> list(&memory);

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    auto it = list.begin();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);
}

TEST(ForwardListTest, PopFront) {
    MapMemoryResource memory;
    ForwardList<int> list(&memory);

    list.push_front(10);
    list.push_front(20);

    list.pop_front();

    EXPECT_EQ(*list.begin(), 10);
}

TEST(ForwardListTest, EmptyList) {
    MapMemoryResource memory;
    ForwardList<int> list(&memory);

    EXPECT_EQ(list.begin(), list.end());
}
