//
// Created by bluth on 31/05/2022.
//

#include "../headers/FactoryCombustibil.h"

std::shared_ptr<Masina> FactoryCombustibil::createVW() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new M_Combustibil{regplate, "VolksWagen", "Golf 7", "negru",
                                                        2018, 15000, 200, 60, M_Combustibil::benzina});
}

std::shared_ptr<Masina> FactoryCombustibil::createDacia() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new M_Combustibil{regplate, "Dacia", "Duster", "negru",
                                                        2017, 20000, 200, 65, M_Combustibil::benzina});
}


std::shared_ptr<Masina> FactoryCombustibil::createToyota() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new M_Combustibil{regplate, "Toyota", "Mirai", "negru",
                                                        2015, 10000, 200, 55, M_Combustibil::motorina});
}

std::shared_ptr<Masina> FactoryCombustibil::createFord() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new M_Combustibil{regplate, "Ford", "Mustang", "negru",
                                                        2019, 10000, 250, 60, M_Combustibil::benzina});
}

std::shared_ptr<Masina> FactoryCombustibil::createBMW() {
    std::string regplate = Masina::getValidRegPlate();
   return std::shared_ptr<Masina>(new M_Combustibil{regplate, "BMW", "X3", "negru",
                                                        2017, 30000, 250, 60, M_Combustibil::motorina});
}

std::shared_ptr<Masina> FactoryCombustibil::createRenault() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new M_Combustibil{regplate, "Renault", "Megane 4", "negru",
                                                        2019, 20000, 200, 55, M_Combustibil::motorina});
}

std::shared_ptr<Masina> FactoryCombustibil::createAudi() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new M_Combustibil{regplate, "Audi", "A5", "negru",
                                                        2018, 25000, 250, 65, M_Combustibil::benzina});
}