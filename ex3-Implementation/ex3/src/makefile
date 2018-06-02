##########################
# 311124283   208388850  #
# birkame     simonoa    #
##########################
a.out: main.o BFS.o Driver.o DriverCreator.o LuxuryCab.o Matrix.o Menu.o Node.o NodeMatrix.o Passenger.o Person.o Point.o Ride.o StandardCab.o Statistics.o TaxiCab.o TaxiCenter.o TaxiCreator.o Trip.o TripCreator.o Vehicle.o 
	g++ -std=c++0x main.o BFS.o Driver.o DriverCreator.o LuxuryCab.o Matrix.o Menu.o Node.o NodeMatrix.o Passenger.o Person.o Point.o Ride.o StandardCab.o Statistics.o TaxiCab.o TaxiCenter.o TaxiCreator.o Trip.o TripCreator.o Vehicle.o

BFS.o: BFS.cpp BFS.h Grid.h Node.h 
	g++ -c -std=c++0x BFS.cpp

Driver.o: Driver.cpp Driver.h Person.h Trip.h
	g++ -c -std=c++0x Driver.cpp

DriverCreator.o: DriverCreator.cpp Driver.h 
	g++ -c -std=c++0x DriverCreator.cpp

LuxuryCab.o: LuxuryCab.cpp LuxuryCab.h TaxiCab.h
	g++ -c -std=c++0x LuxuryCab.cpp

Matrix.o: Matrix.cpp Matrix.h Grid.h NodeMatrix.h
	g++ -c -std=c++0x Matrix.cpp

Menu.o: Menu.cpp Menu.h DriverCreator.h TripCreator.h TaxiCenter.h Grid.h
	g++ -c -std=c++0x Menu.cpp

Node.o: Node.cpp Node.h 
	g++ -c -std=c++0x Node.cpp

NodeMatrix.o: NodeMatrix.cpp NodeMatrix.h Node.h Point.h
	g++ -c -std=c++0x NodeMatrix.cpp

Passenger.o: Passenger.cpp Passenger.h Point.h Person.h
	g++ -c -std=c++0x Passenger.cpp

Person.o: Person.cpp Person.h Point.h
	g++ -c -std=c++0x Person.cpp

Point.o: Point.cpp Point.h Node.h
	g++ -c -std=c++0x Point.cpp

Ride.o: Ride.cpp Ride.h Trip.h Driver.h TaxiCab.h
	g++ -c -std=c++0x Ride.cpp

StandardCab.o: StandardCab.cpp StandardCab.h TaxiCab.h
	g++ -c -std=c++0x StandardCab.cpp

Statistics.o: Statistics.cpp Statistics.h Person.h
	g++ -c -std=c++0x Statistics.cpp

TaxiCab.o: TaxiCab.cpp TaxiCab.h Vehicle.h
	g++ -c -std=c++0x TaxiCab.cpp

TaxiCenter.o: TaxiCenter.cpp TaxiCenter.h Driver.h TaxiCab.h Trip.h Ride.h
	g++ -c -std=c++0x TaxiCenter.cpp

TaxiCreator.o: TaxiCreator.cpp TaxiCreator.h TaxiCab.h
	g++ -c -std=c++0x TaxiCreator.cpp

Trip.o: Trip.cpp Trip.h Point.h
	g++ -c -std=c++0x Trip.cpp

TripCreator.o: TripCreator.cpp TripCreator.h Trip.h Matrix.h
	g++ -c -std=c++0x TripCreator.cpp

Vehicle.o: Vehicle.cpp Vehicle.h 
	g++ -c -std=c++0x Vehicle.cpp


main.o: main.cpp Driver.h Matrix.h TaxiCenter.h Menu.h
	g++ -c -std=c++0x main.cpp

