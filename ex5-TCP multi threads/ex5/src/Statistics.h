//
// Created by mei on 03/12/16.
//

#ifndef EX2AP_STATISTICS_H
#define EX2AP_STATISTICS_H

#include "persons/Person.h"

class Statistics {
public:

    //get the current location of all the persons
    std::list<Person> getCurrentLocation();
};


#endif //EX2AP_STATISTICS_H
