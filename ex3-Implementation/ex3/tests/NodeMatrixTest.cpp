//
// Created by mei on 29/11/16.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/NodeMatrix.h"

using testing::Eq;
class  NodeMatrixTest : public testing::Test {
public:
    NodeMatrix nodeMatrix;
    NodeMatrixTest() : nodeMatrix(-1,-1){
    }
};

TEST_F(NodeMatrixTest, NodeGetPoint){
    ASSERT_EQ(nodeMatrix.getPoint(),Point(-1,-1));
}

TEST_F(NodeMatrixTest, OperatorEq){
    ASSERT_EQ(nodeMatrix, NodeMatrix(-1,-1));
}

TEST_F(NodeMatrixTest, OperatorPrint){
testing::internal::CaptureStdout();
cout << nodeMatrix;
string output = testing::internal::GetCapturedStdout();
ASSERT_EQ("(-1,-1)\n",output);
}




