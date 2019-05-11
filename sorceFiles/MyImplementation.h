
#ifndef UNTITLED2_MYIMPLEMENTATION_H

#include "interface.h"
#include "EmployeeData.h"
#include "CustomerData.h"
#include "ReservationData.h"
#include "PlaneData.h"
#include "FlightData.h"
#include <iostream>

#define UNTITLED2_MYIMPLEMENTATION_H

class MyImplementation : public Ex2 {
    // members
    EmployeeData employees;
    CustomerData customers;
    ReservationData reservations;
    PlaneData planes;
    FlightData flights;
public:

    MyImplementation();

    Employee *addEmployee(int seniority, int birth_year,
                          string employer_id, Jobs title);

    Employee *getEmployee(string id);

    Plane *addPlane(int model_number, map<Jobs, int> crew_needed,
                    map<Classes, int> max_passangers);

    Plane *getPlane(string id);

    Flight *addFlight(int model_number, Date date,
                      string source, string destination);

    Flight *getFlight(string id);

    Customer *addCustomer(string full_name, int priority);

    Customer *getCustomer(string id);

    Reservation *addResevation(string customerId, string flightId,
                               Classes cls, int max_baggage);

    Reservation *getReservation(string id);

    void exit();


};

#endif //UNTITLED2_MYIMPLEMENTATION_H
