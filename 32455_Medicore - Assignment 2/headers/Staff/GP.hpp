#ifndef GP_HPP
#define GP_HPP

#include "Staff.hpp"

class GP : public Staff {
    double consultationFee;
public:
    GP(string name, string dob, string id, string phone, double salary, string dept, double fee);
    double getBillingRate() const override;
    string getSummary() const override;
};

#endif