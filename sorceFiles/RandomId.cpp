#include "RandomId.h"

/**
 * Constractor, random an id
 */
RandomId::RandomId() {
    id = generateRandom();
}

/**
 * save the id
 * @param ide
 */
RandomId::RandomId(string ide) {
    id = ide;
}

/**
 * the function generate an id
 * @return the id
 */
string RandomId::generateRandom() {
    // the string id
    string id = "";
    // arry of the char to rendom
    static const char randId[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    // get a random number from hardware
    std::random_device rd;
    // generator
    std::mt19937 eng(rd());
    // define the range
    std::uniform_int_distribution<> distr(0, sizeof(randId) - 2);
    // create a rendom id with 15 chars
    for (int i = 0; i < 15; ++i) {
        id += randId[distr(eng)];
    }
    return id;

}

/**
 *
 * @return the id
 */
string RandomId::getId() {
    return id;
}


