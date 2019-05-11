

#include "CustomerData.h"


/**
 * Constructor for the customern
 */
CustomerData::CustomerData() : Data(CUSTOMER) {}

/**
 * the function search a customer ,in the maps
 * or txt file ,by his id and terutn the customer
 * or null id dont exist.
 * @param id - the customer id.
 * @return the coustomer .
 */
MyCustomer *CustomerData::findCustomer(string id) {
    // check if the customer is in the new data map
    if (newData.find(id) != newData.end()) {
        // is so return him
        return newData[id];
        // check if the customer is in the old data map
    } else if (oldData.find(id) != oldData.end()) {
        // is so return him
        return oldData[id];
    }
    // open the file
    ifstream myFile(fileName);
    string line;
    // new customer
    MyCustomer *newCustomer;
    // check if the file didnt exist
    if (!myFile.good()) {
        // if no return null
        return nullptr;
    }
    //check if the file open
    if (myFile.is_open()) {
        vector<string> customer;
        // read every line
        while (getline(myFile, line)) {
            // split the line
            customer = split(line, ',');
            // if the coustomer not in old data
            if (oldData.find(customer.at(0)) == oldData.end()) {
                newCustomer = new MyCustomer(&customer);
                oldData[newCustomer->getID()] = newCustomer;
                // check if the line we read is the customer
                if (customer.at(0) == id) {
                    myFile.close();
                    return newCustomer;
                }
                // check if the line we read is the customer
            } else if (customer.at(0) == id) {
                myFile.close();
                return oldData[id];
            }
        }
        //close the file
        myFile.close();
        // the file dont exist
    } else {
        throw runtime_error("Unable to open file");
    }
    return nullptr;
}