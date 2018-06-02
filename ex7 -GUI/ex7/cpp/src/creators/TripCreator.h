//
// Created by noam on 16/12/16.
//

#ifndef EX2AP_TRIPCREATOR_H
#define EX2AP_TRIPCREATOR_H


#include "../Trip.h"
#include "../TaxiCenter.h"
#include "../core/Matrix.h"
#include "ThreadCreator.h"
#include "../TaxiCenter.h"
#include "../Job.h"
#include "../ThreadPool.h"
//help to create a trip
Trip *createTrip(Matrix *grid, int id, long xStart, long yStart, long xEnd, long yEnd, int numOfPass, double tariff,
                 int timeOfStart, ThreadPool *tripThreadPool, class TaxiCenter *taxiCenter);

void * calculatePath(void *pathArgs);



class PathAgrs{
public:
    Matrix* grid;
    Point* start;
    Point* end;
    Trip* trip;
    class TaxiCenter* taxiCenter;
    pthread_mutex_t lock;


    PathAgrs(Matrix *grid, Point start,  Point end, Trip* trip, TaxiCenter* taxiCenter)
            : grid(grid), trip(trip), taxiCenter(taxiCenter) {
        pthread_mutex_init(&lock, NULL);
        this->start = new Point(start.x(), start.y());
        this->end = new Point(end.x(), end.y());
    }

    ~PathAgrs(){
        pthread_mutex_destroy(&lock);
        delete start;
        delete end;
    }
};

#endif //EX2AP_TRIPCREATOR_H
