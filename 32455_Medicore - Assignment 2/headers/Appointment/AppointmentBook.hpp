#ifndef APPOINT_BOOK_HPP
#define APPOINT_BOOK_HPP

#include <vector>
#include <string>
#include <functional>
#include "Appointment.hpp"

using namespace std;

class AppointmentBook {
private:
    vector<Appointment> appointments;

public:
    bool addAppointment(const Appointment& newAppt);
    void cancelAppointment(string patientID, string date, int hr, int min);
    
    vector<Appointment> getStaffSchedule(string staffID, string date) const;
    vector<Appointment> getPatientSchedule(string patientID) const;
};

#endif