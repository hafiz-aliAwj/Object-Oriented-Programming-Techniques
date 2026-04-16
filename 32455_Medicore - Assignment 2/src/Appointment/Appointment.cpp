#include "../../headers/Appointment/Appointment.hpp"

Appointment::Appointment(Patient* p, Staff* s, string d, TimeSlot ts) 
    : patient(p), staff(s), date(d), slot(ts), status("Scheduled") {}



Patient* Appointment::getPatient() const { return patient; }
Staff* Appointment::getStaff() const { return staff; }
string Appointment::getDate() const { return date; }
TimeSlot Appointment::getTimeSlot() const { return slot; }
string Appointment::getStatus() const { return status; }
void Appointment::setStatus(string s) { status = s; }