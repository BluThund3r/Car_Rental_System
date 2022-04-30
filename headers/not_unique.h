//
// Created by bluth on 26/04/2022.
//

#ifndef MAIN_CPP_NOT_UNIQUE_H
#define MAIN_CPP_NOT_UNIQUE_H


#include <exception>
#include <string>

class not_unique: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override{
        return "The value of the unique identifier is already assigned to an object";
    }
};


#endif //MAIN_CPP_NOT_UNIQUE_H
