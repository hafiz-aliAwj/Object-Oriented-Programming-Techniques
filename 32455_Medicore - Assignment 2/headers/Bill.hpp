#ifndef BILL_HPP
#define BILL_HPP

#include <iostream>
using namespace std;

// Manages financial totals for patient treatments and stay.
class Bill {
private:
    double treatmentCosts; // Sum of all procedure costs
    double wardFees;       // Sum of all daily stay costs
    double adminFee = 500.0;       // Standard hospital processing fee
    double totalAmount;    // Final sum of all components

public:
    Bill(double treatment, double wardFees, double adminFee); // Constructor with breakdown support
    
    double getTotalAmount() const;
    bool operator==(const Bill& other) const; // Compares all individual cost components
    
    Bill operator+(const Bill& other) const; // Sums bills while preserving breakdown
    friend ostream& operator<<(ostream& os, const Bill& b); // Detailed itemized receipt output
};

#endif