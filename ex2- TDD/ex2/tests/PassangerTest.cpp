//
// Created by mei on 29/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "PassangerTest.h"
using  testing::Eq;
namespace {
    class  ClassDeclaration7 : public testing::Test {
    public:
        Passanger passenger;
        ClassDeclaration7() : passenger(Point(0,0),Point(1,1)){
        }
    };
}
//getters ang setters
TEST_F(ClassDeclaration7, passangerProduceRandomScore){
    ASSERT_EQ(0,passenger.produceRandomScore());
}
TEST_F(ClassDeclaration7, passangerGetStartPoint){
    ASSERT_EQ(Point(0,0),passenger.getSourcePoint());
}
TEST_F(ClassDeclaration7, passangerSetStartPoint){
    passenger.setSourcePoint(Point(0,1));
    ASSERT_EQ(Point(0,1),passenger.getSourcePoint());
}
TEST_F(ClassDeclaration7, passangerSetDestanationPoint){
    passenger.setDestenationPoint(Point(0,1));
    ASSERT_EQ(Point(0,1),passenger.getSourcePoint());
}
TEST_F(ClassDeclaration7, passangerGetDestanationPoint){
    ASSERT_EQ(Point(0,0),passenger.getSourcePoint());
}
