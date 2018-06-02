//
// Created by noam on 12/12/16.
//

#ifndef EX2AP_VEHICLE_H
#define EX2AP_VEHICLE_H

enum MANUFACTURER {HONDA, SUBARO, TESLA, FIAT};
enum COLOR {RED, GREEN, BLUE, PINK, WHITE};

class Vehicle {
protected:
    MANUFACTURER manu;
    COLOR c;
public:
    //constractor
    Vehicle(MANUFACTURER carManufacturer, COLOR c);

    //get the COLOR of the Vehicle
    COLOR getColor();

    //get the MANUFACTURER of the Vehicle
    MANUFACTURER  getCarManufacturer();
};


#endif //EX2AP_VEHICLE_H
