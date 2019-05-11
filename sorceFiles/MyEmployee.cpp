#include "MyEmployee.h"

/**
 * Constractor
 * @param employeeSeniority
 * @param birth
 * @param boss
 * @param title
 */
MyEmployee::MyEmployee(int employeeSeniority, int birth,
                       Employee *boss, Jobs title) :
        seniority(employeeSeniority),
        birthYear(birth), employer(boss), job(title), id() {
}

/**
 * Constractor
 * @param employeeSeniority
 * @param birth
 * @param boss
 * @param title
 * @param employeeId
 */
MyEmployee::MyEmployee(int employeeSeniority, int birth,
                       Employee *boss, Jobs title, string employeeId) :
        seniority(employeeSeniority),
        birthYear(birth), employer(boss), job(title), id(employeeId) {
}

/**
 * Constractor
 * @param employee details
 * @param boss
 */
MyEmployee::MyEmployee(vector<string> *employee, Employee *boss) :
        seniority(stoi(employee->at(1))),
        birthYear(stoi(employee->at(2))), employer(boss),
        job(static_cast<Jobs >(stoi(employee->at(4)))), id(employee->at(0)) {
}

/**
 *
 * @return the seniority
 */
int MyEmployee::getSeniority() {
    return seniority;
}

/**
 *
 * @return the employee birth year
 */
int MyEmployee::getBirthYear() {
    return birthYear;
}

/**
 *
 * @return  the employer of the employee
 */
Employee *MyEmployee::getEmployer() {
    return employer;
}

/**
 *
 * @return the employee job title
 */
Jobs MyEmployee::getTitle() {
    return job;
}

/**
 *
 * @return the employee id
 */
string MyEmployee::getID() {
    return id.getId();
}

/**
 * the function write the format of the print
 * @param stream to write
 * @param emp
 * @return the stream
 */
ostream &operator<<(ostream &stream, Employee &emp) {
    string sign = ",";
    string employerID;
    // check the boss and save his id
    if (!emp.getEmployer()) {
        employerID = "Null";
    } else {
        employerID = emp.getEmployer()->getID();
    }
    stream << emp.getID() << sign << to_string(emp.getSeniority()) << sign <<
           to_string(emp.getBirthYear()) << sign
           << employerID << sign << to_string(emp.getTitle())
           << endl;
    return stream;
}

MyEmployee::~MyEmployee() {}


