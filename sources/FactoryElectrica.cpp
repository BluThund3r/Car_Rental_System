//
// Created by bluth on 31/05/2022.
//

#include "../headers/FactoryElectrica.h"


std::shared_ptr<Masina> FactoryElectrica::createVW() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Electrica{regplate, "VolksWagen", "ID.4", "negru",
                                                        2021, 0, 300, 45000});
}

std::shared_ptr<Masina> FactoryElectrica::createDacia() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Electrica{regplate, "Dacia", "Spring", "negru",
                                                        2021, 0, 174.99, 27000});
}


std::shared_ptr<Masina> FactoryElectrica::createToyota() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Electrica{regplate, "Toyota","bZ4X", "negru",
                                                       2023, 0, 250, 45000});
}

std::shared_ptr<Masina> FactoryElectrica::createFord() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Electrica{regplate, "Ford","Mustang Mach-E", "negru",
                                                       2023, 0, 300, 45000});
}

std::shared_ptr<Masina> FactoryElectrica::createBMW() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Electrica{regplate, "BMW","i3", "negru",
                                                       2019, 0, 200, 30000});
}

std::shared_ptr<Masina> FactoryElectrica::createRenault() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Electrica{regplate,"Renault", "Megane", "negru",
                                                       2022, 0, 250, 40000});
}

std::shared_ptr<Masina> FactoryElectrica::createAudi() {
    std::string regplate = Masina::getValidRegPlate();
    return std::shared_ptr<Masina>(new Electrica{regplate, "Audi","e-Tron", "negru",
                                                       2023, 0, 350, 55000});
}