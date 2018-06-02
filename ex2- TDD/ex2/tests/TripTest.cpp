//
// Created by mei on 29/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TripTest.h"
using  testing::Eq;
namespace {
    class  ClassDeclaration6 : public testing::Test {
    public:
        Trip trip;
        ClassDeclaration6() : trip(0,0,0,0,0.0,Point(0,0),Point(0,0),Point(0,0)){
            trip;
        }
    };
}
//getters ang setters
TEST_F(ClassDeclaration6, tripGetLength){
  ASSERT_EQ(0,trip.getlength());
}
////getters ang setters
TEST_F(ClassDeclaration6, tripSetLength){
    trip.setLength(1);
    ASSERT_EQ(1,trip.getlength());
}
//getters ang setters
TEST_F(ClassDeclaration6, tripGetRide){
    ASSERT_EQ(0,trip.getRide());
}
//getters ang setters
TEST_F(ClassDeclaration6, tripSetRide){
    trip.setRide(1);
    ASSERT_EQ(1,trip.getRide());
}
//getters ang setters
TEST_F(ClassDeclaration6, tripGetTotalmeters){
    ASSERT_EQ(0,trip.getTotalmeters());
}
//getters ang setters
TEST_F(ClassDeclaration6, tripSetTotalmeters){
    trip.setTotalMeters(1);
    ASSERT_EQ(1,trip.getRide());
}
//getters ang setters
TEST_F(ClassDeclaration6, tripGetNumberofPassangers){
    ASSERT_EQ(0,trip.getNumberofPassangers());
}
//getters ang setters
TEST_F(ClassDeclaration6, tripsetNumberofPassangers){
    trip.setNumberofPassangers(1);
    ASSERT_EQ(1,trip.getNumberofPassangers());
}
//getters ang setters
TEST_F(ClassDeclaration6, tripGettarrif){
    ASSERT_EQ(0,trip.getTarrif());
}
//getters ang setters
TEST_F(ClassDeclaration6, tripSetTarrif){
    trip.setTariff(1.1);
    ASSERT_EQ(1.1,trip.getTarrif());
}
//getters ang setters
TEST_F(ClassDeclaration6, tripGetStartPoint){
    ASSERT_EQ(Point(0,0),trip.getStartPoint());
}
//getters ang setters
TEST_F(ClassDeclaration6, tripSetStartPoint){
    trip.setStartPoint(Point(1,0));
    ASSERT_EQ(Point(1,0),trip.getStartPoint());
}
//getters ang setters
TEST_F(ClassDeclaration6, tripSetEndPoint){
    trip.setEndPoint(Point(1,0));
    ASSERT_EQ(Point(1,0),trip.getEndPoint());

}
//getters ang setters
TEST_F(ClassDeclaration6, tripGetCurrentPoint){
    ASSERT_EQ(Point(0,0),trip.getCurrentPoint());
}
//getters ang setters
TEST_F(ClassDeclaration6, tripSetCurrentPoint){
    trip.setCurrentPoint(Point(1,0));
    ASSERT_EQ(Point(1,0),trip.getCurrentPoint());

}

TEST_F(ClassDeclaration6, updateLocationTest){
    trip.updateLocation(Point(1,0));
    ASSERT_EQ(Point(1,0),trip.getCurrentPoint());

}
