//
// Created by mei on 29/11/16.
//
#include <string>
#include "Person.h"
#include "../Trip.h"
#include "../cabs/TaxiCab.h"

#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

#ifndef EX2AP_DRIVER_H
#define EX2AP_DRIVER_H



class Driver : public Person{
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<Person>(*this);
        archive & taxiCab;
        archive & vehicleId;
        archive & yearsOfExperience;
        archive & averageSatisfaction;
        archive & totalPoints;
        archive & numberOfVotes;
    }

    unsigned int yearsOfExperience;
    unsigned int averageSatisfaction;
    unsigned int totalPoints;
    unsigned int numberOfVotes;
    int vehicleId;
    TaxiCab* taxiCab;

public:
    // Constructor
    Driver() : taxiCab(NULL), averageSatisfaction(0), totalPoints(0),
               numberOfVotes(0) {};

    // Constructor all the members
    Driver(Point location, int id, unsigned int age, unsigned int yearsOfExperience,
           int vehicleId, STATUS status);

    ~Driver();

    //getters and setters
    int getYearsOfExperience();

    //getters and setters
    void setYearsOfExperience(unsigned int yearsOfExperience);

    //getters and setters
    unsigned int getAverageSatisfaction();

    //getters and setters
    void setVehicleId(int vehicleId);

    //getters and setters
    int getVehicleId();

    //getters and setters
    void setTaxiCab(TaxiCab* taxi);

    //getters and setters
    TaxiCab* getTaxiCab();

    //update points of driver and average of votes to the driver
    void rateDriver(unsigned int points);

    //getters and setters
    int getVelocity();
};


#endif //EX2AP_DRIVER_H
