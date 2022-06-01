//
// Created by bluth on 31/05/2022.
//

#ifndef MAIN_CPP_BASICUSERBUILDER_H
#define MAIN_CPP_BASICUSERBUILDER_H

#include "BasicUser.h"

class BasicUserBuilder {
    BasicUser u;
public:
    BasicUserBuilder() = default;

    BasicUserBuilder& username(const std::string&);
    BasicUserBuilder& email(const std::string&);
    BasicUserBuilder& bDay(const std::string&);
    BasicUserBuilder& cnp(const std::string&);
    BasicUserBuilder& name(const std::string&);
    BasicUserBuilder& phone(const std::string&);
    BasicUserBuilder& age(const int&);
    BasicUserBuilder& car(const std::shared_ptr<Masina>&);
    BasicUserBuilder& bal(const double&);
    BasicUser build();

};


#endif //MAIN_CPP_BASICUSERBUILDER_H
