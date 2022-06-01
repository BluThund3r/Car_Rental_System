//
// Created by bluth on 31/05/2022.
//

#include "../headers/BuilderAdmin.h"
#include "../headers/null_username.h"
#include "../headers/not_unique_user.h"

BuilderAdmin& BuilderAdmin::username(const std::string& username) {
    a.username = username;
    return *this;
}

BuilderAdmin& BuilderAdmin::email(const std::string& email) {
    a.email = email;
    return *this;
}

BuilderAdmin& BuilderAdmin::bDay(const std::string& bday) {
    a.b_day = bday;
    return *this;
}

BuilderAdmin& BuilderAdmin::cnp(const std::string& cnp) {
    a.cnp = cnp;
    return *this;
}

BuilderAdmin& BuilderAdmin::name(const std::string& name) {
    a.name = name;
    return *this;
}

BuilderAdmin& BuilderAdmin::phone(const std::string& phone) {
    a.phone = phone;
    return *this;
}

BuilderAdmin& BuilderAdmin::age(const int& age) {
    a.age = age;
    return *this;
}

BuilderAdmin& BuilderAdmin::rep(const Reprezentanta& rep) {
    a.rep = rep;
    return *this;
}

Admin BuilderAdmin::build() {
    if(a.username.empty())
        throw null_username();
    if(User::existsUsername(a.username))
        throw not_unique_user();

    auto copy{a};
    a.clear();
    return copy;
}