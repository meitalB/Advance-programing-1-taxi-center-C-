//
// Created by mei on 29/11/16.
//

#include "Passanger.h"
Passanger::Passanger(Point sourceNew,Point destanetionNew)
        :source(0,0),destanation(0,0){
    source=sourceNew;
    destanation=destanetionNew;
}

Point Passanger::getSourcePoint(){
    return Point(0,0);
}

void Passanger::setSourcePoint(Point p){

}

Point Passanger::getDestenationPoint(){
    return Point(0,0);

}
void Passanger::setDestenationPoint(Point p){

}
int Passanger::produceRandomScore(){
    return 0;
}