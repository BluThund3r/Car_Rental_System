//
// Created by bluth on 13/04/2022.
//

#ifndef MAIN_CPP_ADMIN_H
#define MAIN_CPP_ADMIN_H
#include "Reprezentanta.h"

class Admin{
    Reprezentanta rep;
    std::string pass, username, email, nr_telefon;

public:
    Admin(const Reprezentanta& rep, const std::string& username, const std::string& email, const std::string& pass, const std::string& nr_telefon);
    ~Admin();
    friend std::ostream& operator<<(std::ostream& os, const Admin& admin);
};

#endif //MAIN_CPP_ADMIN_H
