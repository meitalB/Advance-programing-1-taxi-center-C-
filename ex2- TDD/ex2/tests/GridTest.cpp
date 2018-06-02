#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "GridTest.h"
#include "../src/Matrix.h"

using  testing::Eq;
namespace {
    class GridTestImp : public testing::Test {
    public:
        Matrix matrix;
        Grid *grid;
        GridTestImp() : matrix(10, 10) {
            grid = &matrix;
        }
    };
}

TEST_F(GridTestImp, getNode){
    Node* n = grid->getNode(2,3);
    Node* n2 = new NodeMatrix(2,3);
    ASSERT_EQ(n2, n);
    delete n2;
}

TEST_F(GridTestImp, initDistanceForAll){
    int d = 3;
    grid->initDistanceForAll(d);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            Node*  n = grid->getNode(i,j);
            ASSERT_EQ(d, n->getDistance());
        }
    }
}