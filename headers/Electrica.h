//
// Created by bluth on 17/04/2022.
//

#ifndef MAIN_CPP_ELECTRICA_H
#define MAIN_CPP_ELECTRICA_H


#include "Masina.h"

class Electrica: virtual public Masina {
protected:
    double bat_capacity, bat_lvl;

public:
    Electrica(const std::string &regPlate, const std::string &co, const std::string &model, const std::string &color,
              const int &fabYear, const int &noKm, const double &hirePrice, const double &batCapacity,
              const double &batLvl = 0, const bool &isHired = false);

    Electrica(const Electrica &other);

    ~Electrica() override = default;

    void charge(const double& power) override;

    [[nodiscard]] double get_bat_lvl() const {return bat_lvl;}

    friend std::ostream& operator<<(std::ostream& os, const Electrica& car);

    void afis() override;

    [[maybe_unused]] void honk() const;

    [[nodiscard]] std::shared_ptr<Masina> clone() const override {
        return std::make_shared<Electrica>(*this);
    }
};


#endif //MAIN_CPP_ELECTRICA_H
