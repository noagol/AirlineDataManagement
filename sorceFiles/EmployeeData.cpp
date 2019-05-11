#include "EmployeeData.h"

EmployeeData::EmployeeData() : Data(EMPLOYEE) {}

/**
 * the function search a employee ,in the maps
 * or txt file ,by his id and return the customer
 * or null id dont exist.
 * @param id - the employee id.
 * @return the employee .
 */
MyEmployee *EmployeeData::findEmployee(string id) {
    // check if the employee is in the new data map
    if (newData.find(id) != newData.end()) {
        // return the employee
        return newData[id];
        // check if the employee is in the old data map
    } else if (oldData.find(id) != oldData.end()) {
        // return the employee
        return oldData[id];
    }
    // open the file
    ifstream myFile(fileName);
    string line;
    MyEmployee *newEmployee;
    MyEmployee *boss;
    // check if the file didnt exist
    if (!myFile.good()) {
        return nullptr;
    }
    //check if the file open
    if (myFile.is_open()) {
        vector<string> employee;
        // read every line
        while (getline(myFile, line)) {
            // split the line
            employee = split(line, ',');
            // if the employee not in old data
            if (oldData.find(employee.at(0)) == oldData.end()) {
                // check the boss id
                if (employee.at(3) == "Null") {
                    boss = nullptr;
                } else {
                    //find the boss
                    boss = findEmployee(employee.at(3));
                }
                // if the employee not in old data (because the recursive)
                if (oldData.find(employee.at(0)) == oldData.end()) {
                    // create new employee
                    newEmployee = new MyEmployee(&employee, boss);
                    // save him in the map
                    oldData[newEmployee->getID()] = newEmployee;
                    // if we found the employee
                    if (newEmployee->getID() == id) {
                        // close the file and return him
                        myFile.close();
                        return newEmployee;
                    }
                    // check if the line we read is the employee
                } else if (employee.at(0) == id) {
                    myFile.close();
                    return oldData[employee.at(0)];
                }
                // check if the line we read is the customer
            } else if (employee.at(0) == id) {
                myFile.close();
                return oldData[employee.at(0)];
            }
        }
        //close the file
        myFile.close();
        // the file dont exist
    } else {
        throw runtime_error("Unable to open file");
    }
    // check if the employee is in the old data map
    if (oldData.find(id) != oldData.end()) {
        return oldData[id];
    }
    return nullptr;
}


/**
 * the function search for a crew ,in the maps
 * or txt file ,by the map of crew needed and return the crew
 * or null if dont exist.
 * @param crewNeeded - the map of the jobs.
 *         date- the date to find a crew
 * @return the crew .
 */
