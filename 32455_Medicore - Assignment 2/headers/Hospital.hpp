    #ifndef HOSPITAL_HPP
    #define HOSPITAL_HPP

    #include <vector>
    #include <string>
    #include <functional>
    #include "Patient.hpp"
    #include "Staff/Staff.hpp"
    #include "Ward/Ward.hpp"
    #include "Appointment/AppointmentBook.hpp"
    #include "ReportGenerator.hpp"

    using namespace std;

    class Hospital {
    private:
        string hospitalName;
        vector<Patient> admittedPatients; 
        vector<Patient> archivedPatients; 
        vector<Ward*> wards;
        vector<Staff*> staffMembers;
        vector<Patient*> getAdmittedPointers();

    public:
        Hospital(string name);
        ~Hospital();
        void admit(Patient p); 
        bool discharge(string patientID);
        bool isAdmitted(string patientID) const;
        bool isArchived(string patientID) const;
        Patient* getPatientRecord(string patientID);
        void addWard(Ward* w);
        void addStaff(Staff* s);
        AppointmentBook& getApptBook() { return apptBook; }
        vector<Patient*> filterPatients(function<bool(Patient*)> predicate);
        void sortPatients(function<bool(Patient*, Patient*)> comparator);
        vector<Staff*> filterStaff(function<bool(Staff*)> predicate);
        double getWardRevenue(string wardName);
        vector<Patient*> getStaffPatientHistory(string staffName);
        string getName() const;
        const vector<Patient>& getAdmittedPatients() const;
        const vector<Patient>& getArchivedPatients() const;
    };

    #endif