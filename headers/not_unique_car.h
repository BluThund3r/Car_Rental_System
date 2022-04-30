//
// Created by bluth on 27/04/2022.
//

#ifndef MAIN_CPP_NOT_UNIQUE_CAR_H
#define MAIN_CPP_NOT_UNIQUE_CAR_H


#include "not_unique.h"

class not_unique_car: public not_unique {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "O masina cu acest numar de inmatriculare este deja inregistrata";
    }
};


#endif //MAIN_CPP_NOT_UNIQUE_CAR_H
