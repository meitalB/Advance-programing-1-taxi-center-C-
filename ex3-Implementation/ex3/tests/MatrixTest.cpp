//
// Created by mei on 02/12/16.
//

#include "../src/Matrix.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using  testing::Eq;
namespace {
    class MatrixTest : public testing::Test {
    public:
        Matrix matrix;
        MatrixTest() : matrix(10 ,10) {}
    };
}

TEST_F(MatrixTest, getNode){
    Node* n = matrix.getNode(2,3);
    Node* n2 = new NodeMatrix(2,3);
    ASSERT_EQ(*n2, *n);
    delete(n2);
}

TEST_F(MatrixTest, initDistanceForAll){
    int d = 3;
    matrix.initDistanceForAll(d);
    for (int i = 0; i < matrix.getWidth(); ++i) {
        for (int j = 0; j < matrix.getHeight(); ++j) {
            Node*  n = matrix.getNode(i,j);
            ASSERT_EQ(d, n->getDistance());
        }
    }
}
TEST_F(MatrixTest, getWidth){
    ASSERT_EQ(10, matrix.getWidth());
}

TEST_F(MatrixTest, getHight){
    ASSERT_EQ(10, matrix.getHeight());
}