//
// Created by bluth on 31/05/2022.
//

#include "../headers/FactoryHybrid.h"

std::shared_ptr<Masina> FactoryHybrid::createToyota() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Hybrid{regplate, "Toyota", "Corola", "negru",
                                              2017, 30456, 174.99, 6500,
                                              M_Combustibil::motorina, 50});
}

std::shared_ptr<Masina> FactoryHybrid::createDacia() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Hybrid{regplate, "Dacia", "Jogger", "negru",
                                                        2023, 0, 250, 5500,
                                                        M_Combustibil::benzina, 55});
}


std::shared_ptr<Masina> FactoryHybrid::createVW() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Hybrid{regplate, "VolksWagen", "Arteon", "negru",
                                                        2020, 5000, 260, 7000,
                                                        M_Combustibil::motorina, 60});
}

std::shared_ptr<Masina> FactoryHybrid::createFord() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Hybrid{regplate, "Ford", "Puma", "negru",
                                                        2021, 2000, 270, 6500,
                                                        M_Combustibil::benzina, 55});
}

std::shared_ptr<Masina> FactoryHybrid::createBMW() {
    std::string regplate = Masina::getValidRegPlate();
   return std::shared_ptr<Masina>(new Hybrid{regplate, "BMW", "Seria 2", "negru",
                                                        2021, 2000, 300, 7000,
                                                        M_Combustibil::motorina, 60});
}

std::shared_ptr<Masina> FactoryHybrid::createRenault() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Hybrid{regplate, "Renault", "Captur E-Tech", "negru",
                                                        2019, 15000, 250, 5500,
                                                        M_Combustibil::motorina, 65});
}

std::shared_ptr<Masina> FactoryHybrid::createAudi() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Hybrid{regplate, "Audi", "A7", "negru",
                                                        2019, 20000, 300, 7000,
                                                        M_Combustibil::benzina, 60});
}