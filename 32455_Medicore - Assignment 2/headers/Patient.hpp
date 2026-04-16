#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "Person.hpp"
#include "Bill.hpp"
#include <vector>
#include <string>

using namespace std;

class Ward; 

//Records details of medical procedures performed.
struct Treatment {
    string name;
    double cost;
    string performedBy;
};

class Patient : public Person {
private:
    string diagnosis;
    string admissionDate;
    string wardName;
    Ward* currentWard; 
    vector<Treatment> treatments;
    bool isDischarged;
    bool critical;

public:
    Patient(string name, string dob, string id, string phone, string diagnosis, string admitDate, string wardName,  bool critical);
    
    Patient(Patient&& other) noexcept; // Moves patient data to new object
    Patient& operator=(Patient&& other) noexcept; // Transfers patient data via move assignment
    
    Patient(const Patient& other) = default; // Creates exact copy of patient data
    Patient& operator=(const Patient& other) = default; // Assigns patient data using copy semantics

    void setWard(Ward* w) { currentWard = w; } // Assigns specific ward to the patient
    void addTreatment(string treatmentName, double cost, string staffName); // Records a new medical procedure performed
    void discharge(); // Updates status to indicate patient left
    
    const vector<Treatment>& getTreatments() const; // Returns list of all medical procedures
    string getDiagnosis() const; // Retrieves the identified medical condition description
    string getSummary() const override; // Provides comprehensive overview of patient record
    bool getDischargedStatus() const; // Checks if patient has left hospital
    bool isCritical() const;

    Bill generateBill(int daysAdmitted) const; // Calculates total costs for hospital stay
};

#endif