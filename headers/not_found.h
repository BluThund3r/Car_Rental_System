//
// Created by bluth on 28/04/2022.
//

#ifndef MAIN_CPP_NOT_FOUND_H
#define MAIN_CPP_NOT_FOUND_H

#include <exception>

class not_found: std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Masina cautata nu se afla la aceasta reprezentanta";
    }
};


#endif //MAIN_CPP_NOT_FOUND_H
