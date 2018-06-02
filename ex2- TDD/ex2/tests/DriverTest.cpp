//
// Created by mei on 29/11/16.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "DriverTest.h"
using  testing::Eq;
namespace {
    class DriverTestImp : public testing::Test {
    public:

        Driver driver;

        DriverTestImp() : driver(0, 0, 0, 0, 1) {
        }
    };
}


TEST_F(DriverTestImp, driverGetID){
ASSERT_EQ(0,driver.getId());
}
TEST_F(DriverTestImp, driverSetId){
    driver.setId(1);
    ASSERT_EQ(1,driver.getId());
}
TEST_F(DriverTestImp, driverGetAge){
ASSERT_EQ(0,driver.getAge());
}
TEST_F(DriverTestImp, driverSetAge){
    driver.setAge(1);
    ASSERT_EQ(1,driver.getAge());
}

TEST_F(DriverTestImp, driverGetYearsOfExperience){
    ASSERT_EQ(0,driver.getYearsOfExperience());
}
TEST_F(DriverTestImp, driverSetYearsOfExperience){
    driver.setyearsOfExperience(1);
    ASSERT_EQ(1,driver.getYearsOfExperience());
}

TEST_F(DriverTestImp, driverGetaverageSatisfaction){
    ASSERT_EQ(0,driver.getaverageSatisfaction());
}
TEST_F(DriverTestImp, driverSetaverageSatisfaction){
    driver.setaverageSatisfaction(1);
    ASSERT_EQ(1,driver.getYearsOfExperience());
}
TEST_F(DriverTestImp, driverGetmaritalstatus){
    int i = 1;
    ASSERT_EQ(i ,driver.getMaritalstatus());
}
TEST_F(DriverTestImp, driverSetmaritalstatus){
    driver.setMaritalStatus(1);
    int i = 1;
    ASSERT_EQ(i ,driver.getMaritalstatus());
}