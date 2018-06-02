//
// Created by mei on 29/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BFSTest.h"

using testing::Eq;
namespace {
    class  ClassDeclaration4 : public testing::Test {
    public:
        BFS bfs;
        ClassDeclaration4() : bfs(){
            bfs;
        }
    };
}
TEST_F(ClassDeclaration4, BFSfunc){
    Matrix grid = Matrix(-1, -1);
   Node* start = grid.getNode(-1, -1);
    std::list<Node*> list;
    list.push_back(start);
    ASSERT_EQ(bfs.funcBFS(start,start),list);
}
