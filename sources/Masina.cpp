//
// Created by bluth on 13/04/2022.
//

#include "../headers/Masina.h"
#include <iostream>

Masina::Masina(const std::string& reg_plate, const std::string& co, const std::string& model, const std::string& color, const std::string& fuel, const int& fab_year, const int& no_km, const double& hire_price, const bool& is_hired):
        fab_year(fab_year),
        no_km(no_km),
        reg_plate(reg_plate),
        fuel(fuel),
        color(color),
        model(model),
        co(co),
        is_hired(is_hired),
        hire_price(hire_price)
{
    std::cout << "Masina cu numarul de inmatriculare " << reg_plate << " a fost adaugata in aplicatie.\n";
}

Masina::Masina(const Masina& other):
        fab_year(other.fab_year),
        no_km(other.no_km),
        reg_plate(other.reg_plate),
        fuel(other.fuel),
        color(other.color),
        model(other.model),
        co(other.co),
        is_hired(other.is_hired),
        hire_price(other.hire_price)
{}

Masina& Masina::operator=(const Masina& other){
    reg_plate = other.reg_plate;
    fuel = other.fuel;
    color = other.color;
    model = other.model;
    co = other.co;
    fab_year = other.fab_year;
    no_km = other.no_km;
    is_hired = other.is_hired;
    hire_price = other.hire_price;
    return *this;
}

bool Masina::operator==(const Masina& m) const{
    return this->reg_plate == m.reg_plate;
}

Masina::~Masina(){
    std::cout << "Masina cu numarul de inmatriculare " << reg_plate << " a fost stearsa din aplicatie!\n";
}

std::ostream& operator<<(std::ostream& os, const Masina& car){
    os  << "========== Masina ==========\n"
        << "\tNumarul de inmatriculare: " << car.reg_plate <<'\n'
        << "\tMarca: " << car.co << '\n'
        << "\tModelul: " << car.model << '\n'
        << "\tCuloarea: " << car.color << '\n'
        << "\tAnul fabricatiei: " << car.fab_year << '\n'
        << "\tNumarul de kilometri parcursi: " << car.no_km << '\n';
    if(car.fuel == "electrica")
        os << "\tMasina electrica\n";
    else
        os << "\tTipul combustibilului: " << car.fuel << '\n';
    os  << "\tPretul de inchiriere: " << car.hire_price << " RON / zi\n"
        << "\tDisponibilitate: " << ((car.is_hired)? "Indisponibila momentan\n" : "Disponibila\n");

    os << "================== End Masina ==================\n";
    return os;
}
