//
// Created by mei on 29/11/16.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "NodeMatrixTest.h"
using testing::Eq;
class  NodeMatrixTestImp : public testing::Test {
public:
    NodeMatrix nodeMatrix;
    NodeMatrixTestImp() : nodeMatrix(-1,-1){
    }
};

TEST_F(NodeMatrixTestImp, NodeGetPoint){
    ASSERT_EQ(nodeMatrix.getPoint(),Point(-1,-1));
}

TEST_F(NodeMatrixTestImp, OperatorEq){
    ASSERT_EQ(nodeMatrix.getPoint(),Point(-1,-1));
}

TEST_F(NodeMatrixTestImp, OperatorPrint){
testing::internal::CaptureStdout();
cout << nodeMatrix;
string output = testing::internal::GetCapturedStdout();
ASSERT_EQ("(0,0)",output);
}




