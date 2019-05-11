//
// Created by noa on 24/11/2018.
//

#ifndef UNTITLED2_RANDOMID_H

#include <cstdlib>
#include <string>
#include <random>

using namespace std;
#define UNTITLED2_RANDOMID_H

class RandomId {
    // member
    string id;
public:
    RandomId();

    RandomId(string ide);

    string generateRandom();

    string getId();
};


#endif //UNTITLED2_RANDOMID_H
