#include "../headers/Bill.hpp"
#include <iomanip>
#include <cmath>

Bill::Bill(double treatments = 0.0, double ward = 0.0, double adminFee = 500.0) : treatmentCosts(treatments), wardFees(ward), adminFee(adminFee)
{
    totalAmount = treatmentCosts + wardFees + adminFee;
}

  double Bill::getTotalAmount() const{
    return totalAmount;
  }

bool Bill::operator==(const Bill& other) const {
   bool treatmentsMatch = std::fabs(this->treatmentCosts - other.treatmentCosts) < 0.001;
    bool wardFeesMatch = std::fabs(this->wardFees - other.wardFees) < 0.001;
    bool adminMatch = std::fabs(this->adminFee - other.adminFee) < 0.001;
    return treatmentsMatch && wardFeesMatch && adminMatch;
}

Bill Bill::operator+(const Bill& other) const {
    return Bill(
        this->treatmentCosts + other.treatmentCosts,
        this->wardFees + other.wardFees,
        this->adminFee + other.adminFee
    );
}

ostream& operator<<(ostream& os, const Bill& b) {
    os << "\n==========================================" << endl;
    os << "           MEDICORE HOSPITAL BILL          " << endl;
    os << "==========================================" << endl;
    
    os << left << setw(25) << "Total Treatment Costs:" 
       << "PKR " << right << setw(10) << fixed << setprecision(2) << b.treatmentCosts << endl;
    
    os << left << setw(25) << "Total Ward/Bed Fees:" 
       << "PKR " << right << setw(10) << b.wardFees << endl;
    
    os << left << setw(25) << "Administrative Base Fee:" 
       << "PKR " << right << setw(10) << b.adminFee << endl;
    
    os << "------------------------------------------" << endl;
    
    os << left << setw(25) << "FINAL BALANCE DUE:" 
       << "PKR " << right << setw(10) << b.totalAmount << endl;
    
    os << "==========================================" << endl;
    os << "Thank you for choosing MediCore Healthcare" << endl;
    os << "==========================================\n" << endl;
    
    return os;
}