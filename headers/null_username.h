//
// Created by bluth on 31/05/2022.
//

#ifndef MAIN_CPP_NULL_USERNAME_H
#define MAIN_CPP_NULL_USERNAME_H

#include <exception>

class null_username: std::exception {
public:
     [[nodiscard]] const char* what() const noexcept override {
        return "Username-ul nu poate fi null";
    }
};


#endif //MAIN_CPP_NULL_USERNAME_H
