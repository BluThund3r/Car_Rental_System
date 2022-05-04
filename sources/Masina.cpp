//
// Created by bluth on 13/04/2022.
//

#include "../headers/Masina.h"
#include "../headers/not_unique_car.h"
#include "../headers/negative_qtty.h"
#include <iostream>

std::unordered_set<std::string> Masina::regPlates;

Masina::Masina(const std::string& reg_plate, const std::string& co, const std::string& model, const std::string& color, const int& fab_year, const int& no_km, const double& hire_price, const bool& is_hired):
        reg_plate(reg_plate),
        co(co),
        model(model),
        color(color),
        fab_year(fab_year),
        no_km(no_km),
        hire_price(hire_price),
        is_hired(is_hired)
{
    addRegPlate();
}

Masina::Masina(const Masina& other):
        reg_plate(other.reg_plate),
        co(other.co),
        model(other.model),
        color(other.color),
        fab_year(other.fab_year),
        no_km(other.no_km),
        hire_price(other.hire_price),
        is_hired(other.is_hired)
{}

Masina& Masina::operator=(const Masina& other){
    reg_plate = other.reg_plate;
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

std::ostream& operator<<(std::ostream& os, const Masina& car){
    car.afis(os);
    return os;
}

Masina::~Masina() {}

void Masina::charge(const double& qtty) {
    if(qtty < 0)
        throw negative_qtty();
    std::cout << "class Masina\t";
    std::cout << "Masina a fost alimentata cu " << qtty << " litri de combustibi\n";
}

void Masina::honk() const {std::cout << "Honk Masina\n";}

void Masina::addRegPlate() {
    if(regPlates.find(reg_plate) != regPlates.end())
        throw not_unique_car();
    regPlates.insert(reg_plate);
}

void Masina::afis(std::ostream& os) const {
    os  << "========== Masina ==========\n"
        << "\tNumarul de inmatriculare: " << reg_plate <<'\n'
        << "\tMarca: " << co << '\n'
        << "\tModelul: " << model << '\n'
        << "\tCuloarea: " << color << '\n'
        << "\tAnul fabricatiei: " << fab_year << '\n'
        << "\tNumarul de kilometri parcursi: " << no_km << '\n';
    os  << "\tPretul de inchiriere: " << hire_price << " RON / zi\n"
        << "\tDisponibilitate: " << ((is_hired)? "Indisponibila momentan\n" : "Disponibila\n");

    os << "================== End Masina ==================\n";
}