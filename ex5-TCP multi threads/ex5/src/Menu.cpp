//
//  Created by noam on 16/12/16.
//

#include "Menu.h"
#include "creators/ThreadCreator.h"
#include <pthread.h>

//  run the input to the program
void Menu::run() {
    getObstacles();
    cin.ignore();
    int option;
    cin >> option;
    while (option != 7) {
        cin.ignore();
        switch (option) {
            case 1: //insert drivers
                expectingDriver();
                break;
            case 2: //insert trip
                insertTrip();
                break;
            case 3: //insert taxi
                insertTaxi();
                break;
            case 4: //get the drivers location
                getDriverLocation();
                break;
            case 6: //move all the drivers to end
                moveAllDriversToTheEnd();
                break;
            case 9:// move the drivers to the next point.
                this->taxiCenter->moveAllRidesOneStep();
                break;
            default:
                break;
        }
        cin >> option;
    }
    return;
}

//insert a new taxi from the input arguments
void Menu::insertTaxi() {
    char dummy;
    int id, taxiType;
    char manufacturer, color;
    std::cin >> id >> dummy >> taxiType >> dummy >> manufacturer >> dummy >> color;
    //create the taxi
    TaxiCab* cab = createTaxi(id, taxiType, manufacturer, color);
    this->taxiCenter->addTaxiCab(cab);
    

}

//expecting a new driver from the client
void Menu::expectingDriver() {
    int numOfDrivers;
    std::cin >> numOfDrivers;

    for (int i = 0; i < numOfDrivers; ++i) {
        taxiCenter->addClient();
    }
}

//insert a new trip from the input arguments
void Menu::insertTrip() {
    char dummy;
    int id;
    int xStart, yStart, xEnd, yEnd;
    int numOfPass;
    double tariff;
    int timeOfStart;
    std::cin >> id >> dummy >> xStart >> dummy >> yStart >> dummy >> xEnd
             >> dummy >> yEnd >> dummy >> numOfPass >> dummy >> tariff
             >> dummy >>timeOfStart;
    //create the trip
    tripAndThread newTrip = createTrip(grid, id, xStart, yStart, xEnd, yEnd,
                              numOfPass, tariff, timeOfStart);

    taxiCenter->insertTrip(newTrip);
}

//create obstacles from the input arguments
void Menu::getObstacles() {
    int numOfObstacles;
    char dummy;
    int x;
    int y;
    //num of obstacles
    std::cin >> numOfObstacles;
    while (numOfObstacles > 0) {
        std::cin >> x >> dummy  >> y;
        Node* n = new NodeMatrix(x, y);
        this->grid->addObstacle(n);
        delete n;
        numOfObstacles--;
    }

}

//get the driver location from the input arguments
void Menu::getDriverLocation() {
    int idDriver;
    std::cin >> idDriver;
    std::cout << this->taxiCenter->getDriverLocation(idDriver);
}

// move all the drivers to the next node in the trip
void Menu::moveAllDriversToTheEnd() {
    this->taxiCenter->moveAllRidesToTheEnd();
}

//constructor to a new
Menu::Menu(TaxiCenter *taxiCenter, Matrix *grid)
        : grid(grid), taxiCenter(taxiCenter) {}




//void Menu::clientFunction(int client_socket) {
//
//    unsigned long readBytes;
//    char buffer[1024];
//    std::fill_n(buffer, 1024, 0);
//    readBytes = tcp->receiveData(buffer, sizeof(buffer), client_socket);
//
//    // deserialize driver
//    string serial_str_driver(buffer, readBytes);
//    Driver *d = deserialize<Driver>(serial_str_driver);
//
//    TaxiCab* taxiCab = taxiCenter->getTaxi(d->getVehicleId());
//
//    //serialize taxi
//    string serial_str_taxi = serialize(taxiCab);
//    //sent back the taxi
//    tcp->sendData(serial_str_taxi, client_socket);
//
//    //add driver to the taxi-center.
//    taxiCenter->clientFunction(d, client_socket);
//}
//
//void* Menu::threadFunction(void* element) {
//    ClientData* data = (ClientData*) element;
//    data->menu->clientFunction(data->client_socket);
//    data = NULL;
//    return NULL;
//}


//class DriverAgrs{
//public:
//    TaxiCenter* taxiCenter;
//    TcpServer* tcp;
//    bool stop;
//    DriverAgrs(TaxiCenter* taxiCenter, TcpServer* tcp, bool stop) {
//        this->taxiCenter = taxiCenter;
//        this->tcp = tcp;
//        this->stop = stop;
//    }
//};


//pass date from server<->client
//void Menu::updatesFromClient() {
//    unsigned long readBytes;
//    char buffer[1024];
//    std::fill_n(buffer, 1024, 0);
//    readBytes = this->tcp->receiveData(buffer, sizeof(buffer));
//
//    // deserialize driver
//    string serial_str_driver(buffer, readBytes);
//    Driver *d = deserialize<Driver>(serial_str_driver);
//
//    TaxiCab* taxiCab = this->taxiCenter->getTaxi(d->getVehicleId());
//
//    //serialize taxi
//    string serial_str_taxi = serialize(taxiCab);
//    //sent back the taxi
//    this->tcp->sendData(serial_str_taxi);
//
//    //add driver to the taxi-center.
//    this->taxiCenter->clientFunction(d);

//}