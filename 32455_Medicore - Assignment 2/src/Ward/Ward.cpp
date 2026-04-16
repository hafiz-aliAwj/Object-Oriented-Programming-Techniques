#include "../../headers/Ward/Ward.hpp"
#include "../../headers/Patient.hpp"

Ward::Ward(string n, int cap, double rate) 
    : name(n), capacity(cap), dailyRate(rate) {}

bool Ward::addPatient(Patient* p) {
    if (patients.size() >= (size_t)capacity) {
        return false; 
    }
    if (this->canAccept(*p)) {
        patients.push_back(p);
        p->setWard(this);
        return true;
    }

    return false;
}
double Ward::getOccupancyPercentage() const {
    if (capacity == 0) return 0.0;
    return (static_cast<double>(patients.size()) / capacity) * 100.0;
}

bool Ward::operator<(const Ward& other) const {
    return this->getOccupancyPercentage() < other.getOccupancyPercentage();
}

bool Ward::operator>(const Ward& other) const {
    return this->getOccupancyPercentage() > other.getOccupancyPercentage();
}

bool Ward::operator==(const Ward& other) const {
    return this->getOccupancyPercentage() == other.getOccupancyPercentage();
}

double Ward::getDailyRate() const { return dailyRate; }

string Ward::getName() const { return name; }