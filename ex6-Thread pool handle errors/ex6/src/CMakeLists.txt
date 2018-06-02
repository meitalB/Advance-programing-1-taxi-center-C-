cmake_minimum_required(VERSION 3.6)
project(Taxi-Center)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pthread -DELPP_THREAD_SAFE -DELPP_DISABLE_LOGS")

set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system regex)
include_directories(${Boost_INCLUDE_DIR})

set(SOURCE_FILES Serialization.h core/Point.cpp core/Point.h core/Node.cpp
        core/Node.h core/Matrix.cpp core/Matrix.h core/Grid.h core/BFS.cpp
        core/BFS.h core/NodeMatrix.cpp core/NodeMatrix.h persons/Driver.cpp persons/Driver.h
        persons/Passenger.h persons/Passenger.cpp cabs/TaxiCab.cpp cabs/TaxiCab.h Trip.h Trip.cpp cabs/LuxuryCab.cpp
        cabs/LuxuryCab.h cabs/StandardCab.cpp cabs/StandardCab.h Statistics.cpp Statistics.h persons/Person.cpp
        persons/Person.h TaxiCenter.cpp TaxiCenter.h cabs/Vehicle.cpp cabs/Vehicle.h creators/TripCreator.cpp
        creators/TripCreator.h creators/TaxiCreator.cpp creators/TaxiCreator.h creators/DriverCreator.cpp
        creators/DriverCreator.h Menu.cpp Menu.h Ride.cpp Ride.h Clock.cpp Clock.h creators/ThreadCreator.cpp creators/ThreadCreator.h
        logging/easylogging++.h logging/easylogging++.cpp InputParser.cpp InputParser.h Job.cpp Job.h ThreadPool.cpp ThreadPool.h)

set(SOCKETS_FILES sockets/TcpServer.cpp sockets/TcpServer.h  sockets/TcpClient.cpp sockets/TcpClient.h)
set(ELPP_MAJOR_VERSION "9")
set(ELPP_MINOR_VERSION "90")
set(ELPP_VERSION_STRING "${ELPP_MAJOR_VERSION}.${ELPP_MINOR_VERSION}")


set(ELPP_INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/include" CACHE PATH "The directory the headers are installed in")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
install(FILES
        logging/easylogging++.h
        logging/easylogging++.cpp
        DESTINATION "${ELPP_INCLUDE_INSTALL_DIR}"
        COMPONENT dev)

add_library(sockets ${SOCKETS_FILES})
add_library(core ${SOURCE_FILES})


add_executable(server server.cpp)
add_executable(client client.cpp)

target_link_libraries(server sockets core)
target_link_libraries(client sockets core)

target_link_libraries(server ${Boost_LIBRARIES})
target_link_libraries(client ${Boost_LIBRARIES})

