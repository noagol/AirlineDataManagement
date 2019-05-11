//
// Created by noa on 24/11/2018.
//

#ifndef UNTITLED2_MYEMPLOYEE_H

#include <iostream>
#include <vector>
#include "interface.h"
#include "RandomId.h"
#include "SplitString.h"

#define UNTITLED2_MYEMPLOYEE_H

class MyEmployee : public Employee {
    // members
    RandomId id;
    int seniority;
    int birthYear;
    Employee *employer;
    Jobs job;
public:
    MyEmployee(int employeeSeniority, int birth,
               Employee *boss, Jobs title);

    MyEmployee(int employeeSeniority, int birth,
               Employee *boss, Jobs title, string employeeId);

    MyEmployee(vector<string> *employee, Employee *boss);

    int getSeniority();

    int getBirthYear();

    Employee *getEmployer();

    Jobs getTitle();

    string getID();

    friend ostream &operator<<(ostream &stream, Employee &emp);

    ~MyEmployee();


};

#endif //UNTITLED2_MYEMPLOYEE_H
