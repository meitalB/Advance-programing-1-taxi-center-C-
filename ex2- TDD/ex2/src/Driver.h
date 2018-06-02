//
// Created by mei on 29/11/16.
//
#include <string>
#ifndef EX2AP_DRIVER_H
#define EX2AP_DRIVER_H


enum  STATUS{
        SINGLE = 1, MARRIED = 2, DIVORCED = 3, WIDOWED = 4
};

class Driver {
private:
    int id;
    int age;
    int yearsOfExperience;
    int averageSatisfaction;
    int maritalstatus;
    // std::string maritalStatus;
    //**taxi cb
    //TODO
public:
    // Constructor all the members
    Driver(int id, int age, int yearsOfExperience,
           int averageSatisfaction,int maritalstatus);
    int getId();
    void setId(int id);
    int getAge();
    void setAge(int age);
    int getYearsOfExperience();
    void setyearsOfExperience(int yearsOfExperience);
    int getaverageSatisfaction();
    void setaverageSatisfaction(int averageSatisfaction);
    int getMaritalstatus ();
    void setMaritalStatus(int maritalstatusNew);

};


#endif //EX2AP_DRIVER_H
