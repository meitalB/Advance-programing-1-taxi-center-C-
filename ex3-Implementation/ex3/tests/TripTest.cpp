//
// Created by mei on 29/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Trip.h"

using  testing::Eq;
namespace {
    class  TripTest : public testing::Test {
    public:
        Trip trip;
        TripTest() : trip(0,0,0,0,0.0,Point(0,0),Point(0,0)){
            trip;
        }
    };
}
//getters ang setters
TEST_F(TripTest, tripGetLength){
  ASSERT_EQ(0, trip.getLength());
}
//getters ang setters
TEST_F(TripTest, tripSetLength){
    trip.setLength(1);
    ASSERT_EQ(1, trip.getLength());
}

////getters ang setters
//TEST_F(TripTest, tripGetRide){
//    ASSERT_EQ(0,trip.getRide());
//}
////getters ang setters
//TEST_F(TripTest, tripSetRide){
//    trip.setRide(1);
//    ASSERT_EQ(1,trip.getRide());
//}

//getters ang setters
TEST_F(TripTest, tripGetTotalmeters){
    ASSERT_EQ(0, trip.getTotalMeters());
}
//getters ang setters
TEST_F(TripTest, tripSetTotalmeters){
    trip.setTotalMeters(1);
    ASSERT_EQ(1,trip.getTotalMeters());
}
//getters ang setters
TEST_F(TripTest, tripGetNumberofPassangers){
    ASSERT_EQ(0, trip.getNumberOfPassengers());
}
//getters ang setters
TEST_F(TripTest, tripsetNumberofPassangers){
    trip.setNumberOfPassengers(1);
    ASSERT_EQ(1, trip.getNumberOfPassengers());
}
//getters ang setters
TEST_F(TripTest, tripGettarrif){
    ASSERT_EQ(0, trip.getTariff());
}
//getters ang setters
TEST_F(TripTest, tripSetTarrif){
    trip.setTariff(1.1);
    ASSERT_EQ(1.1, trip.getTariff());
}
//getters ang setters
TEST_F(TripTest, tripGetStartPoint){
    ASSERT_EQ(Point(0,0),trip.getStartPoint());
}
//getters ang setters
TEST_F(TripTest, tripSetStartPoint){
    trip.setStartPoint(Point(1,0));
    ASSERT_EQ(Point(1,0),trip.getStartPoint());
}
//getters ang setters
TEST_F(TripTest, tripSetEndPoint){
    trip.setEndPoint(Point(1,0));
    ASSERT_EQ(Point(1,0),trip.getEndPoint());

}
//getters ang setters
TEST_F(TripTest, tripGetCurrentPoint){
    ASSERT_EQ(Point(0,0),trip.getCurrentPoint());
}
//getters ang setters
TEST_F(TripTest, tripSetCurrentPoint){
    trip.setCurrentPoint(Point(1,0));
    ASSERT_EQ(Point(1,0),trip.getCurrentPoint());

}

TEST_F(TripTest, updateLocationTest){
    trip.updateLocation(Point(1,0));
    ASSERT_EQ(Point(1,0),trip.getCurrentPoint());

}
