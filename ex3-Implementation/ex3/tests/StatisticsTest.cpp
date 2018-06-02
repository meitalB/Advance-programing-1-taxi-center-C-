//
// Created by mei on 03/12/16.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Statistics.h"

using  testing::Eq;
namespace {
    class StatisticsTest : public testing::Test {
    public:
        Statistics s;

        StatisticsTest() : s() {
            s;
        }
    };
}
TEST_F(StatisticsTest, getCurrentLocationTest){
    std::list<Person> list1 = s.getCurrentLocation();
    std::list<Person> list2 = s.getCurrentLocation();
    ASSERT_EQ(list1.front().equalPerson(list2.front()),true);
}