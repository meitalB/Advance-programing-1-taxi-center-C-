//
// Created by mei on 29/11/16.
//
#ifndef EX2AP_TAXICAB_H
#define EX2AP_TAXICAB_H


class TaxiCab {
private:
    int cabId;
    int numberOfKilometers;
    //car manufactor, color enum
    //TODO
    int tariff;
public:
    TaxiCab(int cabIdNew,int numOfKilometersNew,int tariffNew);
    //getters and setters
    int getCabId();
    //getters and setters
    void setCabId(int id);
    //getters and setters
    int getnumberOfKilometers();
    //getters and setters
    void setnumberOfKilometers(int numberOfKilometers);
     int getTariff();
    //getters and setters
    void setTariff(int tariff);



};


#endif //EX2AP_TAXICAB_H
