//
// Created by bluth on 31/05/2022.
//

#include "../headers/BasicUserBuilder.h"
#include "../headers/null_username.h"
#include "../headers/not_unique_user.h"

BasicUserBuilder& BasicUserBuilder::username(const std::string& username) {
    u.username = username;
    return *this;
}

BasicUserBuilder& BasicUserBuilder::email(const std::string& email) {
    u.email = email;
    return *this;
}

BasicUserBuilder& BasicUserBuilder::bDay(const std::string& bday) {
    u.b_day = bday;
    return *this;
}

BasicUserBuilder& BasicUserBuilder::cnp(const std::string &cnp) {
    u.cnp = cnp;
    return *this;
}

BasicUserBuilder& BasicUserBuilder::name(const std::string &name) {
    u.name = name;
    return *this;
}

BasicUserBuilder& BasicUserBuilder::phone(const std::string &phone) {
    u.phone = phone;
    return *this;
}

BasicUserBuilder& BasicUserBuilder::age(const int &age) {
    u.age = age;
    return *this;
}

BasicUserBuilder& BasicUserBuilder::car(const std::shared_ptr<Masina> &m) {
    u.car = m;
    return *this;
}

BasicUserBuilder& BasicUserBuilder::bal(const double &bal) {
    u.bal = bal;
    return *this;
}


BasicUser BasicUserBuilder::build() {
    if(u.username.empty())
        throw null_username();
    if(User::existsUsername(u.username))
        throw not_unique_user();

    auto copy{u};
    u.clear();
    return copy;
}
