cmake_minimum_required(VERSION 3.3)

set(REPO ~/ClionProjects/.repo)

project(ex2ap)

include(CTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
set(test_SRCS PointTest.cpp NodeMatrixTest.cpp DriverTest.cpp
        PassengerTest.cpp TaxiCabTest.cpp BFSTest.cpp NodeTest.cpp
        TripTest.cpp GridTest.cpp LuxuryCabTest.cpp
        MatrixTest.cpp StandartCabTest.cpp StatisticsTest.cpp
        TaxiCenterTest.cpp)

include(${REPO}/DownloadProject/DownloadProject.cmake)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)



add_executable(runUnitTests ${test_SRCS} gtest.cpp)

target_link_libraries(runUnitTests gtest gmock core)
add_test(runUnitTests runUnitTests) #included in all tutorials but I don't know what it actually does.



