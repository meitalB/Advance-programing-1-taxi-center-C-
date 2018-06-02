//
// Created by mei on 29/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/TaxiCab.h"

using  testing::Eq;
namespace {
    class  TaxiCabTest : public testing::Test {
    public:
        TaxiCab taxi;
        TaxiCabTest() : taxi(HONDA, RED,0,0,0){
        }
    };
}
TEST_F(TaxiCabTest,taxiGetIDCab){
    ASSERT_EQ(0, taxi.getId());
}
TEST_F(TaxiCabTest, taxisetIDCab){
    taxi.setId(1);
    ASSERT_EQ(1, taxi.getId());
}
TEST_F(TaxiCabTest,taxiGetnumberOfKilometers){
    ASSERT_EQ(0, taxi.getKilometers());
}
TEST_F(TaxiCabTest, taxiSetnumberOfKilometers){
    taxi.setKilometers(1);
    ASSERT_EQ(1, taxi.getKilometers());
}
TEST_F(TaxiCabTest,taxiGetTariff){
    ASSERT_EQ(0,taxi.getTariff());
}
TEST_F(TaxiCabTest, taxiSetTariff){
    taxi.setTariff(1);
    ASSERT_EQ(1,taxi.getTariff());
}