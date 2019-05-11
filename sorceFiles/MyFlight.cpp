#include "MyFlight.h"

/**
 * Constractor
 * @param p the plane
 * @param d the date
 * @param s the name
 * @param dest the destenation
 * @param team
 */
MyFlight::MyFlight(Plane *p, Date *d, string *s, string *dest, list<MyEmployee *> *team) :
        plane(p), date(*d), source(*s), destination(*dest),
        reservation(), crew(*team), flightId(), firstClassCount(plane->getMaxFirstClass()),
        secondClassCount(plane->getMaxEconomyClass()) {}

/**
 * Constractor
 * @param flight
 * @param p
 * @param team
 */

MyFlight::MyFlight(vector<string> *flight, Plane *p, list<MyEmployee *> *team) :
        flightId(flight->at(0)), date(flight->at(2)),
        source(flight->at(3)), destination(flight->at(4)), reservation(),
        plane(p), crew(*team), firstClassCount(plane->getMaxFirstClass()),
        secondClassCount(plane->getMaxEconomyClass()) {}

/**
 *
 * @return the model number
 */
int MyFlight::getModelNumber() {
    return plane->getModelNumber();
}

/**
 *
 * @return the reservation of the flight
 */
list<Reservation *> MyFlight::getReservations() {
    return reservation;
}

/**
 *
 * @return the crew of the flught
 */
list<Employee *> MyFlight::getAssignedCrew() {
    list<Employee *> team;
    typename list<MyEmployee *>::iterator it;
    for (it = crew.begin(); it != crew.end(); ++it) {
        team.push_back(*it);
    }
    return team;
}

/**
 *
 * @return the flight date
 */
Date MyFlight::getDate() {
    return date;
}

/**
 *
 * @return the flight sorce
 */
string MyFlight::getSource() {
    return source;
}

/**
 *
 * @return the flight destenation
 */
string MyFlight::getDestination() {
    return destination;
}

/**
 *
 * @return the flight id
 */
string MyFlight::getID() {
    return flightId.getId();
}

/**
 * the func return true if there is place in the
 * flight else false
 * @param res the reservation
 */
bool MyFlight::findPlace(Reservation *res) {
    // check if there is place in first class
    if (res->getClass() == FIRST_CLASS) {
        if (firstClassCount > 0) {
            return true;
        }
        // check if there is place in second class
    } else if (res->getClass() == SECOND_CLASS) {
        if (secondClassCount > 0) {
            return true;
        }
    }
    //else return false
    return false;
}

/**
 * the function add reservation if there is place,
 * else throw exception
 * @param res
 */
void MyFlight::AddReservation(Reservation *res) {
    // check if there is place
    if (findPlace(res)) {
        // add the reservation
        reservation.push_back(res);
        if (res->getClass() == FIRST_CLASS) {
            firstClassCount--;
        } else if (res->getClass() == SECOND_CLASS) {
            secondClassCount--;
        }
        //there is no place
    } else {
        throw runtime_error("no place in plane");
    }
}

/**
 * the function write the format of the print
 * @param stream to write
 * @param flight
 * @return the stream
 */
ostream &operator<<(ostream &stream, Flight &flight) {
    string sign = ",";
    stream << flight.getID() << sign << to_string(flight.getModelNumber())
           << sign << flight.getDate().getDate() << sign << flight.getSource()
           << sign << flight.getDestination() << endl;
    return stream;
}

MyFlight::~MyFlight() {}
