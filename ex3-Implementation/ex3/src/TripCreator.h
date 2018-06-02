//
// Created by noam on 16/12/16.
//

#ifndef EX2AP_TRIPCREATOR_H
#define EX2AP_TRIPCREATOR_H


#include "Trip.h"
#include "Matrix.h"

//help to craete a trip
Trip createTrip(Matrix grid, int id, int xStart, int yStart,
                int xEnd, int yEnd, int numOfPass, double tariff);


#endif //EX2AP_TRIPCREATOR_H
