//
// Created by noa on 27/11/2018.
//

#ifndef UNTITLED2_PLANDATA_H

#include "MyPlane.h"
#include "SplitString.h"
#include "Data.h"
#include <iostream>
#include <fstream>
#define PLANE "plane.txt"

#define UNTITLED2_PLANDATA_H


class PlaneData : public Data<MyPlane> {

public:
    PlaneData();

    MyPlane *findPlane(string id);

    MyPlane *findAvailablePlane(int modelNumber, Date date);


};

#endif //UNTITLED2_PLANDATA_H
