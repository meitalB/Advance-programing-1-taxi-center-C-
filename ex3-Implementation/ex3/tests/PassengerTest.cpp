//
// Created by mei on 29/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Passenger.h"

using  testing::Eq;
namespace {
    class  PassengerTest : public testing::Test {
    public:
        Passenger passenger;
        PassengerTest() : passenger(0, 0, MARRIED, Point(0, 0), Point(0, 0), Point(1, 1)) {
        }
    };
}
//getters ang setters
TEST_F(PassengerTest, passangerGetStartPoint){
    ASSERT_EQ(Point(0,0),passenger.getSourcePoint());
}
TEST_F(PassengerTest, passangerSetStartPoint){
    passenger.setSourcePoint(Point(0,1));
    ASSERT_EQ(Point(0,1),passenger.getSourcePoint());
}
TEST_F(PassengerTest, passangerSetDestanationPoint){
    passenger.setDestinationPoint(Point(0, 1));
    ASSERT_EQ(Point(0,1),passenger.getDestinationPoint());
}
TEST_F(PassengerTest, passangerGetDestanationPoint){
    ASSERT_EQ(Point(1,1), passenger.getDestinationPoint());
}
