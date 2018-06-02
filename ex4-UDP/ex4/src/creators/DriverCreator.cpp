//
// Created by noam on 16/12/16.
//

#include "DriverCreator.h"
//create a driver
Driver * createDriver(int id, int age, char status, int experience, int vehicleId) {
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
    return new Driver(Point(0, 0), id, age, experience, vehicleId, st);
}