#ifndef SURGEON_HPP
#define SURGEON_HPP

#include "Staff.hpp"

class Surgeon : public Staff {
    string specialization;
    double operationFee;
public:
    Surgeon(string name, string dob, string id, string phone, double salary, string department, string specialization, double fee);
    double getBillingRate() const override;
    string getSummary() const override;
};

#endif