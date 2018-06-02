//
// Created by mei on 03/12/16.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TaxiCenterTest.h"
namespace {
    class  TaxiCenterTestImp : public testing::Test {
    protected:
        TaxiCenter taxiCenter;
        TaxiCenterTestImp(): taxiCenter(){}
    };
}

TEST_F(TaxiCenterTestImp, answerCall){
}
TEST_F(TaxiCenterTestImp, sendTexi) {
}
