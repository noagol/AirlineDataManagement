
#ifndef UNTITLED2_MYPLANE_H

#include <iostream>
#include "interface.h"
#include "RandomId.h"

#define UNTITLED2_MYPLANE_H


class MyPlane : public Plane {
    // members
    int modelNumber;
    map<Jobs, int> crewNeeded;
    map<Classes, int> maxPassangers;
    RandomId planeId;

public:
    MyPlane(int model, map<Jobs, int> crew, map<Classes, int> passangers);

    MyPlane(vector<string> *plane);

    int getModelNumber();

    map<Jobs, int> getCrewNeeded();

    int getMaxFirstClass();

    int getMaxEconomyClass();

    string getID();

    int getNumOf(Jobs job);


    friend ostream &operator<<(ostream &stream, MyPlane &plane);


    ~MyPlane();

};

#endif //UNTITLED2_MYPLANE_H
