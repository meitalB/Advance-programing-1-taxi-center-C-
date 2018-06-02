//
// Created by mei on 02/12/16.
//

#include "MatrixTest.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using  testing::Eq;
namespace {
    class ClassDeclaration13 : public testing::Test {
    public:
        Matrix matrix;
        ClassDeclaration13() : matrix(10 ,10){}

    };
}

TEST_F(ClassDeclaration13, getNode){
    Node* n = matrix.getNode(2,3);
    Node* n2 = new NodeMatrix(2,3);
    ASSERT_EQ(n2, n);
    delete(n2);
}

TEST_F(ClassDeclaration13, initDistanceForAll){
    int d = 3;
    matrix.initDistanceForAll(d);
    for (int i = 0; i < matrix.getWidth(); ++i) {
        for (int j = 0; j < matrix.getHeight(); ++j) {
            Node*  n = matrix.getNode(i,j);
            ASSERT_EQ(d, n->getDistance());
        }
    }
}
TEST_F(ClassDeclaration13, getWidth){
    ASSERT_EQ(10, matrix.getWidth());
}

TEST_F(ClassDeclaration13, getHight){
    ASSERT_EQ(10, matrix.getHeight());
}