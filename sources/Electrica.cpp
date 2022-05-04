//
// Created by bluth on 17/04/2022.
//

#include "../headers/Electrica.h"
#include "../headers/negative_qtty.h"
#include <iostream>



Electrica::Electrica(const Electrica &other): Masina(other), bat_capacity(other.bat_capacity), bat_lvl(other.bat_lvl) {}

Electrica::Electrica(const std::string &regPlate, const std::string &co, const std::string &model,
                     const std::string &color, const int &fabYear, const int &noKm, const double &hirePrice,
                     const double &batCapacity, const double &batLvl, const bool &isHired) : Masina(regPlate, co, model, color,
                                                                                      fabYear, noKm, hirePrice,
                                                                                      isHired),
                                                                               bat_capacity(batCapacity),
                                                                               bat_lvl(batLvl) {}

void Electrica::charge(const double& power){
    if(power <= 0)
        throw negative_qtty();

    bat_lvl += power * 100 / bat_capacity;
    if(bat_lvl > 100)
        bat_lvl = 100;
    std::cout << "Ati incarcat masina " << this->reg_plate << " pana la " << this->bat_lvl << "%\n";
}

std::ostream& operator<<(std::ostream& os, const Electrica& car){
    car.afis(os);
    return os;
}

[[maybe_unused]] void Electrica::honk() const {
    std::cout << "Honk Electrica\n";
}

void Electrica::afis(std::ostream& os) const {
    os  << "========== Masina ==========\n"
        << "\tNumarul de inmatriculare: " << reg_plate <<'\n'
        << "\tMarca: " << co << '\n'
        << "\tModelul: " << model << '\n'
        << "\tCuloarea: " << color << '\n'
        << "\tMASINA ELECTRICA\n"
        << "\tAnul fabricatiei: " << fab_year << '\n'
        << "\tNumarul de kilometri parcursi: " << no_km << '\n';
    os  << "\tCapacitate baterie: " << bat_capacity << " Watts\n"
        << "\tNivel baterie: " << bat_lvl << "%\n"
        << "\tPretul de inchiriere: " << hire_price << " RON / zi\n"
        << "\tDisponibilitate: " << ((is_hired)? "Indisponibila momentan\n" : "Disponibila\n");

    os << "================== End Masina ==================\n";
}




