#include "../../headers/Staff/Nurse.hpp"

Nurse::Nurse(string name, string dob, string id, string phone, double salary, string department, double fee, string aWard)
    : Staff(name, dob, id, phone, salary, department), careFee(fee), assignedWard(aWard) {}

double Nurse::getBillingRate() const {
    return careFee;
}

string Nurse::getSummary() const {
    return "[Nurse] Name: " + name + " | Ward: " + assignedWard + " | Dept: " + department + " | Hourly Care Fee: " + to_string(careFee);
}