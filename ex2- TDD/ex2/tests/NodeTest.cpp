//
// Created by mei on 29/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "NodeMatrixTest.h"
#include "NodeTest.h"
using testing::Eq;
namespace {
    class  NodeTestImp : public testing::Test {
    public:

        NodeMatrix node;
        Node * n ;

        NodeTestImp() : node(-1,-1){
            node;
            n = &node;
            node.setDistance(0);

        }
    };
}

TEST_F(NodeTestImp, nodeGetDistance){
ASSERT_EQ(node.getDistance(),0);
}
TEST_F(NodeTestImp, nodeGetParent){
    Node* start=node.getParent() ;
     ASSERT_EQ(node.getParent(),start);
}
TEST_F(NodeTestImp, nodeSetParent){
    Matrix grid = Matrix(-1, -1);
    grid.getNode(-1, -1);
    NodeMatrix n;
    node.setParent(&n);
    ASSERT_EQ(node.getParent(),&n);

}

TEST_F(NodeTestImp, nodeSetDistance){
    node.setDistance(5);
    ASSERT_EQ(node.getDistance(),5);
}

TEST_F(NodeTestImp, nodeGetNeighbors){
    std::list<Node*> list;
    ASSERT_EQ(node.getNeighbors(),list);
}
TEST_F(NodeTestImp, operatorPrint){
    testing::internal::CaptureStdout();
    cout << node;
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("(0,0)",output);
}

TEST_F(NodeTestImp, addNeighbor){
    Node* n = new NodeMatrix(1,2);
    node.addNeighbor(n);
    ASSERT_EQ(n, node.getNeighbors().front());
}


