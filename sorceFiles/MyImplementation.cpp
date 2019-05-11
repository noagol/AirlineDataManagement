#include "MyImplementation.h"

/**
 * Constractor
 */
MyImplementation::MyImplementation() : employees(), customers(), reservations(), planes(), flights() {
    flights.load(&employees, &planes);
}

/**
 * the function add a new employee
 * @param seniority
 * @param birth_year
 * @param employer_id
 * @param title
 * @return the employee
 */
Employee *MyImplementation::addEmployee(int seniority, int birth_year,
                                        string employer_id, Jobs title) {
    // check the birth year
    if (birth_year < 0 || birth_year > 9999) {
        throw invalid_argument("Illegal argument- birth year");
        // check the seniority
    } else if (seniority < 0) {
        throw invalid_argument("Illegal argument- seniority");
    }
    Employee *boss;
    // check if there is no id
    if (employer_id.empty()) {
        boss = nullptr;
        // find the employer
    } else {
        boss = employees.findEmployee(employer_id);
    }
    // create the new employee
    MyEmployee *emp = new MyEmployee(seniority, birth_year, boss, title);
    // add him to the list
    employees.add(emp);
    return emp;
}

/**
 *
 * @param id - the id of the employee
 * @return the employee
 */
Employee *MyImplementation::getEmployee(string id) {
    return employees.findEmployee(id);
}

/**
 * the function add a new plane
 * @param model_number
 * @param crew_needed
 * @param max_passangers
 * @return the plane
 */
Plane *MyImplementation::addPlane(int model_number, map<Jobs, int> crew_needed,
                                  map<Classes, int> max_passangers) {
    // create a new plane
    MyPlane *plane = new MyPlane(model_number, crew_needed, max_passangers);
    // add the plane to the list
    planes.add(plane);
    return plane;
}

/**
 *
 * @param id - the id of the plane
 * @return the plane
 */
Plane *MyImplementation::getPlane(string id) {
    return planes.findPlane(id);
}

/**
 * the function add a new flight
 * @param model_number
 * @param date
 * @param source
 * @param destination
 * @return the flight
 */
Flight *MyImplementation::addFlight(int model_number, Date date,
                                    string source, string destination) {
    // check the source and destination
    if (source.empty()) {
        throw invalid_argument("invalid source location");
    } else if (destination.empty()) {
        throw invalid_argument("invalid destination location");
    }
    // check for a free plane
    Plane *plane = planes.findAvailablePlane(model_number, date);
    // check for a crew
    list<MyEmployee *> crew = employees.findCrew(plane->getCrewNeeded(), date);
    // create a new flight
    MyFlight *flight = new MyFlight(plane, &date, &source, &destination, &crew);
    // set the flight date
    flights.setObjectDate(date, flight);
    flights.add(flight);
    return flight;
}

/**
 *
 * @param id - the id of the flight
 * @return the flight
 */
Flight *MyImplementation::getFlight(string id) {
    return flights.findFlight(id, &employees, &planes);
}

/**
 * the function add a new customer
 * @param full_name
 * @param priority
 * @return the cusomer
 */
Customer *MyImplementation::addCustomer(string full_name, int priority) {
    // check the priority
    if (priority < 0 || priority > 5) {
        throw invalid_argument("Illegal argument- priority");
        // check the name
    } else if (full_name.empty()) {
        throw invalid_argument("Illegal argument- name");
    }
    list<Reservation *> res;
    // create new customer
    MyCustomer *customer = new MyCustomer(full_name, priority);
    // set all his reservation
    res = reservations.findAllObjects(1, customer->getID(), &customers,
                                      &flights, &employees, &planes);
    customer->setReservation(&res);
    customers.add(customer);
    return customer;
}

/**
 *
 * @param id - the id of the customer
 * @return the customer by his id
 */
Customer *MyImplementation::getCustomer(string id) {
    return customers.findCustomer(id);
}

/**
 * the function add a new reservation
 * @param customerId
 * @param flightId
 * @param cls
 * @param max_baggage
 * @return the reservation
 */
Reservation *MyImplementation::addResevation(string customerId, string flightId,
                                             Classes cls, int max_baggage) {
    Customer *customer = getCustomer(customerId);
    // check if the customer exist
    if (!customer) {
        throw invalid_argument("invalid customer");
    }
    MyFlight *flight = flights.findFlight(flightId, &employees, &planes);
    // check if the flight exist
    if (!flight) {
        throw invalid_argument("invalid flight");
    }
    // create new reservation
    MyReservation *reservation = new MyReservation(customer, flight, cls, max_baggage);
    reservations.add(reservation);
    flight->AddReservation(reservation);
    return reservation;
}

/**
 *
 * @param id - the id of the reservation
 * @return the reservation by its id
 */
Reservation *MyImplementation::getReservation(string id) {
    return reservations.findRes(id, &customers, &flights, &employees, &planes);
}

/**
 * save all the details to the files
 */
void MyImplementation::exit() {
    employees.saveToFile();
    planes.saveToFile();
    customers.saveToFile();
    reservations.saveToFile();
    flights.saveToFile();
}

