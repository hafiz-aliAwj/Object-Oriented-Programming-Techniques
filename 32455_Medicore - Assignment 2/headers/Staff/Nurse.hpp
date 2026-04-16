#ifndef NURSE_HPP
#define NURSE_HPP

#include "Staff.hpp"

class Nurse : public Staff {
    double careFee;
    string assignedWard;
public:
    Nurse(string name, string dob, string id, string phone, double salary, string department, double fee, string aWard);
    double getBillingRate() const override;
    string getSummary() const override;
};

#endif