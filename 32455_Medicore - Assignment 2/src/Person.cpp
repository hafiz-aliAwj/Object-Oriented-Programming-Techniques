#include "../headers/Person.hpp"

Person::Person(string n, string d, string i, string p) 
    : name(n), dateOfBirth(d), id(i), phone(p) {}

string Person::getID() const { return id; }
string Person::getName() const { return name; }