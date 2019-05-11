
#include "interface.h"
#include "SplitString.h"

/**
 * Constractor save the date string
 * @param date
 */
Date::Date(string date) {
    // check the lenght
    if (date.length() != 10) {
        throw invalid_argument("Illegal argument");
    }
    // split the string
    vector<string> dateSplit = split(date, '-');
    // check if there are 3 args
    if (dateSplit.size() != 3) {
        throw invalid_argument("Illegal argument");
    }
    int year, day, month;
    try {
        // try to save the 3 parameters
        year = stoi(dateSplit[0]);
        month = stoi(dateSplit[1]);
        day = stoi(dateSplit[2]);
        // if couldnt throw exception
    } catch (exception e) {
        throw invalid_argument("Illegal argument");
    }
    // check if the date is correct
    if ((year > 9999) || (year < 0) || (month > 12) ||
        (month < 1) || (day > 31) || (day < 1)) {
        throw invalid_argument("Illegal argument");
    }
    this->date = date;
}

/**
 * The function return true if this<other
 * else false
 */
bool Date::operator<(const Date &d) const {
    // split the two strings and save each arg
    vector<string> dateSplit = split(date, '-');
    vector<string> dateOtherSplit = split(d.date, '-');
    int year1 = stoi(dateSplit[0]);
    int month1 = stoi(dateSplit[1]);
    int day1 = stoi(dateSplit[2]);
    int year2 = stoi(dateOtherSplit[0]);
    int month2 = stoi(dateOtherSplit[1]);
    int day2 = stoi(dateOtherSplit[2]);
   // check if the first date < second date
    if (year1 < year2) {
        return true;
    } else if (month1 > month2) {
        return false;
    } else if (month1 < month2) {
        return true;
    } else if (month1 > month2) {
        return false;
    } else if (day1 < day2) {
        return true;
    } else {
        return false;
    }

}
/**
 * The function return true if this>other
 * else false
 */
bool Date::operator>(const Date &d) const {
    // check if the first date <>second date
    // using < and = operators
    return !((this->date < d.date) || (this->date == d.date));
}

/**
 * The function return true if this=other
 * else false
 */
bool Date::operator==(const Date &d) const {
   // split the two strings and save each arg
    vector<string> dateSplit = split(date, '-');
    vector<string> dateOtherSplit = split(d.date, '-');
    int year1 = stoi(dateSplit[0]);
    int month1 = stoi(dateSplit[1]);
    int day1 = stoi(dateSplit[2]);
    int year2 = stoi(dateOtherSplit[0]);
    int month2 = stoi(dateOtherSplit[1]);
    int day2 = stoi(dateOtherSplit[2]);
    // check if the first date = second date
    return ((year1 == year2) && (month1 == month2)
            && (day1 == day2));
}


