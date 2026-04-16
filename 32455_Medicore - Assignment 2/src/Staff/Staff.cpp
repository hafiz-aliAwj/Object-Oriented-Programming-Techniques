#include "../../headers/Staff/Staff.hpp"

Staff::Staff(string name, string dob, string id, string phone, double salary, string department)
    : Person(name, dob, id, phone), salary(salary), department(department) {}

string Staff::getDept() const {
    return department;
}