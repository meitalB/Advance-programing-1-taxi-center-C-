//
// Created by mei on 29/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/NodeMatrix.h"
#include "../src/Matrix.h"

using testing::Eq;
namespace {
    class  NodeTest : public testing::Test {
    public:

        NodeMatrix node;
        Node * n ;

        NodeTest() : node(-1,-1){
            node;
            n = &node;
            node.setDistance(0);

        }
    };
}

TEST_F(NodeTest, nodeGetDistance){
ASSERT_EQ(node.getDistance(),0);
}
TEST_F(NodeTest, nodeGetParent){
    Node* start = node.getParent() ;
     ASSERT_EQ(node.getParent(),start);
}
TEST_F(NodeTest, nodeSetParent){
    Matrix grid = Matrix(-1, -1);
    grid.getNode(-1, -1);
    NodeMatrix n;
    node.setParent(&n);
    ASSERT_EQ(node.getParent(),&n);

}

TEST_F(NodeTest, nodeSetDistance){
    node.setDistance(5);
    ASSERT_EQ(node.getDistance(),5);
}

TEST_F(NodeTest, nodeGetNeighbors){
    std::list<Node*> list;
    ASSERT_EQ(node.getNeighbors(),list);
}
TEST_F(NodeTest, operatorPrint){
    testing::internal::CaptureStdout();
    cout << node;
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("(-1,-1)\n" ,output);
}

TEST_F(NodeTest, addNeighbor){
    Node* n = new NodeMatrix(1,2);
    node.addNeighbor(n);
    ASSERT_EQ(n, node.getNeighbors().front());
    delete  n;
}


