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
        return "Valoarea identificatorului unic este deja atribuita unui obiect";
    }
};


#endif //MAIN_CPP_NOT_UNIQUE_H
