//
// Created by mei on 03/12/16.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/TaxiCenter.h"

namespace {
    class  TaxiCenterTest : public testing::Test {
    protected:
        TaxiCenter taxiCenter;
        TaxiCenterTest(): taxiCenter(){}
    };
}

TEST_F(TaxiCenterTest, answerCall){
}
TEST_F(TaxiCenterTest, sendTexi) {
}
