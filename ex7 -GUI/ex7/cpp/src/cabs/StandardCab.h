//
// Created by mei on 02/12/16.
//

#ifndef EX2AP_STANDARTCAB_H
#define EX2AP_STANDARTCAB_H


#include "TaxiCab.h"


class StandardCab : public TaxiCab {
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &archive, const unsigned int version) {
        archive & boost::serialization::base_object<TaxiCab>(*this);
    }
public:
    StandardCab() {};
    //constructor
    StandardCab(int cabId, int numOfKilometers, int tariff,
                MANUFACTURER carManufacturer, COLOR color);
};

#endif //EX2AP_STANDARTCAB_H
