//
// Created by bluth on 31/05/2022.
//

#ifndef MAIN_CPP_FACTORYCOMBUSTIBIL_H
#define MAIN_CPP_FACTORYCOMBUSTIBIL_H

#include "Factory.h"

class FactoryCombustibil:public Factory {
public:
    std::shared_ptr<Masina> createVW() override;
    std::shared_ptr<Masina> createDacia() override;
    std::shared_ptr<Masina> createToyota() override;
    std::shared_ptr<Masina> createFord() override;
    std::shared_ptr<Masina> createBMW() override;
    std::shared_ptr<Masina> createRenault() override;
    std::shared_ptr<Masina> createAudi() override;
};


#endif //MAIN_CPP_FACTORYCOMBUSTIBIL_H
