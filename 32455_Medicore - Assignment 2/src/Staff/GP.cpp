#include "../../headers/Staff/GP.hpp"

GP::GP(string name, string dob, string id, string phone, double salary, string dept, double fee)
    : Staff(name, dob, id, phone, salary, dept), consultationFee(fee) {}

double GP::getBillingRate() const {
    return consultationFee;
}

string GP::getSummary() const {
    return "[GP] Name: " + name + " | ID: " + id + " | Dept: " + department + " | Rate: " + to_string(consultationFee);
}