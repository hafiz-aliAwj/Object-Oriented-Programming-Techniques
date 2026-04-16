#include "../headers/Hospital.hpp"

Hospital::Hospital(string name) : hospitalName(name) {}

Hospital::~Hospital() {
    for (Ward* w : wards) delete w;
    for (Staff* s : staffMembers) delete s;
}


vector<Patient*> Hospital::getAdmittedPointers() {
    vector<Patient*> ptrs;
    for (auto& p : admittedPatients) ptrs.push_back(&p);
    return ptrs;
}

void Hospital::admit(Patient p) { admittedPatients.push_back(p); }

bool Hospital::discharge(string patientID) {
    for (auto it = admittedPatients.begin(); it != admittedPatients.end(); ++it) {
        if (it->getID() == patientID) {
            it->discharge();
            archivedPatients.push_back(std::move(*it));
            admittedPatients.erase(it);
            return true;
        }
    }
    return false;
}

bool Hospital::isAdmitted(string patientID) const {
    for (const auto& p : admittedPatients) {
        if (p.getID() == patientID) return true;
    }
    return false;
}

bool Hospital::isArchived(string patientID) const {
    for (const auto& p : archivedPatients) {
        if (p.getID() == patientID) return true;
    }
    return false;
}

Patient* Hospital::getPatientRecord(string patientID) {
    for (auto& p : admittedPatients) {
        if (p.getID() == patientID) return &p;
    }
    return nullptr;
}

void Hospital::addWard(Ward* w) { wards.push_back(w); }
void Hospital::addStaff(Staff* s) { staffMembers.push_back(s); }

vector<Patient*> Hospital::filterPatients(function<bool(Patient*)> predicate) {
    return ReportGenerator::filterPatients(getAdmittedPointers(), predicate);
}

void Hospital::sortPatients(function<bool(Patient*, Patient*)> comparator) {
    vector<Patient*> ptrs = getAdmittedPointers();
    ReportGenerator::sortPatients(ptrs, comparator);
}

vector<Staff*> Hospital::filterStaff(function<bool(Staff*)> predicate) {
    return ReportGenerator::filterStaff(this->staffMembers, predicate);
}

double Hospital::getWardRevenue(string wardName) {
    return ReportGenerator::calculateWardRevenue(wardName, archivedPatients);
}

vector<Patient*> Hospital::getStaffPatientHistory(string staffName) {
    vector<Patient*> history = getAdmittedPointers();
    for (auto& p : archivedPatients) history.push_back(&p);
    return ReportGenerator::getPatientsByStaff(staffName, history);
}

string Hospital::getName() const { return hospitalName; }
const vector<Patient>& Hospital::getAdmittedPatients() const { return admittedPatients; }
const vector<Patient>& Hospital::getArchivedPatients() const { return archivedPatients; }