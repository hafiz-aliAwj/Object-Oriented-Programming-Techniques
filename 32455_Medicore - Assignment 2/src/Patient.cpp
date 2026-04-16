#include "../headers/Patient.hpp"
#include "../headers/Ward/Ward.hpp"

Patient::Patient(string name, string dob, string id, string phone, string diagnosis, string admitDate, string wardName,  bool critical)
    : Person(name, dob, id, phone), diagnosis(diagnosis), admissionDate(admitDate), 
      wardName(wardName), currentWard(nullptr), isDischarged(false), critical(critical) {}

Patient::Patient(Patient&& other) noexcept 
    : Person(std::move(other)), 
      diagnosis(std::move(other.diagnosis)),
      admissionDate(std::move(other.admissionDate)),
      wardName(std::move(other.wardName)),
      currentWard(other.currentWard),
      treatments(std::move(other.treatments)),
      isDischarged(other.isDischarged), critical(other.critical) 
{
    other.currentWard = nullptr;
}

Patient& Patient::operator=(Patient&& other) noexcept {
    if (this != &other) {
        Person::operator=(std::move(other));
        diagnosis = std::move(other.diagnosis);
        admissionDate = std::move(other.admissionDate);
        wardName = std::move(other.wardName);
        currentWard = other.currentWard;
        treatments = std::move(other.treatments);
        isDischarged = other.isDischarged;
        
        other.currentWard = nullptr; // Crucial
    }
    return *this;
}

void Patient::addTreatment(string treatmentName, double cost, string staffName) {
    treatments.push_back({treatmentName, cost, staffName});
}

void Patient::discharge() {
    isDischarged = true;
}

const vector<Treatment>& Patient::getTreatments() const {
    return treatments;
}

string Patient::getDiagnosis() const { return diagnosis; }

bool Patient::getDischargedStatus() const { return isDischarged; }

string Patient::getSummary() const {
    string status = isDischarged ? "Archived" : "Admitted";
    return "[Patient] Name: " + name + " | ID: " + id + " | Status: " + status + " | Diagnosis: " + diagnosis + " | Admit Date: " + admissionDate + " | Ward: " + wardName;
}

 bool Patient::isCritical() const{
    return critical;
 }

Bill Patient::generateBill(int daysAdmitted) const {
    double treatmentSum = 0.0;
    double wardSum = 0.0;
    double adminFee = 500.0;
    for (size_t i = 0; i < treatments.size(); ++i) {
        treatmentSum += treatments[i].cost;
    }
    if (currentWard != nullptr) {
        wardSum = (daysAdmitted * currentWard->getDailyRate());
    }
    return Bill(treatmentSum, wardSum, adminFee);
}