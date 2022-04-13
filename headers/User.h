//
// Created by bluth on 13/04/2022.
//

#ifndef MAIN_CPP_USER_H
#define MAIN_CPP_USER_H
#include <optional>
#include "Masina.h"
#include "Reprezentanta.h"

class User{
    std::string username, email, pass, b_day, cnp, name;
    int age;
    double bal;
    std::optional<Masina> hired_car;


public:
    void hire(Reprezentanta&, const Masina&);
    void unhire();
    User(const std::string& username, const std::string& email, const std::string& pass, const std::string& b_day, const std::string& cnp, const std::string& name, const int& age, const double& bal, const std::optional<Masina>& = std::nullopt);
    ~User();
    friend std::ostream& operator<<(std::ostream& os, const User& user);
    void load_account(const double& value){bal += value;}
};


#endif //MAIN_CPP_USER_H
