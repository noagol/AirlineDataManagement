#include "PlaneData.h"

/**
 * Counstractor,get the plane name
 */
PlaneData::PlaneData() : Data(PLANE) {}

/**
 * the function serck for a plane by id
 * @param id
 * @return the plane
 */
MyPlane *PlaneData::findPlane(string id) {
    // if the plane in the map of new data
    if (newData.find(id) != newData.end()) {
        return newData[id];
        // if the plane in the map of old data
    } else if (oldData.find(id) != oldData.end()) {
        return oldData[id];
    }
    //open the file
    ifstream myFile(fileName);
    string line;
    MyPlane *newPlane;
    // check if the file not exist
    if (!myFile.good()) {
        return nullptr;
    }
    // check if the file is open
    if (myFile.is_open()) {
        vector<string> plane;
        // read each line from the file
        while (getline(myFile, line)) {
            plane = split(line, ',');
            // if the plane isn't in old data
            if (oldData.find(plane.at(0)) == oldData.end()) {
                newPlane = new MyPlane(&plane);
                oldData[newPlane->getID()] = newPlane;
                // if we found the plane
                if (plane.at(0) == id) {
                    // close the file and return it
                    myFile.close();
                    return newPlane;
                }
            } else if (plane.at(0) == id) {
                myFile.close();
                return newPlane;
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

/**
 * the function find avilable plane in a spesific date
 * @param modelNumber
 * @param date
 * @return the plane if exist else throw exception
 */
MyPlane *PlaneData::findAvailablePlane(int modelNumber, Date date) {
    typename map<string, MyPlane *>::iterator it;
    // if the plane in the map of new data and available
    for (it = newData.begin(); it != newData.end(); ++it) {
        if ((modelNumber == (it->second->getModelNumber()))
            && (check(date, it->second))) {
            setObjectDate(date, it->second);
            return it->second;
        }
    }
    // if the plane in the map of old data and available
    for (it = oldData.begin(); it != oldData.end(); ++it) {
        if ((modelNumber == (it->second->getModelNumber()))
            && (check(date, it->second))) {
            setObjectDate(date, it->second);
            return it->second;
        }
    }
    // open the file
    ifstream myFile(fileName);
    string line;
    MyPlane *newPlane;
    // check if the file not exist
    if (!myFile.good()) {
        throw runtime_error("no plane available");
    }
    // check if the file is open
    if (myFile.is_open()) {
        vector<string> plane;
        // read each line from the file
        while (getline(myFile, line)) {
            plane = split(line, ',');
            // if the plane isn't in old data
            if (oldData.find(plane.at(0)) == oldData.end()) {
                newPlane = new MyPlane(&plane);
                oldData[newPlane->getID()] = newPlane;
                // if we found available plane
                if ((modelNumber == (newPlane->getModelNumber()))
                    && (check(date, newPlane))) {
                    setObjectDate(date, newPlane);
                    // close the file and return it
                    myFile.close();
                    return newPlane;
                }
            } else if (modelNumber == stoi(plane.at(1)) && check(date, oldData[plane.at(0)])) {
                setObjectDate(date, oldData[plane.at(0)]);
                myFile.close();
                return oldData[plane.at(0)];
            }
        }
        //close the file
        myFile.close();
        // if the file didnt open
    } else {
        throw runtime_error("Unable to open file");
    }
    throw runtime_error("no plane available");
}
