//
// Created by bluth on 13/04/2022.
//

#ifndef MAIN_CPP_MASINA_H
#define MAIN_CPP_MASINA_H

#include <string>

class Masina{
    int fab_year, no_km;
    std::string reg_plate, fuel, color, model, co;
    bool is_hired;
    double hire_price;

public:
    Masina(const std::string& reg_plate, const std::string& co, const std::string& model, const std::string& color, const std::string& fuel, const int& fab_year, const int& no_km, const double& hire_price, const bool& is_hired = false);
    Masina(const Masina& other);
    Masina& operator=(const Masina& other);
    bool operator==(const Masina&) const;
    ~Masina();
    std::string get_reg_plate() const {return reg_plate;}
    friend std::ostream& operator<<(std::ostream& os, const Masina& car);
    bool get_hire_status() const {return is_hired;}
    double get_price() const {return hire_price;}
    void set_hire_status(const bool& status){is_hired = status;}
};

#endif //MAIN_CPP_MASINA_H
