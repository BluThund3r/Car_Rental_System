//
// Created by bluth on 13/04/2022.
//

#ifndef MAIN_CPP_MASINA_H
#define MAIN_CPP_MASINA_H

#include <string>
#include <unordered_set>
#include <memory>

class Masina{
protected:
    static std::unordered_set<std::string> regPlates;
    std::string reg_plate, co, model, color;
    int fab_year, no_km;
    double hire_price;
    bool is_hired;

public:
    Masina(const std::string& reg_plate, const std::string& co, const std::string& model, const std::string& color, const int& fab_year, const int& no_km, const double& hire_price, const bool& is_hired = false);

    Masina(const Masina& other);

    Masina& operator=(const Masina& other);

    bool operator==(const Masina&) const;

    virtual ~Masina() = 0;

    [[nodiscard]] std::string get_reg_plate() const {return reg_plate;}

    friend std::ostream& operator<<(std::ostream& os, const Masina& car);

    [[nodiscard]] bool get_hire_status() const {return is_hired;}

    [[nodiscard]] double get_price() const {return hire_price;}

    void set_hire_status(const bool& status){is_hired = status;}

    virtual void charge(const double& power);

    virtual void afis() = 0;

    [[nodiscard]] virtual std::shared_ptr<Masina> clone() const = 0;

    [[maybe_unused]] void honk() const;

    //adds the reg_plate to the regPlates set or throws an error if already added
    static void addRegPlate(const std::string& reg_plate);
};

#endif //MAIN_CPP_MASINA_H
