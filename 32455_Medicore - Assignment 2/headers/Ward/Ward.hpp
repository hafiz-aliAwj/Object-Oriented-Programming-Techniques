#ifndef WARD_HPP
#define WARD_HPP

#include <string>
#include <vector>

using namespace std;

class Patient;

class Ward {
protected:
    string name;
    int capacity;
    vector<Patient*> patients;
    double dailyRate;

public:
    Ward(string n, int cap, double rate);
    virtual ~Ward() {} 
    
    virtual bool canAccept(const Patient& p) const = 0;
    bool addPatient(Patient* p);
    double getOccupancyPercentage() const;
    bool operator<(const Ward& other) const;
    bool operator>(const Ward& other) const;
    bool operator==(const Ward& other) const;
    
    double getDailyRate() const;
    string getName() const;
};

#endif