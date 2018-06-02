//
// Created by noam on 16/12/16.
//

#include "TaxiCreator.h"
#include "../cabs/StandardCab.h"
#include "../cabs/LuxuryCab.h"
//help to create a taxi with macro of MANUFACTURER and COLOR
TaxiCab * createTaxi(int id, int taxiType, char manufacturer, char color){
    COLOR c;
    MANUFACTURER carManufacturer;

    switch(manufacturer){
        case 'H':
            carManufacturer = HONDA;
            break;
        case 'S':
            carManufacturer = SUBARO;
            break;
        case 'T':
            carManufacturer = TESLA;
            break;
        case 'F':
            carManufacturer = FIAT;
            break;
        default:
            carManufacturer = HONDA;
            break;
    }

    switch(color){
        case 'R':
            c = RED;
            break;
        case 'G':
            c = GREEN;
            break;
        case 'P':
            c = PINK;
            break;
        case 'W':
            c = WHITE;
            break;
        case 'B':
            c = BLUE;
            break;
        default:
            c = RED;
            break;
    }

    switch (taxiType) {
        case 1:
            return new StandardCab(id, 0, 1, carManufacturer, c);
        case 2:
            return new LuxuryCab(id, 0, 2, carManufacturer, c);
        default:
            return new LuxuryCab(id, 0, 2, carManufacturer, c);
    }
}