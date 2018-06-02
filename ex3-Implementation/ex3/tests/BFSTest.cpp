//
// Created by mei on 29/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/BFS.h"
#include "../src/Matrix.h"

using testing::Eq;
namespace {
    class  BFSTest : public testing::Test {
    public:
        BFS bfs;
        BFSTest() : bfs(){
            bfs;
        }
    };
}
TEST_F(BFSTest, BFSfunc){
    int width = 4;
    int height = 4;
    int startX = 0;
    int startY = 1;
    int endX = 3;
    int endY = 4;
    std::list<Node*> list;
    Matrix grid = Matrix(width, height);
    Node* start = grid.getNode(startX, startY);
    Node* end = grid.getNode(endX,endY);
    for (int j = startX; j < endX ; ++j) {
        for (int i = startY; i < endY ; ++i) {
            list.push_back(grid.getNode(j,i));
        }

    }
    std::list<Node*> list1 = bfs.funcBFS(start,end);
    while (!list1.empty()) {
        ASSERT_EQ(list1.front(),list.front());
        list1.pop_front();
        list.pop_front();
    }
}
