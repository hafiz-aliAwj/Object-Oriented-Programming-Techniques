#include "../../headers/Ward/ICU.hpp"
#include "../../headers/Patient.hpp"
bool ICU::canAccept(const Patient& p) const {
    return p.isCritical();
}