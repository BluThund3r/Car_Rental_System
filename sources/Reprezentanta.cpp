//
// Created by bluth on 13/04/2022.
//

#include "../headers/Reprezentanta.h"
#include <iostream>
#include <vector>


int Reprezentanta::gen_id = 0;

int Reprezentanta::find_car(const Masina &m) const {                      // returneaza pozitia pe care se afla masina data ca parametru in vectorul de cars din reprezentanta sau -1 daca nu exista masina respectiva in reprezentanta
    for(int i = 0; i < (int)cars.size(); ++ i)
        if(cars[i] == m)
            return i;

    return -1;
}

void Reprezentanta::add_car(const Masina& m){
    cars.push_back(m);
}

void Reprezentanta::delete_car(const Masina& m){
    int pos = this->find_car(m);
    if(pos != -1) {
        cars.erase(cars.begin() + pos);
        return;
    }

    std::cout << "Masina cu numarul de inmatriculare " << m.get_reg_plate() << " nu este inregistrata la aceasta reprezentanta!\n";
}

Reprezentanta::Reprezentanta(const std::vector<Masina>& cars , const std::string& address):
        cars(cars), address(address), id(++gen_id){
    std::cout << "Reprezentanta cu id-ul " << id << " a fost adaugata in aplicatie.\n";
}

Reprezentanta::~Reprezentanta(){
    std::cout << "Reprezentanta cu id-ul " << id << " a fost stearsa din aplicatie!\n";
}

std::ostream& operator<<(std::ostream& os, const Reprezentanta& rep){
    os  << "========== Reprezentanta ==========\n"
        << "\tId: " << rep.id << '\n'
        << "\tAdresa: " << rep.address << '\n'
        << "\tNumar de masini: " << rep.cars.size() << '\n';
    if(!rep.cars.empty()) {
        std::cout << "\nMasinile din reprezentanta:\n\n";
        for(int i = 0; i < (int)rep.cars.size(); ++ i)
            os << rep.cars[i] << "\n";
    }
    else
        std::cout << "Reprezentanta nu are masini in momentul de fata.\n";

    os << "================== End Reprezentanta ==================\n";
    return os;
}