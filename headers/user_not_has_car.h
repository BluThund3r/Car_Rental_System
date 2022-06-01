//
// Created by bluth on 30/05/2022.
//

#ifndef MAIN_CPP_USER_NOT_HAS_CAR_H
#define MAIN_CPP_USER_NOT_HAS_CAR_H

#include <exception>

class user_not_has_car: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Acest user nu are nici o masina";
    }
};


#endif //MAIN_CPP_USER_NOT_HAS_CAR_H
