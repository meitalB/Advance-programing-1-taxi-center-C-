#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "PointTest.h"

using  testing::Eq;
namespace {
    class  ClassDeclaration : public testing::Test {
    public:
        Point point;
        ClassDeclaration() : point(0,0){}
    };
}
TEST_F(ClassDeclaration, pointGetX){
    ASSERT_EQ(0,point.x());
}
TEST_F(ClassDeclaration, pointGetY){
    ASSERT_EQ(0,point.y());
}
TEST_F(ClassDeclaration, pointCopyConstractor){
    ASSERT_EQ(Point(0,0),point);
}

TEST_F(ClassDeclaration, OperatorPrint){
    testing::internal::CaptureStdout();
    cout << point;
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("(0,0)",output);
}

TEST_F(ClassDeclaration, OperatorEq){
    bool b = false;
    int x = point.x();
    int y = point.y();
    if (x == 0 && y == 0) {
        b = true;
    }
    ASSERT_EQ(true,b);
}

