#ifndef STAFF_HPP
#define STAFF_HPP

#include "../Person.hpp"
using namespace std;

class Staff : public Person {
protected:
    double salary;
    string department;

public:
    Staff(string name, string dob, string id, string phone, double salary, string department);
    virtual double getBillingRate() const = 0; 
    string getDept() const;
};

#endif