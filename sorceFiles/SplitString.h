
#ifndef UNTITLED2_STRING_H

#include <string>
#include <vector>

using namespace std;
#define UNTITLED2_STRING_H

/**
 * the function get a string and a sign,
 * and split the string according to the sign
 * @param str the string
 * @param sign the sign
 * @return the splited string
 */
static vector<string> split(string str, char sign) {
    vector<string> splitStr;
    unsigned int i;
    unsigned int start = 0;
    // goes all the string
    for (i = 0; i < str.size(); i++) {
        // check if we get to the sign
        if (str.at(i) == sign) {
            // save the word until the ','
            splitStr.push_back(str.substr(start, i - start));
            start = i + 1;
        }
    }
    // save the last word
    splitStr.push_back(str.substr(start, i));
    return splitStr;
}

#endif //UNTITLED2_SPLITSTRING_H
