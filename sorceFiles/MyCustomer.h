//
// Created by noa on 26/11/2018.
//

#ifndef UNTITLED2_MYCUSTOMER_H

#include <iostream>
#include "interface.h"
#include "RandomId.h"

#define UNTITLED2_MYCUSTOMER_H


class MyCustomer : public Customer {
    // members
    string fullName;
    int priority;
    RandomId customerId;
    list<Reservation *> reservation;

public:
    MyCustomer(string name, int prior);

    MyCustomer(vector<string> *customer);

    string getFullName();

    int getPriority();

    list<Reservation *> getReservations();

    void setReservation(list<Reservation *> *res);

    string getID();

    friend ostream &operator<<(ostream &stream, Customer &customer);

    ~MyCustomer();
};


#endif //UNTITLED2_MYCUSTOMER_H