list<MyEmployee *> EmployeeData::findCrew(map<Jobs, int> crewNeeded, Date date) {
    //lists of the jobs
    list<MyEmployee *> crew;
    list<MyEmployee *> managers;
    list<MyEmployee *> navigators;
    list<MyEmployee *> flyAttendants;
    list<MyEmployee *> pilots;
    list<MyEmployee *> other;

    typename map<string, MyEmployee *>::iterator it;
    //goes all the new data
    for (it = newData.begin(); it != newData.end(); ++it) {
        // check if the crew is full
        if (fullCrew(&managers, &navigators, &flyAttendants, &pilots,
                     &other, &crewNeeded)) {
            // save the date the employees work
            addAllToDate(&crew, date);
            return crew;
        }
        //check if the employee is manager
        if (it->second->getTitle() == MANAGER) {
            checkIf(it->second, &crewNeeded, &managers, &crew, &date, MANAGER);
            //check if the employee is navigator
        } else if (it->second->getTitle() == NAVIGATOR) {
            checkIf(it->second, &crewNeeded, &navigators, &crew, &date, NAVIGATOR);
            //check if the employee is fly attender
        } else if (it->second->getTitle() == FLY_ATTENDANT) {
            checkIf(it->second, &crewNeeded, &flyAttendants, &crew, &date, FLY_ATTENDANT);
            //check if the employee is pilot
        } else if (it->second->getTitle() == PILOT) {
            checkIf(it->second, &crewNeeded, &pilots, &crew, &date, PILOT);
            //check if the employee is other
        } else if (it->second->getTitle() == OTHER) {
            checkIf(it->second, &crewNeeded, &other, &crew, &date, OTHER);
        }
    }
    //goes all the old data
    for (it = oldData.begin(); it != oldData.end(); ++it) {
        // check if the crew is full
        if (fullCrew(&managers, &navigators, &flyAttendants, &pilots,
                     &other, &crewNeeded)) {
            // save the date the employees work
            addAllToDate(&crew, date);
            return crew;
        }
        //check if the employee is manager
        if (it->second->getTitle() == MANAGER) {
            checkIf(it->second, &crewNeeded, &managers, &crew, &date, MANAGER);
            //check if the employee is navigator
        } else if (it->second->getTitle() == NAVIGATOR) {
            checkIf(it->second, &crewNeeded, &navigators, &crew, &date, NAVIGATOR);
            //check if the employee is fly attender
        } else if (it->second->getTitle() == FLY_ATTENDANT) {
            checkIf(it->second, &crewNeeded, &flyAttendants, &crew, &date, FLY_ATTENDANT);
            //check if the employee is pilot
        } else if (it->second->getTitle() == PILOT) {
            checkIf(it->second, &crewNeeded, &pilots, &crew, &date, PILOT);
            //check if the employee is other
        } else if (it->second->getTitle() == OTHER) {
            checkIf(it->second, &crewNeeded, &other, &crew, &date, OTHER);
        }
    }
    // open the file
    ifstream myFile(fileName);
    string line;
    MyEmployee *newEmployee;
    MyEmployee *boss;
    // check if the file dont exist
    if (!myFile.good()) {
        // check if the crew is full
        if (fullCrew(&managers, &navigators, &flyAttendants, &pilots,
                     &other, &crewNeeded)) {
            addAllToDate(&crew, date);
            // close the file
            myFile.close();
            return crew;
        } else {
            throw runtime_error("no find crew");
        }
    }
    // check if the file is open
    if (myFile.is_open()) {
        vector<string> employee;
        // go ebery line in the file
        while (getline(myFile, line)) {
            employee = split(line, ',');
            // if the employee not in old data
            if (oldData.find(employee.at(0)) == oldData.end()) {
                // check the  boss id
                if (employee.at(3) == "Null") {
                    boss = nullptr;
                } else {
                    // find the boss
                    boss = findEmployee(employee.at(3));
                }
                // if the employee not in old data
                if (oldData.find(employee.at(0)) == oldData.end()) {
                    // find the employee ans save him o the map
                    newEmployee = new MyEmployee(&employee, boss);
                    oldData[newEmployee->getID()] = newEmployee;
                } else {
                    newEmployee = oldData[employee.at(0)];
                }
                //check if the employee is manager
                if (newEmployee->getTitle() == MANAGER) {
                    checkIf(newEmployee, &crewNeeded, &managers, &crew, &date, MANAGER);
                    //check if the employee is navigator
                } else if (newEmployee->getTitle() == NAVIGATOR) {
                    checkIf(newEmployee, &crewNeeded, &navigators, &crew, &date, NAVIGATOR);
                    //check if the employee is fly attender
                } else if (newEmployee->getTitle() == FLY_ATTENDANT) {
                    checkIf(newEmployee, &crewNeeded, &flyAttendants, &crew, &date, FLY_ATTENDANT);
                    //check if the employee is pilot
                } else if (newEmployee->getTitle() == PILOT) {
                    checkIf(newEmployee, &crewNeeded, &pilots, &crew, &date, PILOT);
                    //check if the employee is other
                } else if (newEmployee->getTitle() == OTHER) {
                    checkIf(newEmployee, &crewNeeded, &other, &crew, &date, OTHER);
                }
                // the employee is in the map
            } else {
                newEmployee = oldData[employee.at(0)];
                bool inCrew = false;
                typename list<MyEmployee *>::iterator it;
                // check if the employee alredy in te crew
                for (it = crew.begin(); it != crew.end(); ++it) {
                    if (*it == newEmployee) {
                        inCrew = true;
                        break;
                    }
                }
                // if he not in the crew
                if (!inCrew) {
                    //check if the employee is manager
                    if (newEmployee->getTitle() == MANAGER) {
                        checkIf(newEmployee, &crewNeeded, &managers, &crew, &date, MANAGER);
                        //check if the employee is navigator
                    } else if (newEmployee->getTitle() == NAVIGATOR) {
                        checkIf(newEmployee, &crewNeeded, &navigators, &crew, &date, NAVIGATOR);
                        //check if the employee is fly attender
                    } else if (newEmployee->getTitle() == FLY_ATTENDANT) {
                        checkIf(newEmployee, &crewNeeded, &flyAttendants, &crew, &date, FLY_ATTENDANT);
                        //check if the employee is pilot
                    } else if (newEmployee->getTitle() == PILOT) {
                        checkIf(newEmployee, &crewNeeded, &pilots, &crew, &date, PILOT);
                        //check if the employee is other
                    } else if (newEmployee->getTitle() == OTHER) {
                        checkIf(newEmployee, &crewNeeded, &other, &crew, &date, OTHER);
                    }
                }
            }
        }
        //close the file
        myFile.close();
        // if the file did not open
    } else {
        throw runtime_error("Unable to open file");
    }
    // if the crew is full
    if (fullCrew(&managers, &navigators, &flyAttendants, &pilots,
                 &other, &crewNeeded)) {
        addAllToDate(&crew, date);
        // return the crew
        return crew;
        // dont find crew
    } else {
        throw runtime_error("no find crew");
    }
}

/**
 *
 * @param managers
 * @param navigators
 * @param flyAttendants
 * @param pilots
 * @param other
 * @param crewNeeded - jobs
 * @return true if found a crew else false
 */
bool EmployeeData::fullCrew(list<MyEmployee *> *managers,
                            list<MyEmployee *> *navigators, list<MyEmployee *> *flyAttendants,
                            list<MyEmployee *> *pilots,
                            list<MyEmployee *> *other, map<Jobs, int> *crewNeeded) {

    return ((managers->size() == (*crewNeeded)[MANAGER]) &&
            (navigators->size() == (*crewNeeded)[NAVIGATOR])
            && (flyAttendants->size() == (*crewNeeded)[FLY_ATTENDANT]) &&
            (pilots->size() == (*crewNeeded)[PILOT])
            && (other->size() == (*crewNeeded)[OTHER]));
}

/**
 * the function check if the employee available
 * in the date and have a match job
 * @param emp the employee
 * @param crewNeeded
 * @param job
 * @param crew
 * @param date
 * @param jobs
 */
void EmployeeData::checkIf(MyEmployee *emp, map<Jobs, int> *crewNeeded, list<MyEmployee *> *job,
                           list<MyEmployee *> *crew, Date *date, Jobs jobs) {
    // check if we need more crew and the employee is available
    if ((job->size() < (*crewNeeded)[jobs]) && check(*date, emp)) {
        // add him to the crew
        crew->push_back(emp);
        job->push_back(emp);
    }
}
