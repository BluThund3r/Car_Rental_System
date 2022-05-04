//
// Created by bluth on 22/04/2022.
//

#include "../headers/M_Combustibil.h"
#include "../headers/negative_qtty.h"
#include <iostream>

M_Combustibil::M_Combustibil(const std::string &regPlate, const std::string &co, const std::string &model,
                             const std::string &color, const int &fabYear, const int &noKm, const double &hirePrice,
                             const double& tankCap, fuel_type ftype, const double& tankLvl , const bool &isHired) :
        Masina(regPlate, co, model, color,fabYear, noKm, hirePrice,isHired),
        tank_cap(tankCap),
        tank_lvl(tankLvl),
        ftype(ftype)
{}

M_Combustibil::M_Combustibil(const M_Combustibil& other): Masina(other),
        tank_cap(other.tank_cap),
        tank_lvl(other.tank_lvl),
        ftype(other.ftype)
{}

void M_Combustibil::charge(const double& qtty){
    if(qtty <= 0)
        throw negative_qtty();


    tank_lvl += qtty;
    if(tank_lvl > tank_cap)
        tank_lvl = tank_cap;
    std::cout << "Ati alimentat masina " << this->reg_plate << " pana la " << this->tank_lvl << " litri\n";
}


std::ostream& operator<<(std::ostream& os, const M_Combustibil& car){
    car.afis(os);
    return os;
}

void M_Combustibil::honk() const {
    std::cout << "Honk M_Combustibil\n";
}

void M_Combustibil::afis(std::ostream &os) const {
    os  << "========== Masina ==========\n"
        << "\tNumarul de inmatriculare: " << reg_plate <<'\n'
        << "\tMarca: " << co << '\n'
        << "\tModelul: " << model << '\n'
        << "\tCuloarea: " << color << '\n'
        << "\tMASINA PE COMBUSTIBIL\n"
        << "\tTipul combustibilului: ";
    switch(ftype) {
            case 0 : {std::cout << "Benzina\n"; break;}
            case 1 : {std::cout << "Motorina\n"; break;}
            case 2 : {std::cout << "GPL\n"; break;}
    }
    os  << "\tAnul fabricatiei: " << fab_year << '\n'
        << "\tNumarul de kilometri parcursi: " << no_km << '\n';
    os  << "\tPretul de inchiriere: " << hire_price << " RON / zi\n"
        << "\tCapacitate rezervor: " << tank_cap << " Litri\n"
        << "\tNivel combustibil: " << tank_lvl << " Litri\n"
        << "\tDisponibilitate: " << ((is_hired)? "Indisponibila momentan\n" : "Disponibila\n");

    os << "================== End Masina ==================\n";
}