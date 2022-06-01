//
// Created by bluth on 01/06/2022.
//

#ifndef MAIN_CPP_EMPTY_EXCEPTION_H
#define MAIN_CPP_EMPTY_EXCEPTION_H

#include <exception>

class empty_exception:public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override{
        return "Colectia nu poate fi vida";
    }
};


#endif //MAIN_CPP_EMPTY_EXCEPTION_H
