#ifndef REPORT_GENERATOR_HPP
#define REPORT_GENERATOR_HPP

#include <vector>
#include <string>
#include <functional>
#include "Patient.hpp"
#include "Staff/Staff.hpp"

using namespace std;

class ReportGenerator {
public:
    static vector<Patient*> filterPatients(const vector<Patient*>& patients, function<bool(Patient*)> predicate);
    static void sortPatients(vector<Patient*>& patients, function<bool(Patient*, Patient*)> comparator);
    static vector<Staff*> filterStaff(const vector<Staff*>& staff, function<bool(Staff*)> predicate);
    static double calculateWardRevenue(string wardName, const vector<Patient>& dischargedPatients);
    static vector<Patient*> getPatientsByStaff(string staffName, const vector<Patient*>& allPatients);
};

#endif