//
// Created by bluth on 13/04/2022.
//

#include "../headers/Reprezentanta.h"
#include "../headers/not_found.h"
#include <iostream>
#include <vector>


IDgen<Reprezentanta> Reprezentanta::gen_id;

Reprezentanta::Reprezentanta(const std::string& address, const std::vector<std::shared_ptr<Masina>>& cars):
        cars(cars),
        address(address),
        id(gen_id.generate())
        {}

Reprezentanta::Reprezentanta(const Reprezentanta& other):
    address(other.address),
    id(other.id)
    {
        for(const auto& car : other.cars)
            cars.push_back(car->clone());
    }

int Reprezentanta::find_car(const std::shared_ptr<Masina>& m) const {
    for(int i = 0; i < (int)cars.size(); ++ i)
        if(*cars[i] == *m)
            return i;

    throw not_found();
}

void Reprezentanta::add_car(const std::shared_ptr<Masina>& m){
    cars.push_back(m);
}

const std::shared_ptr<Masina>&  Reprezentanta::delete_car(const std::shared_ptr<Masina>& m){
    int pos = this->find_car(m);
    cars.erase(cars.begin() + pos);
    return m;
}

void swap(Reprezentanta& r1, Reprezentanta& r2) {
    using std::swap;
    swap(r1.id, r2.id);
    swap(r1.address, r2.address);
    swap(r1.cars, r2.cars);
}

std::ostream& operator<<(std::ostream& os, const Reprezentanta& rep){
    os  << "========== Reprezentanta ==========\n"
        << "\tId: " << rep.id << '\n'
        << "\tAdresa: " << rep.address << '\n'
        << "\tNumar de masini: " << rep.cars.size() << '\n';
    if(!rep.cars.empty()) {
        std::cout << "\tMasinile din reprezentanta:";
        for(int i = 0; i < (int)rep.cars.size(); ++ i) {
            std::cout << "\n\t\t> " << rep.cars[i]->get_reg_plate();
        }
    }
    else
        std::cout << "\nReprezentanta nu are masini in momentul de fata.";

    os << "\n================== End Reprezentanta ==================\n";
    return os;
}

Reprezentanta& Reprezentanta::operator=(const Reprezentanta &other) {
    auto copy{other};
    swap(copy, *this);
    return *this;
}