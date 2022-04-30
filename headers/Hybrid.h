//
// Created by bluth on 22/04/2022.
//

#ifndef MAIN_CPP_HYBRID_H
#define MAIN_CPP_HYBRID_H

#include "M_Combustibil.h"
#include "Electrica.h"

class Hybrid:public M_Combustibil, public Electrica {

public:
    Hybrid(const std::string &reg_plate, const std::string &co, const std::string &model, const std::string &color,
           const int &fab_year, const int &no_km, const double &hire_price, const double &batCapacity, fuel_type ftype,
           const double &tankCap, const double &tankLvl = 0, const double &batLvl = 0, const bool &is_hired = false);

    Hybrid(const Hybrid&);

    void afis() override;

    void charge(const double&) override;

    [[nodiscard]] std::shared_ptr<Masina> clone() const override {
        return std::make_shared<Hybrid>(*this);
    }

    ~Hybrid() override = default;

    friend std::ostream& operator<<(std::ostream& os, const Hybrid& car);

    Hybrid& operator=(const Hybrid& other);

    friend void swap(Hybrid& h1, Hybrid& h2);

    void honk() const;
};


#endif //MAIN_CPP_HYBRID_H