#include "../../headers/Staff/Surgeon.hpp"

Surgeon::Surgeon(string name, string dob, string id, string phone, double salary, string department, string specialization, double fee)
    : Staff(name, dob, id, phone, salary, department), specialization(specialization), operationFee(fee) {}

double Surgeon::getBillingRate() const {
    return operationFee;
}

string Surgeon::getSummary() const {
    return "[Surgeon] Name: " + name + " | Spec: " + specialization + " | Operation Fee: " + to_string(operationFee);
}