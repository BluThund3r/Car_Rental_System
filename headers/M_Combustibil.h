//
// Created by bluth on 22/04/2022.
//

#ifndef MAIN_CPP_M_COMBUSTIBIL_H
#define MAIN_CPP_M_COMBUSTIBIL_H


#include "Masina.h"

class M_Combustibil: virtual public Masina{
public:
    enum fuel_type{benzina, motorina, gpl};

protected:
    double tank_cap, tank_lvl;
    fuel_type ftype;

public:
    M_Combustibil(const std::string &regPlate, const std::string &co, const std::string &model,
                  const std::string &color, const int &fabYear, const int &noKm, const double &hirePrice,
                  const double& tankCap, fuel_type ftype, const double& tankLvl = 0, const bool &isHired = false );

    M_Combustibil(const M_Combustibil& other);

    ~M_Combustibil() override = default;

    void charge(const double& qtty) override;

    friend std::ostream& operator<<(std::ostream& os, const M_Combustibil& car);

    void afis() override;

    [[nodiscard]] std::shared_ptr<Masina> clone() const override {
        return std::make_shared<M_Combustibil>(*this);
    }

    void honk() const;
};


#endif //MAIN_CPP_M_COMBUSTIBIL_H
