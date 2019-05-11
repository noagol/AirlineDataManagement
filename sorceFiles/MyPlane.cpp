#include "MyPlane.h"

/**
 * Constractor
 * @param model plane
 * @param crew
 * @param passangers
 */
MyPlane::MyPlane(int model, map<Jobs, int> crew, map<Classes, int> passangers) :
        modelNumber(model), crewNeeded(crew), maxPassangers(passangers), planeId() {
}

/**
 * Constractor
 * @param plane details
 */
MyPlane::MyPlane(vector<string> *plane) :
        modelNumber(stoi(plane->at(1))), planeId(plane->at(0)) {
    this->maxPassangers[FIRST_CLASS] = stoi(plane->at(2));
    this->maxPassangers[SECOND_CLASS] = stoi(plane->at(3));
    this->crewNeeded[MANAGER] = stoi(plane->at(4));
    this->crewNeeded[NAVIGATOR] = stoi(plane->at(5));
    this->crewNeeded[FLY_ATTENDANT] = stoi(plane->at(6));
    this->crewNeeded[PILOT] = stoi(plane->at(7));
    this->crewNeeded[OTHER] = stoi(plane->at(8));
}

/**
 *
 * @return the plane model number
 */
int MyPlane::getModelNumber() {
    return modelNumber;
}

/**
 *
 * @return the crew needed
 */
map<Jobs, int> MyPlane::getCrewNeeded() {
    return crewNeeded;
}

/**
 *
 * @return the max passengers in first class
 */
int MyPlane::getMaxFirstClass() {
    int num = maxPassangers[FIRST_CLASS];
    if (!num) {
        maxPassangers[FIRST_CLASS] = 0;
    }
    return maxPassangers.at(FIRST_CLASS);
}

/**
 *
 * @return the max passengers on economy class
 */
int MyPlane::getMaxEconomyClass() {
    int num = maxPassangers[SECOND_CLASS];
    if (!num) {
        maxPassangers[SECOND_CLASS] = 0;
    }
    return maxPassangers.at(SECOND_CLASS);
}

/**
 *
 * @return the plane id
 */
string MyPlane::getID() {
    return planeId.getId();
}

/**
 *
 * @param job
 * @return the num of people needed to specific job
 */
int MyPlane::getNumOf(Jobs job) {
    int num = crewNeeded[job];
    if (num) {
        return num;
    } else {
        return 0;
    }
}

/**
 * the function write the format of the print
 * @param stream to write
 * @param plane
 * @return the stream
 */
ostream &operator<<(ostream &stream, MyPlane &plane) {
    string sign = ",";

    stream << plane.getID() << sign << to_string(plane.getModelNumber()) << sign <<
           to_string(plane.getMaxFirstClass()) << sign
           << to_string(plane.getMaxEconomyClass()) << sign <<
           plane.getNumOf(MANAGER) << sign <<
           plane.getNumOf(NAVIGATOR) << sign <<
           plane.getNumOf(FLY_ATTENDANT) << sign <<
           plane.getNumOf(PILOT) << sign <<
           plane.getNumOf(OTHER)
           << endl;
    return stream;
}


MyPlane::~MyPlane() {}

