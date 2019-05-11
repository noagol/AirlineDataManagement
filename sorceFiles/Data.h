
#ifndef UNTITLED2_DATA_H

#include "interface.h"
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

#define UNTITLED2_DATA_H

template<class T>
class Data {
protected:
    // members of the class
    map<string, T *> oldData;
    map<string, T *> newData;
    map<Date, list<T *> *> dates;
    string fileName;
public:

    Data(string file);

    void add(T *object);

    void saveToFile();

    void setObjectDate(Date date, T *objects);

    void addAllToDate(list<T *> *crew, Date date);

    bool check(Date date, T *objects);

    ~Data();

};

template<class T>
/**
 * Counstactor get the file name
 * @tparam T
 * @param file
 */
Data<T>::Data(string file) : fileName(file) {}


template<class T>
/**
 * the function add an object to the map
 * @tparam T
 * @param object
 */
void Data<T>::add(T *object) {
    newData[object->getID()] = object;
}

/**
 *  the function save any object to file.
 * @tparam T - the object to save.
 */
template<class T>
void Data<T>::saveToFile() {
    ofstream outFile;
    // open the file to write
    outFile.open(fileName, std::ios::app);
    // check if the file open
    if (outFile.is_open()) {
        typename map<string, T *>::iterator it;
        // goes all the parameters to write
        for (it = newData.begin(); it != newData.end(); ++it) {
            outFile << *it->second;
        }
        //close the file
        outFile.close();
        // if the file could not open
    } else {
        throw runtime_error("Unable to open file");
    }
}

/**
 * save the date the obect booked
 * @tparam T the object
 * @param date the date
 * @param objects
 */
template<class T>
void Data<T>::setObjectDate(Date date, T *objects) {
    // ceate a new list
    list<T *> *lst = dates[date];
    // if the list dont exist
    if (!lst) {
        lst = new list<T *>;
        // book the object
        dates[date] = lst;
    }
    // add the object
    lst->push_back(objects);
}

/**
 * add all object to the map.
 * save the date they work.
 * @tparam T
 * @param crew the crew to add
 * @param date the date to save
 */
template<class T>
void Data<T>::addAllToDate(list<T *> *crew, Date date) {
    typename list<T *>::iterator it;
    // goes all the list and add them to map
    for (it = crew->begin(); it != crew->end(); ++it) {
        setObjectDate(date, *it);
    }
}

/**
 * the function check if an obect is available
 * of a specific date
 * @tparam T
 * @param date
 * @param objects
 * @return false if he is not available else true
 */
template<class T>
bool Data<T>::check(Date date, T *objects) {
    list<T *> *lst = dates[date];
    // if the list exist
    if (lst) {
        typename list<T *>::iterator it;
        //goes all the list
        for (it = lst->begin(); it != lst->end(); ++it) {
            // if he book return fale
            if (*it == objects) {
                return false;
            }
        }
    }
    // the object available
    return true;
}

/**
 * distractor.
 * free all memory
 * @tparam T
 */
template<class T>
Data<T>::~Data() {
    typename map<string, T *>::iterator it;
    // goes all the new data and free memory
    for (it = newData.begin(); it != newData.end(); ++it) {
        delete (it->second);
    }
    // goes all the old data and free memory
    for (it = oldData.begin(); it != oldData.end(); ++it) {
        delete (it->second);
    }
    typename map<Date, list<T *> *>::iterator it2;
    // goes all the dates list and free memory
    for (it2 = dates.begin(); it2 != dates.end(); ++it2) {
        delete (it2->second);
    }
}


#endif //UNTITLED2_DATA_H
