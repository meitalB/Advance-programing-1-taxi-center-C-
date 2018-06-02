##########################
# 311124283   208388850  #
# birkame     simonno    #
##########################

all: server.out client.out

server.out: server.o Point.o Node.o Matrix.o BFS.o NodeMatrix.o Driver.o Passenger.o TaxiCab.o Trip.o LuxuryCab.o StandardCab.o Statistics.o Person.o TaxiCenter.o Vehicle.o TripCreator.o TaxiCreator.o DriverCreator.o Menu.o Ride.o Clock.o TcpServer.o ThreadCreator.o
	g++ -g -o server.out server.o Point.o Node.o Matrix.o BFS.o NodeMatrix.o Driver.o Passenger.o TaxiCab.o Trip.o LuxuryCab.o StandardCab.o Statistics.o Person.o TaxiCenter.o Vehicle.o TripCreator.o TaxiCreator.o DriverCreator.o Menu.o Ride.o Clock.o TcpServer.o ThreadCreator.o -pthread -lboost_serialization

client.out: client.o Point.o Node.o Matrix.o BFS.o NodeMatrix.o Driver.o Passenger.o TaxiCab.o Trip.o LuxuryCab.o StandardCab.o Statistics.o Person.o TaxiCenter.o Vehicle.o TripCreator.o TaxiCreator.o DriverCreator.o Menu.o Ride.o Clock.o TcpClient.o ThreadCreator.o TcpServer.o
	g++ -g -o client.out client.o Point.o Node.o Matrix.o BFS.o NodeMatrix.o Driver.o Passenger.o TaxiCab.o Trip.o LuxuryCab.o StandardCab.o Statistics.o Person.o TaxiCenter.o Vehicle.o TripCreator.o TaxiCreator.o DriverCreator.o Menu.o Ride.o Clock.o TcpClient.o ThreadCreator.o TcpServer.o -pthread -lboost_serialization

client.o: src/client.cpp src/persons/Driver.h src/creators/DriverCreator.h src/sockets/TcpClient.h src/Serialization.h
	g++ -g -c src/client.cpp

server.o: src/server.cpp src/TaxiCenter.h src/Menu.h src/core/Matrix.h
	g++ -g -c src/server.cpp

Menu.o: src/Menu.cpp src/Menu.h src/creators/DriverCreator.h src/creators/TripCreator.h src/creators/TaxiCreator.h src/TaxiCenter.h src/core/Grid.h src/Clock.h src/core/Matrix.h src/Serialization.h src/creators/ThreadCreator.h src/sockets/TcpServer.h
	g++ -g -c -std=c++0x src/Menu.cpp

BFS.o: src/core/BFS.cpp src/core/BFS.h src/core/Grid.h src/core/Node.h
	g++ -g -c -std=c++0x src/core/BFS.cpp

Clock.o: src/Clock.cpp src/Clock.h
	g++ -g -c -std=c++0x src/Clock.cpp
 
Driver.o: src/persons/Driver.cpp src/persons/Driver.h src/persons/Person.h src/Trip.h src/cabs/TaxiCab.h
	g++ -g -c -std=c++0x src/persons/Driver.cpp

DriverCreator.o: src/creators/DriverCreator.cpp src/persons/Driver.h src/TaxiCenter.h
	g++ -g -c -std=c++0x src/creators/DriverCreator.cpp

LuxuryCab.o: src/cabs/LuxuryCab.cpp src/cabs/LuxuryCab.h src/cabs/TaxiCab.h
	g++ -g -c -std=c++0x src/cabs/LuxuryCab.cpp

Matrix.o: src/core/Matrix.cpp src/core/Matrix.h src/core/Grid.h src/core/NodeMatrix.h
	g++ -g -c -std=c++0x src/core/Matrix.cpp

Node.o: src/core/Node.cpp src/core/Node.h
	g++ -g -c -std=c++0x src/core/Node.cpp

NodeMatrix.o: src/core/NodeMatrix.cpp src/core/NodeMatrix.h src/core/Node.h src/core/Point.h
	g++ -g -c -std=c++0x src/core/NodeMatrix.cpp

Passenger.o: src/persons/Passenger.cpp src/persons/Passenger.h src/core/Point.h src/persons/Person.h
	g++ -g -c -std=c++0x src/persons/Passenger.cpp

Person.o: src/persons/Person.cpp src/persons/Person.h src/core/Point.h
	g++ -g -c -std=c++0x src/persons/Person.cpp

Point.o: src/core/Point.cpp src/core/Point.h src/core/Node.h
	g++ -g -c -std=c++0x src/core/Point.cpp

Ride.o: src/Ride.cpp src/Ride.h src/Clock.h src/Trip.h src/persons/Driver.h src/cabs/TaxiCab.h
	g++ -g -c -std=c++0x src/Ride.cpp

StandardCab.o: src/cabs/StandardCab.cpp src/cabs/StandardCab.h src/cabs/TaxiCab.h
	g++ -g -c -std=c++0x src/cabs/StandardCab.cpp

Statistics.o: src/Statistics.cpp src/Statistics.h src/persons/Person.h
	g++ -g -c -std=c++0x src/Statistics.cpp

TaxiCab.o: src/cabs/TaxiCab.cpp src/cabs/TaxiCab.h src/cabs/Vehicle.h
	g++ -g -c -std=c++0x src/cabs/TaxiCab.cpp

TaxiCenter.o: src/TaxiCenter.cpp src/TaxiCenter.h src/persons/Driver.h src/cabs/TaxiCab.h src/Trip.h src/Ride.h src/sockets/TcpServer.h
	g++ -g -c -std=c++0x src/TaxiCenter.cpp

TaxiCreator.o: src/creators/TaxiCreator.cpp src/creators/TaxiCreator.h src/cabs/TaxiCab.h
	g++ -g -c -std=c++0x src/creators/TaxiCreator.cpp

Trip.o: src/Trip.cpp src/Trip.h src/core/Point.h
	g++ -g -c -std=c++0x src/Trip.cpp

TripCreator.o: src/creators/TripCreator.cpp src/creators/TripCreator.h src/Trip.h src/core/Matrix.h src/creators/ThreadCreator.h
	g++ -g -c -std=c++0x src/creators/TripCreator.cpp

ThreadCreator.o: src/creators/ThreadCreator.cpp src/creators/ThreadCreator.h src/core/Matrix.h src/persons/Driver.h src/Serialization.h src/TaxiCenter.h
	g++ -g -c -std=c++0x src/creators/ThreadCreator.cpp

Vehicle.o: src/cabs/Vehicle.cpp src/cabs/Vehicle.h
	g++ -g -c -std=c++0x src/cabs/Vehicle.cpp

TcpServer.o: src/sockets/TcpServer.h src/sockets/TcpServer.cpp
	g++ -g -c -std=c++0x src/sockets/TcpServer.cpp

TcpClient.o: src/sockets/TcpClient.h src/sockets/TcpClient.cpp
	g++ -g -c -std=c++0x src/sockets/TcpClient.cpp

clean:
	rm -f *.o *.out
