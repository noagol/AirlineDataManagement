
#ifndef UNTITLED2_CUSTOMERDATA_H

#include "SplitString.h"
#include "MyCustomer.h"
#include "Data.h"
#include "MyReservation.h"
#include <iostream>
#include <fstream>
#define CUSTOMER "customer.txt"
#define UNTITLED2_CUSTOMERDATA_H



class CustomerData : public Data<MyCustomer> {
public:
    CustomerData();
    MyCustomer *findCustomer(string id);
};


#endif //UNTITLED2_CUSTOMERDATA_H
