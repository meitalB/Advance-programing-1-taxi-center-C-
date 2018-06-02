//
// Created by mei on 29/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TaxiCabTest.h"

using  testing::Eq;
namespace {
    class  ClassDeclaration10 : public testing::Test {
    public:
        TaxiCab taxi;
        ClassDeclaration10() : taxi(0,0,0){
        }
    };
}
TEST_F(ClassDeclaration10,taxiGetIDCab){
    ASSERT_EQ(0,taxi.getCabId());
}
TEST_F(ClassDeclaration10, taxisetIDCab){
    taxi.setCabId(1);
    ASSERT_EQ(1,taxi.getCabId());
}
TEST_F(ClassDeclaration10,taxiGetnumberOfKilometers){
    ASSERT_EQ(0,taxi.getnumberOfKilometers());
}
TEST_F(ClassDeclaration10, taxiSetnumberOfKilometers){
    taxi.setnumberOfKilometers(1);
    ASSERT_EQ(1,taxi.getnumberOfKilometers());
}
TEST_F(ClassDeclaration10,taxiGetTariff){
    ASSERT_EQ(0,taxi.getTariff());
}
TEST_F(ClassDeclaration10, taxiSetTariff){
    taxi.setTariff(1);
    ASSERT_EQ(1,taxi.getTariff());
}