cmake_minimum_required(VERSION 3.3)

project(ex2ap)

include(CTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
set(test_SRCS PointTest.cpp PointTest.h NodeMatrixTest.cpp NodeMatrixTest.h DriverTest.h DriverTest.cpp
        PassangerTest.cpp PassangerTest.h TaxiCabTest.cpp TaxiCabTest.h BFSTest.cpp BFSTest.h NodeTest.cpp
        NodeTest.h TripTest.cpp TripTest.h GridTest.cpp GridTest.h LuxuryCabTest.cpp LuxuryCabTest.h
        MatrixTest.cpp MatrixTest.h StandartCabTest.cpp StandartCabTest.h StatisticsTest.cpp
        StatisticsTest.h TaxiCenterTest.cpp TaxiCenterTest.h)
add_executable(runUnitTests ${test_SRCS} gtest.cpp)

target_link_libraries(runUnitTests gtest gmock core)
add_test(runUnitTests runUnitTests) #included in all tutorials but I don't know what it actually does.



