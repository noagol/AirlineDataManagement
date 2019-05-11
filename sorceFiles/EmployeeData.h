//
// Created by noa on 27/11/2018.
//

#ifndef UNTITLED2_EMPLOYEEDATA_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "MyEmployee.h"
#include "Data.h"
#define EMPLOYEE "employee.txt"

using namespace std;
#define UNTITLED2_EMPLOYEEDATA_H

class EmployeeData : public Data<MyEmployee> {
public:
    EmployeeData();

    MyEmployee *findEmployee(string id);

    list<MyEmployee *> findCrew(map<Jobs, int> crewNeeded, Date date);

    bool fullCrew(list<MyEmployee *> *managers,
                  list<MyEmployee *> *navigators, list<MyEmployee *> *flyAttendants, list<MyEmployee *> *pilots,
                  list<MyEmployee *> *other, map<Jobs, int> *crewNeeded);

    void checkIf(MyEmployee *emp, map<Jobs, int> *crewNeeded, list<MyEmployee *> *job,
                 list<MyEmployee *> *crew, Date *date, Jobs jobs);


};

#endif //UNTITLED2_EMPLOYEEDATA_H
