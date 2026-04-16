#ifndef GENERAL_WARD_HPP
#define GENERAL_WARD_HPP

#include "Ward.hpp"

class GeneralWard : public Ward {
public:
    using Ward::Ward; 
    bool canAccept(const Patient& p) const override;
};

#endif