#include <iostream>
#include <vector>
#include <string>
#include "headers/Person.hpp"
#include "headers/Staff/Staff.hpp"
#include "headers/Staff/GP.hpp"
#include "headers/Staff/Surgeon.hpp"
#include "headers/Staff/Nurse.hpp"
#include "headers/Patient.hpp"
#include "headers/Ward/Ward.hpp"
#include "headers/Ward/GeneralWard.hpp"
#include "headers/Ward/ICU.hpp"
#include "headers/Ward/SurgicalWard.hpp"
#include "headers/ReportGenerator.hpp"
#include "headers/Appointment/Appointment.hpp"
#include "headers/Appointment/AppointmentBook.hpp"
#include "headers/Hospital.hpp"
using namespace std;

// headers for your own classes here.

void check(const string &testName, bool condition)
{
    cout << testName << ": " << (condition ? "PASS" : "FAIL") << endl;
}

int main()
{
    cout << "===== MediCore Assignment Demo =====" << endl;

    // ------------------------------------------------------------
    // TC-01 Polymorphic Display
    // ------------------------------------------------------------


    cout << "\n[TC-01] Polymorphic Display" << endl;

    // 1. Create one GP object
    GP* gp1 = new GP("Dr. Ali", "1990-01-01", "GP-001", "0300-1234567", 120000.0, "OPD", 1500.0);
    // 2. Create one Surgeon object
    Surgeon* surg1 = new Surgeon("Dr. Nameer", "1985-05-20", "SUR-99", "0321-7654321", 250000.0, "Surgery", "Orthopedic", 45000.0);

    // 3. Create one Nurse object
Nurse* nurse1 = new Nurse("Sister ", "1995-10-10", "NUR-05", "0345-1122334", 65000.0, "Pediatrics", 800.0, "Surgical Ward");
    // 4. Create one Patient object
Patient* pat1 = new Patient("Zubair", "2002-12-12", "PAT-101", "0312-9988776", "Appendicitis", "2026-04-14", "Surgical Ward", false);

    // 5. Put them into a collection of base-class pointers (Person*)
    vector<Person *> people;
    people.push_back(gp1);
    people.push_back(surg1);
    people.push_back(nurse1);
    people.push_back(pat1);

    // 6. Call display using a loop
    bool allChecksPass = true;
    for (Person *p : people)
    {
        string summary = p->getSummary();
        cout << summary << endl;
        if (summary.length() == 0)
            allChecksPass = false;
    }

    bool condition1 = ((gp1->getSummary().find("1500") != string::npos) && (surg1->getSummary().find("Orthopedic") != string::npos) && (surg1->getSummary().find("45000") != string::npos) && (nurse1->getSummary().find("Surgical Ward") != string::npos) && (pat1->getSummary().find("Appendicitis") != string::npos) && (pat1->getSummary().find("2026-04-14") != string::npos));

    // cout << "all check pass" << boolalpha << allChecksPass << endl;
    // cout << "gp" << boolalpha << (gp1.getSummary().find("1500") != string::npos) << endl;
    // cout << "sur" << boolalpha << (surg1.getSummary().find("Orthopedic") != string::npos) << endl;
    // cout << "sur" << boolalpha << (surg1.getSummary().find("45000") != string::npos) << endl;
    // cout << "nurse" << boolalpha << (nurse1.getSummary().find("Surgical Ward") != string::npos) << endl;
    // cout << "pat" << boolalpha << (pat1.getSummary().find("Appendicitis") != string::npos) << endl;
    // cout << "pat" << boolalpha << (pat1.getSummary().find("2026-04-14") != string::npos) << endl;
    check("TC-01", allChecksPass && condition1);

    // ------------------------------------------------------------
    // TC-02 Billing Operator Overloading
    // Goal: Generate two bills and verify operator behaviour.
    // ------------------------------------------------------------
    cout << "\n[TC-02] Billing Operators" << endl;

    GeneralWard genWard("General Ward", 10, 1200.0);
    SurgicalWard surgWard("Surgical Ward", 10, 5500.0);

    pat1->setWard(&genWard);
    pat1->addTreatment("Consultation", 2000.0, "Dr. Ali");
    pat1->addTreatment("Blood Test", 3000.0, "Dr. Ali");
    Bill b1 = pat1->generateBill(3);

Patient* pat2 = new Patient("Hassan", "1998-05-05", "P-102", "0300-5554443", "Surgery Needed", "2026-04-12", "Surgical", false);
    pat2->setWard(&surgWard);
    pat2->addTreatment("Minor Procedure", 10000.0, "Dr. Qais");
    Bill b2 = pat2->generateBill(1);

    Bill combined = b1 + b2;

    cout << "Combined Summary: " << combined << endl;
    Bill expectedCombined(15000.0, 9100.0, 1000.0);
    check("TC-02.1 ", combined == expectedCombined);
    check("TC-02.2 ", !(b1 == b2));
    Bill b3 = b1;
    check("TC-02.3 ", b1 == b3);

      // ------------------------------------------------------------
    // TC-03 Ward Comparison Operators
    // Goal: Compare wards using occupancy percentage.
    // ------------------------------------------------------------
    cout << "\n[TC-03] Ward Comparison" << endl;
    GeneralWard w1("Ward A", 20, 1000.0);
    ICU w2("ICU", 5, 5000.0);
    Patient p1("Pa", "dob", "1", "ph", "critical", "date", "ICU", true);
    Patient p2("Pb", "dob", "2", "ph", "critical", "date", "ICU", true);
    Patient p3("Pc", "dob", "3", "ph", "flu", "date", "Gen", false);
    w1.addPatient(&p3);
    w2.addPatient(&p1);
    w2.addPatient(&p2);
    check("TC-03.1 ", w1 < w2);
    check("TC-03.2 ", w2 > w1);

    check("TC-03.3 ", !(w1 == w2));
    // cout << w1.getName() << " Occupancy: " << (w1.getOccupancyPercentage() * 100) << "%" << endl;
    // cout << w2.getName() << " Occupancy: " << (w2.getOccupancyPercentage() * 100) << "%" << endl;




    // ------------------------------------------------------------
    // TC-04 Ward Admission Rules
    // Goal: Show that different ward types admit/reject patients differently.
    // ------------------------------------------------------------
    cout << "\n[TC-04] Ward Admission Rules" << endl;

    Patient criticalPat("Ali Khan", "1980-01-01", "P-ICU", "0300-1112223", "critical: Cardiac arrest", "2026-04-15", "ICU", true);
    Patient routinePat("Sara Baig", "1995-05-05", "P-GEN", "0300-4445556", "Sprained ankle", "2026-04-15", "General", false);
    Patient surgeryPat("Kamran", "1988-08-08", "P-SURG", "0300-7778889", "Requires knee surgery", "2026-04-15", "Surgical", false);

    ICU icuWard("ICU Unit", 5, 8000.0);
    GeneralWard genWard2("General Ward", 20, 1500.0);
    SurgicalWard surgWard2("Surgical Complex", 10, 6000.0);
    bool icuAcceptsCritical = icuWard.addPatient(&criticalPat);
    bool icuRejectsRoutine = !icuWard.addPatient(&routinePat);
    bool genAcceptsRoutine = genWard2.addPatient(&routinePat);
    bool surgAcceptsSurgery = surgWard2.addPatient(&surgeryPat);

    // check("TC-04.1 ", icuAcceptsCritical);
    // check("TC-04.1 ", icuRejectsRoutine);
    check("TC-04.1 ", icuAcceptsCritical && icuRejectsRoutine);
    check("TC-04.2 ", genAcceptsRoutine);
    check("TC-04.3 ", surgAcceptsSurgery);

    // ------------------------------------------------------------
    // TC-05 Double-Booking Prevention
    // Goal: Same staff member cannot have two appointments
    //       at same date and same time slot.
    // ------------------------------------------------------------
    cout << "\n[TC-05] Double-Booking Prevention" << endl;

    AppointmentBook book;

bool res1 = book.addAppointment(Appointment(pat1, gp1, "2026-04-20", {10, 0, 30}));

bool res2 = book.addAppointment(Appointment(pat2, gp1, "2026-04-20", {10, 0, 30}));

bool res3 = book.addAppointment(Appointment(pat2, gp1, "2026-04-20", {11, 0, 30}));
    check("TC-05.1 ", res1 == true);
    check("TC-05.2 ", res2 == false);
    check("TC-05.3 ", res3 == true);

    // cout << "Total appointments scheduled: " << book.getPatientSchedule(pat2.getID()).size() + 1 << endl;

    // ------------------------------------------------------------
    // TC-06 Copy Independence
    // Goal: Copying a patient should create an independent copy.
    // ------------------------------------------------------------
    cout << "\n[TC-06] Copy Independence" << endl;

    Patient original("Hamid Raza", "1975-03-12", "P-999", "0321-1112223", "Checkup", "2026-04-10", "General", false);
    original.addTreatment("Blood test", 500.0, "Dr. Alvi");
    Patient copyOfPatient = original;
    copyOfPatient.addTreatment("MRI", 8000.0, "Dr. Khan");
    bool originalIntact = (original.getTreatments().size() == 1);
    bool copyUpdated = (copyOfPatient.getTreatments().size() == 2);

    check("TC-06.1 ", originalIntact);
    check("TC-06.2 ", copyUpdated);

    // cout << "Original Treatment Count: " << original.getTreatments().size() << endl;
    // cout << "Copy Treatment Count: " << copyOfPatient.getTreatments().size() << endl;
// ------------------------------------------------------------
    // TC-07 Move Semantics / Archive
    // ------------------------------------------------------------
    cout << "\n[TC-07] Move to Archive" << endl;

    Hospital h7("MediCore General");
    string pId = "P-101";
    Patient p7("Zubair Ahmed", "1990-05-15", pId, "0333-1234567", "Fever", "2026-04-15", "General", false);

    h7.admit(p7);
    bool initiallyAdmitted = h7.isAdmitted(pId);

    bool dischargeSuccess = h7.discharge(pId);
    bool notInLive = !h7.isAdmitted(pId);
    bool inArchive = h7.isArchived(pId);

    check("TC-07.1 ", initiallyAdmitted && notInLive);
    check("TC-07.2 ", dischargeSuccess && inArchive);

    const vector<Patient*>& history = h7.getArchivedPatients();
    if (!history.empty()) {
        check("TC-07.3 ", history.back()->getName() == "Zubair Ahmed");
    }







    // ------------------------------------------------------------
    // TC-08 Lambda-Based Queries
    // ------------------------------------------------------------
    cout << "\n[TC-08] Lambda-Based Queries" << endl;

    Hospital hQuery("Query Center");
    hQuery.admit(Patient("Ali Khan", "1990", "P01", "0300", "critical condition", "2026-04-10", "ICU", true));
    hQuery.admit(Patient("Sara Ahmed", "1995", "P02", "0321", "flu symptoms", "2026-04-11", "General", false));
    hQuery.admit(Patient("Zain Malik", "1988", "P03", "0333", "critical: trauma", "2026-04-12", "ICU", true));

    auto criticalInICU = hQuery.filterPatients([](Patient *p) { 
        return (p->getDiagnosis().find("critical") != string::npos); 
    });

    auto sortedView = hQuery.filterPatients([](Patient *p) { return true; });
    
    ReportGenerator::sortPatients(sortedView, [](Patient *a, Patient *b) {
        return a->getID() > b->getID(); 
    });

    bool filterSuccess = (criticalInICU.size() == 2);
    bool sortSuccess = (!sortedView.empty() && sortedView[0]->getID() == "P03");

    check("TC-08.1 ", filterSuccess);
    check("TC-08.2  ", sortSuccess);



    // ------------------------------------------------------------
    // TC-09 Staff Billing Rate Polymorphism
    // Goal: Different staff types return different billing rates
    //       through one common interface.
    // ------------------------------------------------------------
    cout << "\n[TC-09] Staff Billing Rate Polymorphism" << endl;

    vector<Staff *> medicalTeam;
    medicalTeam.push_back(gp1);
    medicalTeam.push_back(surg1);

    double rate1 = medicalTeam[0]->getBillingRate();
    double rate2 = medicalTeam[1]->getBillingRate();

    bool ratesAreDifferent = (rate1 != rate2);

    check("TC-09.1 ", ratesAreDifferent);

    // for (Staff* s : medicalTeam) {
    //     cout << "Staff: " << s->getName() << " | Rate: PKR " << s->getBillingRate() << endl;
    // }

    // ------------------------------------------------------------
    // TC-10 Ward Revenue
    // Goal: Compute total revenue for a given ward.
    // ------------------------------------------------------------
    cout << "\n[TC-10] Ward Revenue" << endl;

    Hospital h10("Finance Dept");
   ICU* icuWard2 = new ICU("ICU Unit", 5, 8000.0);
    h10.addWard(icuWard2);

    Patient p10_1("Patient X", "1990", "PX", "000", "Critical Condition", "2026-04-01", "ICU Unit", true);
    p10_1.setWard(icuWard2);
    p10_1.addTreatment("Consultation", 1000.0, "Dr. Ali");

    Patient p10_2("Patient Y", "1992", "PY", "111", "Critical Condition", "2026-04-02", "ICU Unit", true);
    p10_2.setWard(icuWard2);
    p10_2.addTreatment("X-Ray", 2000.0, "Dr. Qais");

    h10.admit(p10_1);
    h10.admit(p10_2);
    h10.discharge("PX");
    h10.discharge("PY");

    double totalRevenue = ReportGenerator::calculateWardRevenue("ICU Unit", h10.getArchivedPatients());

    double expected = 84000.0;

    check("TC-10 ", totalRevenue == expected);

    // cout << "Final ICU Revenue: PKR " << totalRevenue << endl;
    cout << "\n===== Demo Finished =====" << endl;
    delete gp1;
delete surg1;
delete nurse1;
delete pat1;
delete pat2;

    return 0;
}