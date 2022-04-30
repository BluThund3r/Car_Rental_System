//
// Created by bluth on 27/04/2022.
//

#ifndef MAIN_CPP_NOT_UNIQUE_USER_H
#define MAIN_CPP_NOT_UNIQUE_USER_H

#include "not_unique.h"

class not_unique_user: public not_unique {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Numele de utilizator este deja inregistrat";
    }
};


#endif //MAIN_CPP_NOT_UNIQUE_USER_H
