#include "MyCustomer.h"

/**
 * Constractor
 * @param name the customer name
 * @param prior
 */
MyCustomer::MyCustomer(string name, int prior) :
        fullName(name), priority(prior), customerId(), reservation() {}

/**
 * Constractor
 * @param customer details
 */
MyCustomer::MyCustomer(vector<string> *customer) :
        customerId(customer->at(0)),
        fullName(customer->at(1)),
        priority(stoi(customer->at(2))) {}

/**
 *
 * @return the customer name
 */
string MyCustomer::getFullName() {
    return fullName;
}
/**
 *
 * @return the customer priority
 */
int MyCustomer::getPriority() {
    return priority;
}

/**
 *
 * @return the reservation list of the customer
 */
list<Reservation *> MyCustomer::getReservations() {
    return reservation;
}

/**
 * the function get reservation list and save it.
 * @param res - the reservation list to add
 */
void MyCustomer::setReservation(list<Reservation *> *res) {
    reservation = *res;
}

/**
 *
 * @return the customer id
 */
string MyCustomer::getID() {
    return customerId.getId();
}

/**
 * the function write the format of the print
 * @param stream to write
 * @param customer
 * @return the stream
 */
ostream &operator<<(ostream &stream, Customer &customer) {
    string sign = ",";
    stream << customer.getID() << sign << customer.getFullName()
           << sign << to_string(customer.getPriority()) << endl;
    return stream;
}

MyCustomer::~MyCustomer() {}

