#include "../../headers/Appointment/AppointmentBook.hpp"

bool AppointmentBook::addAppointment(const Appointment& newAppt) {
    for (const auto& existing : appointments) {
        // Only check overlap if it's the same staff member on the same day
        if (existing.getStaff()->getID() == newAppt.getStaff()->getID() && 
            existing.getDate() == newAppt.getDate()) {
            
            if (existing.getTimeSlot().overlapsWith(newAppt.getTimeSlot())) {
                return false; // Conflict detected
            }
        }
    }

    appointments.push_back(newAppt);
    return true;
}

void AppointmentBook::cancelAppointment(string patientID, string date, int hr, int min) {
    for (auto it = appointments.begin(); it != appointments.end(); ++it) {
        if (it->getPatient()->getID() == patientID && 
            it->getDate() == date && 
            it->getTimeSlot().startHour == hr && 
            it->getTimeSlot().startMinute == min) {
            
            appointments.erase(it);
            return;
        }
    }
}

vector<Appointment> AppointmentBook::getStaffSchedule(string staffID, string date) const {
    vector<Appointment> result;
    for (const auto& appt : appointments) {
        if (appt.getStaff()->getID() == staffID && appt.getDate() == date) {
            result.push_back(appt);
        }
    }
    return result;
}

vector<Appointment> AppointmentBook::getPatientSchedule(string patientID) const {
    vector<Appointment> result;
    for (const auto& appt : appointments) {
        if (appt.getPatient()->getID() == patientID) {
            result.push_back(appt);
        }
    }
    return result;
}