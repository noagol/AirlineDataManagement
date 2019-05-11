//
// Created by noa on 26/11/2018.
//

#ifndef UNTITLED2_MYRESERVATION_H

#include <iostream>
#include "interface.h"
#include "RandomId.h"

#define UNTITLED2_MYRESERVATION_H


class MyReservation : public Reservation {
    //members
    Customer *customer;
    Flight *flight;
    Classes classes;
    int maxBaggage;
    RandomId reservationId;
public:
    MyReservation(Customer *customerId, Flight *flihgtId, Classes cls, int baggage);

    MyReservation(vector<string> *res, Customer *customer1, Flight *flight1);

    Customer *getCustomer();

    Flight *getFlight();

    Classes getClass();

    int getMaxBaggage();

    string getID();

    friend ostream &operator<<(ostream &stream, Reservation &reservation);

    ~MyReservation();
};

#endif //UNTITLED2_MYRESERVATION_H
