#include "../headers/ReportGenerator.hpp"

vector<Patient*> ReportGenerator::filterPatients(const vector<Patient*>& patients, function<bool(Patient*)> predicate) {
    vector<Patient*> filtered;
    for (Patient* p : patients) {
        if (predicate(p)) filtered.push_back(p);
    }
    return filtered;
}

void ReportGenerator::sortPatients(vector<Patient*>& patients, function<bool(Patient*, Patient*)> comparator) {
    size_t n = patients.size();
    for (size_t i = 0; i < n; i++) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < n; j++) {
            if (comparator(patients[j], patients[minIdx])) minIdx = j;
        }
        Patient* temp = patients[i];
        patients[i] = patients[minIdx];
        patients[minIdx] = temp;
    }
}

vector<Staff*> ReportGenerator::filterStaff(const vector<Staff*>& staff, function<bool(Staff*)> predicate) {
    vector<Staff*> filtered;
    for (Staff* s : staff) {
        if (predicate(s)) filtered.push_back(s);
    }
    return filtered;
}

double ReportGenerator::calculateWardRevenue(string wardName, const vector<Patient*>& dischargedPatients) {
    double totalRevenue = 0.0;
    for (Patient* p : dischargedPatients) {
        if (p->getSummary().        find(wardName) != string::npos) {
            totalRevenue += p->generateBill(5).getTotalAmount();
        }
    }
    return totalRevenue;
}

vector<Patient*> ReportGenerator::getPatientsByStaff(string staffName, const vector<Patient*>& allPatients) {
    return filterPatients(allPatients, [&](Patient* p) {
        for (const auto& t : p->getTreatments()) {
            if (t.performedBy == staffName) return true;
        }
        return false;
    });
}