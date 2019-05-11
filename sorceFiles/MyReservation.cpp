#include "MyReservation.h"

/**
 * Constractor
 * @param customerId
 * @param flihgtId
 * @param cls
 * @param baggage
 */
MyReservation::MyReservation(Customer *customerId, Flight *flihgtId, Classes cls, int baggage) :
        customer(customerId), flight(flihgtId), classes(cls), maxBaggage(baggage),
        reservationId() {}

/**
 * Constractor
 * @param res
 * @param customer1
 * @param flight1
 */
MyReservation::MyReservation(vector<string> *res, Customer *customer1, Flight *flight1) :
        reservationId(res->at(0)),
        classes(static_cast<Classes >(stoi(res->at(3)))),
        maxBaggage(stoi(res->at(4))), flight(flight1), customer(customer1) {}

/**
 *
 * @return the reservation customer
 */
Customer *MyReservation::getCustomer() {
    return customer;
}

/**
 *
 * @return the flight
 */
Flight *MyReservation::getFlight() {
    return flight;
}

/**
 *
 * @return the class
 */
Classes MyReservation::getClass() {
    return classes;
}

/**
 *
 * @return max baggage
 */
int MyReservation::getMaxBaggage() {
    return maxBaggage;
}

/**
 *
 * @return the reservation id
 */
string MyReservation::getID() {
    return reservationId.getId();
}

/**
 * the function write the format of the print
 * @param stream to write
 * @param reservation
 * @return the stream
 */
ostream &operator<<(ostream &stream, Reservation &reservation) {
    string sign = ",";
    stream << reservation.getID() << sign << reservation.getCustomer()->getID()
           << sign << reservation.getFlight()->getID() << sign <<
           reservation.getClass() << sign << reservation.getMaxBaggage()
           << endl;
    return stream;
}


MyReservation::~MyReservation() {}

