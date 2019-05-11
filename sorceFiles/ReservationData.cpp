#include "ReservationData.h"

/**
 * constractor
 */
ReservationData::ReservationData() : Data(RESERVATION) {}

/**
 * the function find a reservation by id
 * @param id
 * @param customerData
 * @param flightData
 * @param employeeData
 * @param planeData
 * @return the reservation
 */
MyReservation *ReservationData::findRes(string id, CustomerData *customerData,
                                        FlightData *flightData, EmployeeData *employeeData,
                                        PlaneData *planeData) {
    // check if the res is in the new data
    if (newData.find(id) != newData.end()) {
        return newData[id];
        // check if the res is in the old data
    } else if (oldData.find(id) != oldData.end()) {
        return oldData[id];
    }
    // open the file
    ifstream myFile(fileName);
    string line;
    MyReservation *newRes;
    MyCustomer *customer;
    MyFlight *flight;
    // check if the file not exist
    if (!myFile.good()) {
        return nullptr;
    }
    // check if the file is open
    if (myFile.is_open()) {
        vector<string> res;
        // read each line from the file
        while (getline(myFile, line)) {
            res = split(line, ',');
            // if the flight isn't in old data
            if (oldData.find(res.at(0)) == oldData.end()) {
                // find customer and flight
                customer = customerData->findCustomer(res.at(1));
                flight = flightData->findFlight(res.at(2), employeeData, planeData);
                newRes = new MyReservation(&res, customer, flight);
                oldData[newRes->getID()] = newRes;
                // if we found the res
                if (res.at(0) == id) {
                    // close the file and return the res
                    myFile.close();
                    return newRes;
                }
                // if we found the res
            } else if (res.at(0) == id) {
                myFile.close();
                return oldData[id];
            }
        }
        // close the file
        myFile.close();
        // if the file didnt open
    } else {
        throw runtime_error("Unable to open file");
    }
    return nullptr;
}

/**
 * the function find all the reservations
 * @param index
 * @param id
 * @param customerData
 * @param flightData
 * @param employeeData
 * @param planeData
 * @return list of the reservation
 */
list<Reservation *> ReservationData::findAllObjects(int index, string id, CustomerData *customerData,
                                                    FlightData *flightData, EmployeeData *employeeData,
                                                    PlaneData *planeData) {
    list<Reservation *> reservation;
    typename map<string, MyReservation *>::iterator it;
    // goes all the new data and check for the res
    for (it = newData.begin(); it != newData.end(); ++it) {
        if (id == it->second->getCustomer()->getID()) {
            reservation.push_back(it->second);
        }
    }
    // goes all the old data and check for the res
    for (it = oldData.begin(); it != oldData.end(); ++it) {
        if (id == it->second->getCustomer()->getID()) {
            reservation.push_back(it->second);
        }
    }
    // open the file
    ifstream myFile(fileName);
    // check if the file not exist
    if (!myFile.good()) {
        return reservation;
    }
    string line;
    MyReservation *newRes;
    MyCustomer *customer;
    MyFlight *flight;
    // check if the file is open
    if (myFile.is_open()) {
        vector<string> res;
        // read each line from the file
        while (getline(myFile, line)) {
            res = split(line, ',');
            // if the flight isn't in old data
            if (oldData.find(res.at(0)) == oldData.end()) {
                // find customer and flight
                customer = customerData->findCustomer(res.at(1));
                flight = flightData->findFlight(res.at(2), employeeData, planeData);
                newRes = new MyReservation(&res, customer, flight);
                oldData[newRes->getID()] = newRes;
                // if we found the res
                if (res.at(index) == id) {
                    // add to the list
                    reservation.push_back(newRes);
                }
                // if we found the res
            } else if (res.at(index) == id) {
                reservation.push_back(newRes);
            }
        }
        // close the file and return the res
        myFile.close();
        return reservation;
        // if the file didnt open

    } else {
        throw runtime_error("Unable to open file");
    }
}

