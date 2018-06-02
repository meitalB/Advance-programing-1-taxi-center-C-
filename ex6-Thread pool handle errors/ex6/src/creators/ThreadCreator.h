//
// Created by mei on 10/01/17.
//
#include <pthread.h>
#include <vector>
#include <thread_db.h>
#include "../core/Matrix.h"
#include "../persons/Driver.h"
#include "../Serialization.h"
#include "../TaxiCenter.h"

#ifndef TAXI_CENTER_THREADPOOL_H
#define TAXI_CENTER_THREADPOOL_H

pthread_t createThread(void *(*pFunc)(void *), void *args);


#endif //TAXI_CENTER_THREADPOOL_H
