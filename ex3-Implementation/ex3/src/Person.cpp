//
// Created by mei on 03/12/16.
//


#include "Person.h"
//constructor
Person::Person(int id, int age, STATUS status, Point location) : location(location){
    this->id = id;
    this->age = age;
    this->status = status;
}

//getters and setters
Point Person::getCurrentLocation() {
    return this->location;
}

//equal two persons
bool Person::equalPerson(Person p2){
    return true;
}

//update the person location
void Person::updateLocation(Point p){
    this->location = p;
}

//getters and setters
int Person::getId(){
    return this->id;
}
//getters and setters
void Person::setId(int  id){
    this->id = id;
}
//getters and setters
int Person::getAge(){
    return this->age;
}
//getters and setters
void Person::setAge(int age){
    this->age = age;
}

//getters and setters
STATUS Person::getStatus(){
    return status;
}
//getters and setters
void Person::setMaritalStatus(STATUS status){
    this->status = status;
}