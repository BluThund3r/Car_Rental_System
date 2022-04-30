//
// Created by bluth on 26/04/2022.
//

#ifndef MAIN_CPP_NEGATIVE_QTTY_H
#define MAIN_CPP_NEGATIVE_QTTY_H


#include <exception>

class negative_qtty: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override{
        return "Cantitatea de combustibil / energie electrica nu poate fi negativa";
    }
};


#endif //MAIN_CPP_NEGATIVE_QTTY_H
