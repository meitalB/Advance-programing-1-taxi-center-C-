#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Point.h"

using  testing::Eq;
namespace {
    class  PointTest : public testing::Test {
    public:
        Point point;
        PointTest() : point(0,0){}
    };
}
TEST_F(PointTest, pointGetX){
    ASSERT_EQ(0,point.x());
}
TEST_F(PointTest, pointGetY){
    ASSERT_EQ(0,point.y());
}
TEST_F(PointTest, pointCopyConstractor){
    ASSERT_EQ(Point(0,0),point);
}

TEST_F(PointTest, OperatorPrint){
    testing::internal::CaptureStdout();
    cout << point;
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("(0,0)\n",output);
}

TEST_F(PointTest, OperatorEq){
    bool b = false;
    int x = point.x();
    int y = point.y();
    if (x == 0 && y == 0) {
        b = true;
    }
    ASSERT_EQ(true,b);
}

