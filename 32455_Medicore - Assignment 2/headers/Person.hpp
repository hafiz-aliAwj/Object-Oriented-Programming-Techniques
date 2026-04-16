#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name, dateOfBirth, id, phone;

public:
    Person(string n, string d, string i, string p); // Initializes core personal identification details
    virtual ~Person() = default; // Ensures proper cleanup of derived classes

    virtual string getSummary() const = 0; // Provides basic profile information as string
    string  getID() const; // Retrieves the unique identification string value
    string  getName() const; // Returns the full name of person
};

#endif