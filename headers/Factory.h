//
// Created by bluth on 31/05/2022.
//

#ifndef MAIN_CPP_FACTORY_H
#define MAIN_CPP_FACTORY_H

#include <memory>
#include "Electrica.h"
#include "Hybrid.h"
#include "M_Combustibil.h"
#include "Masina.h"

class Factory {
public:
    virtual std::shared_ptr<Masina> createVW() = 0;
    virtual std::shared_ptr<Masina> createDacia() = 0;
    virtual std::shared_ptr<Masina> createToyota() = 0;
    virtual std::shared_ptr<Masina> createFord() = 0;
    virtual std::shared_ptr<Masina> createBMW() = 0;
    virtual std::shared_ptr<Masina> createRenault() = 0;
    virtual std::shared_ptr<Masina> createAudi() = 0;
    virtual ~Factory() = default;
};

#endif //MAIN_CPP_FACTORY_H
