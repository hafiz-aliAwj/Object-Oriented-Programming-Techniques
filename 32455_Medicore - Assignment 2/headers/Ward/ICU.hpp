#ifndef ICU_HPP
#define ICU_HPP

#include "Ward.hpp"

class ICU : public Ward {
public:
    using Ward::Ward;
    bool canAccept(const Patient& p) const override;
};

#endif