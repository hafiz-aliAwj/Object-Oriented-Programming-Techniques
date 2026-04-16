#ifndef SURGICAL_WARD_HPP
#define SURGICAL_WARD_HPP

#include "Ward.hpp"

class SurgicalWard : public Ward {
public:
    using Ward::Ward;
    bool canAccept(const Patient& p) const override;
};

#endif