//
// Created by noa on 28/11/2018.
//

#ifndef UNTITLED2_FLIGHTDATA_H
#define UNTITLED2_FLIGHTDATA_H

#include "MyFlight.h"
#include "Data.h"
#include "SplitString.h"
#include "EmployeeData.h"
#include "PlaneData.h"

#define FLIGHT "flight.txt"

class FlightData : public Data<MyFlight> {
public:

    FlightData();

    void load(EmployeeData *employees, PlaneData *planes);

    MyFlight *findFlight(string id, EmployeeData *employees, PlaneData *planes);
};


#endif //UNTITLED2_FLIGHTDATA_H
