//
// Created by noa on 28/11/2018.
//

#ifndef UNTITLED2_RESERVATIONDATA_H

#include "SplitString.h"
#include "Data.h"
#include "MyReservation.h"
#include "FlightData.h"
#include "CustomerData.h"
#include <iostream>
#include <fstream>
#define RESERVATION "reservation.txt"

#define UNTITLED2_RESERVATIONDATA_H


class ReservationData : public Data<MyReservation> {
public:
    ReservationData();

    MyReservation *findRes(string id, CustomerData *customerData,
                           FlightData *flightData, EmployeeData *employeeData,
                           PlaneData *planeData);

    list<Reservation *> findAllObjects(int index, string id, CustomerData *customerData,
                                       FlightData *flightData, EmployeeData *employeeData,
                                       PlaneData *planeData);

};

#endif //UNTITLED2_RESERVATIONDATA_H
