//
// Created by mei on 29/11/16.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Driver.h"


using  testing::Eq;
namespace {
    class DriverTest : public testing::Test {
    public:

        Driver driver;

        DriverTest() : driver(Point(0,0), 0, 9, 5, 6, SINGLE) {
        }
    };
}


TEST_F(DriverTest, driverGetID){
ASSERT_EQ(0,driver.getId());
}

TEST_F(DriverTest, driverSetId){
    driver.setId(1);
    ASSERT_EQ(1,driver.getId());
}

TEST_F(DriverTest, driverGetAge){
    ASSERT_EQ(9,driver.getAge());
}

TEST_F(DriverTest, driverSetAge){
    driver.setAge(1);
    ASSERT_EQ(1,driver.getAge());
}

TEST_F(DriverTest, driverGetYearsOfExperience){
    ASSERT_EQ(5,driver.getYearsOfExperience());
}

TEST_F(DriverTest, driverSetYearsOfExperience){
    driver.setYearsOfExperience(1);
    ASSERT_EQ(1,driver.getYearsOfExperience());
}

TEST_F(DriverTest, driverGetaverageSatisfaction){
    ASSERT_EQ(6, driver.getAverageSatisfaction());
}

TEST_F(DriverTest, driverSetaverageSatisfaction){
    driver.setAverageSatisfaction(1);
    ASSERT_EQ(1, driver.getAverageSatisfaction());
}

TEST_F(DriverTest, driverGetmaritalstatus){
    ASSERT_EQ(driver.getStatus(), SINGLE);
}

TEST_F(DriverTest, driverSetmaritalstatus){
    driver.setMaritalStatus(DIVORCED);
    ASSERT_EQ(DIVORCED , driver.getStatus());
}