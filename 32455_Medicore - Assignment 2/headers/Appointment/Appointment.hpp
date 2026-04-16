#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include <string>
#include "../Patient.hpp"
#include "../Staff/Staff.hpp"

using namespace std;

struct TimeSlot {
    int startHour;
    int startMinute;
    int durationMinutes;

    bool overlapsWith(const TimeSlot& other) const {
        int thisStart = startHour * 60 + startMinute;
        int thisEnd = thisStart + durationMinutes;
        int otherStart = other.startHour * 60 + other.startMinute;
        int otherEnd = otherStart + other.durationMinutes;

        return (thisStart < otherEnd && otherStart < thisEnd);
    }
};

class Appointment {
private:
    Patient* patient;
    Staff* staff;
    string date;
    TimeSlot slot;
    string status;

public:
    Appointment(Patient* p, Staff* s, string d, TimeSlot ts);
    
    Patient* getPatient() const;
    Staff* getStaff() const;
    string getDate() const;
    TimeSlot getTimeSlot() const;
    string getStatus() const;
    void setStatus(string s);
};

#endif