#include "FlightData.h"

/**
 * Counstractor,get the file name
 */
FlightData::FlightData() : Data(FLIGHT) {}

/**
 * the function read from the file,
 * and serch for a fligth.
 * @param employees - to find a crew
 * @param planes - to find avilable plane
 */
void FlightData::load(EmployeeData *employees, PlaneData *planes) {
    // open the file
    ifstream myFile(fileName);
    string line;
    MyFlight *newFlight;
    MyPlane *plane;
    list<MyEmployee *> crew;
    // check if the file not exist
    if (!myFile.good()) {
        return;
    }
    // check if the fie open
    if (myFile.is_open()) {
        vector<string> fl;
        // read every line
        while (getline(myFile, line)) {
            fl = split(line, ',');
            // if the flight not in the old data
            if (oldData.find(fl.at(0)) == oldData.end()) {
                // find available plane
                plane = planes->findAvailablePlane(stoi(fl.at(1)), (Date) fl.at(2));
                // find available crew
                crew = employees->findCrew(plane->getCrewNeeded(), (Date) fl.at(2));
                // create a new flight
                newFlight = new MyFlight(&fl, plane, &crew);
                setObjectDate((Date) fl.at(2), newFlight);
                oldData[newFlight->getID()] = newFlight;
            }
        }
        //close the file
        myFile.close();
        // if the file didnt open
    } else {
        throw runtime_error("Unable to open file");
    }
}

/**
 * the function serch for a flight
 * @param id - te id flighe
 * @param employees - an employee to add
 * @param planes
 * @return the flight
 */
MyFlight *FlightData::findFlight(string id, EmployeeData *employees, PlaneData *planes) {
    // if the flight in the mp of new data
    if (newData.find(id) != newData.end()) {
        return newData[id];
        // if the flight in the map of old data
    } else if (oldData.find(id) != oldData.end()) {
        return oldData[id];
    }
    //open the file
    ifstream myFile(fileName);
    string line;
    MyFlight *newFlight;
    MyPlane *plane;
    list<MyEmployee *> crew;
    // check if the file not exist
    if (!myFile.good()) {
        return nullptr;
    }
    // check if the file is open
    if (myFile.is_open()) {
        vector<string> fl;
        // read each line from the file
        while (getline(myFile, line)) {
            fl = split(line, ',');
            // if the flight isn't in old data
            if (oldData.find(fl.at(0)) == oldData.end()) {
                // find a plane
                plane = planes->findAvailablePlane(stoi(fl.at(1)), (Date) fl.at(2));
                // fins=d a crew
                crew = employees->findCrew(plane->getCrewNeeded(), (Date) fl.at(2));
                // create new flight
                newFlight = new MyFlight(&fl, plane, &crew);
                setObjectDate((Date) fl.at(2), newFlight);
                oldData[newFlight->getID()] = newFlight;
                // if we found the flight
                if (fl.at(0) == id) {
                    // close the file and return the light
                    myFile.close();
                    return newFlight;
                }
                // if we found the flight
            } else if (fl.at(0) == id) {
                myFile.close();
                return newFlight;
            }
        }
        //close the file
        myFile.close();
        // if the file didnt open
    } else {
        throw runtime_error("Unable to open file");
    }
    return nullptr;
}

