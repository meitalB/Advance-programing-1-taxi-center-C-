//
// Created by noam on 16/12/16.
//

#include "DriverCreator.h"
//define the status as macro
Driver createDriver(int id, int age, char status, int experience, int vehicleId, TaxiCenter center){
    STATUS st;
    switch(status){
        case 'S':
            st = SINGLE;
            break;
        case 'M':
            st = MARRIED;
            break;
        case 'D':
            st = DIVORCED;
            break;
        case 'W':
            st = WIDOWED;
            break;
        default:
            st = SINGLE;
            break;
    }

//return the new driver
    return Driver(Point(0,0), id, age, experience, 0, st, center.getTaxi(vehicleId));
}