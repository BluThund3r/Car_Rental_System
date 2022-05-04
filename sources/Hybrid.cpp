//
// Created by bluth on 22/04/2022.
//

#include <iostream>
#include "../headers/Hybrid.h"
#include "../headers/negative_qtty.h"

Hybrid::Hybrid(const std::string &reg_plate, const std::string &co, const std::string &model, const std::string &color,
               const int &fab_year, const int &no_km, const double &hire_price, const double &batCapacity, fuel_type ftype,
               const double &tankCap, const double &tankLvl, const double &batLvl, const bool &is_hired):
        Masina(reg_plate, co, model, color, fab_year, no_km, hire_price, is_hired),
        M_Combustibil(reg_plate, co, model, color, fab_year, no_km, hire_price, tankCap, ftype, tankLvl, is_hired),
        Electrica(reg_plate, co, model, color, fab_year, no_km, hire_price, batCapacity, batLvl, is_hired)
{}

Hybrid::Hybrid(const Hybrid& other):
    Masina(other),
    M_Combustibil(other),
    Electrica(other) {}

void Hybrid::charge(const double &qtty) {
    if(qtty < 0)
        throw negative_qtty();


    tank_lvl += qtty;
    if(tank_lvl > tank_cap)
        tank_lvl = tank_cap;
    std::cout << "Ati alimentat masina " << this->reg_plate << " pana la " << this->tank_lvl << " litri\n";
}

std::ostream &operator<<(std::ostream &os, const Hybrid &car) {
    car.afis(os);
    return os;
}

Hybrid& Hybrid::operator=(const Hybrid& other) {
    auto copy{other};
    swap(copy, *this);
    return *this;
}

void swap(Hybrid& h1, Hybrid& h2) {
    using std::swap;
    swap(h1.reg_plate, h2.reg_plate);
    swap(h1.co, h2.co);
    swap(h1.model, h2.model);
    swap(h1.color, h2.color);
    swap(h1.fab_year, h2.fab_year);
    swap(h1.no_km, h2.no_km);
    swap(h1.hire_price, h2.hire_price);
    swap(h1.is_hired, h2.is_hired);
    swap(h1.tank_lvl, h2.tank_lvl);
    swap(h1.tank_cap, h2.tank_cap);
    swap(h1.bat_lvl, h2.bat_lvl);
    swap(h1.bat_capacity, h2.bat_capacity);
    swap(h1.ftype, h2.ftype);
}

void Hybrid::honk() const {
    std::cout << "Honk Hybrid\n";
}

void Hybrid::afis(std::ostream &os) const {
     os  << "========== Masina ==========\n"
        << "\tNumarul de inmatriculare: " << reg_plate <<'\n'
        << "\tMarca: " << co << '\n'
        << "\tModelul: " << model << '\n'
        << "\tCuloarea: " << color << '\n'
        << "\tMASINA HYBRID\n"
        << "\tTipul combustibilului: ";
    switch(ftype) {
            case 0 : {os << "Benzina\n"; break;}
            case 1 : {os << "Motorina\n"; break;}
            case 2 : {os << "GPL\n"; break;}
    }
    os  << "\tAnul fabricatiei: " << fab_year << '\n'
        << "\tNumarul de kilometri parcursi: " << no_km << '\n';
    os  << "\tCapacitate rezervor: " << tank_cap << " Litri\n"
        << "\tNivel combustibil: " << tank_lvl << " Litri\n"
        << "\tCapacitate baterie: " << bat_capacity << " Watts\n"
        << "\tNivel baterie: " << bat_lvl << "%\n"
        << "\tPretul de inchiriere: " << hire_price << " RON / zi\n"
        << "\tDisponibilitate: " << ((is_hired)? "Indisponibila momentan\n" : "Disponibila\n");

    os << "================== End Masina ==================\n";
}