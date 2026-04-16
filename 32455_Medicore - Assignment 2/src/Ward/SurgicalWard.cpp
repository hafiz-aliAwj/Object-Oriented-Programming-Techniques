#include "../../headers/Ward/SurgicalWard.hpp"
#include "../../headers/Patient.hpp"
bool SurgicalWard::canAccept(const Patient& p) const {
 
    string diag = p.getDiagnosis();
 if (diag.find("Surgery") != string::npos || 
        diag.find("surgery") != string::npos || 
        diag.find("Operation") != string::npos || 
        diag.find("operation") != string::npos) {
        return true;
    }
const vector<Treatment>& treatments = p.getTreatments();
    for (size_t i = 0; i < treatments.size(); i++) {
        string tName = treatments[i].name;
        if (tName.find("surgery") != string::npos || 
            tName.find("Surgery") != string::npos || 
            tName.find("Operation") != string::npos || 
            tName.find("operation") != string::npos) {
            return true;
        }
    }
 return false;
}   