//
// Created by bluth on 31/05/2022.
//

#ifndef MAIN_CPP_BUILDERADMIN_H
#define MAIN_CPP_BUILDERADMIN_H

#include "Admin.h"

class BuilderAdmin {
    Admin a;
public:
    BuilderAdmin() = default;

    BuilderAdmin& username(const std::string&);
    BuilderAdmin& email(const std::string&);
    BuilderAdmin& bDay(const std::string&);
    BuilderAdmin& cnp(const std::string&);
    BuilderAdmin& name(const std::string&);
    BuilderAdmin& phone(const std::string&);
    BuilderAdmin& age(const int&);
    BuilderAdmin& rep(const Reprezentanta&);
    Admin build();

};


#endif //MAIN_CPP_BUILDERADMIN_H
