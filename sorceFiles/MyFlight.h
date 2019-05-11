
#ifndef UNTITLED2_MYFLIGHT_H

#include <iostream>
#include "interface.h"
#include "RandomId.h"
#include "MyPlane.h"
#include "MyEmployee.h"

#define UNTITLED2_MYFLIGHT_H


class MyFlight : public Flight {
    // members
    Plane *plane;
    Date date;
    string source;
    string destination;
    list<Reservation *> reservation;
    list<MyEmployee *> crew;
    RandomId flightId;
    int firstClassCount;
    int secondClassCount;

public:
    MyFlight(Plane *p, Date *d, string *s, string *dest, list<MyEmployee *> *team);

    MyFlight(vector<string> *flight, Plane *p, list<MyEmployee *> *team);

    int getModelNumber();

    list<Reservation *> getReservations();

    list<Employee *> getAssignedCrew();

    Date getDate();

    string getSource();

    string getDestination();

    string getID();

    bool findPlace(Reservation *res);

    void AddReservation(Reservation *res);

    friend ostream &operator<<(ostream &stream, Flight &flight);

    ~MyFlight();

};

#endif //UNTITLED2_MYFLIGHT_H
