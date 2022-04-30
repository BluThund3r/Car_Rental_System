//
// Created by bluth on 13/04/2022.
//

#ifndef MAIN_CPP_REPREZENTANTA_H
#define MAIN_CPP_REPREZENTANTA_H

#include "Masina.h"
#include <vector>
#include <memory>

class Reprezentanta{
    static int gen_id;
    std::vector<std::shared_ptr<Masina>> cars;
    std::string address;
    int id;

public:
    [[nodiscard]] int get_id() const {return id;}

    const std::shared_ptr<Masina>& delete_car(const std::shared_ptr<Masina>&);

    void add_car(const std::shared_ptr<Masina>&);

    Reprezentanta(const std::vector<std::shared_ptr<Masina>>& , const std::string&);

    ~Reprezentanta() = default;

    Reprezentanta(const Reprezentanta& other);

    friend std::ostream& operator<<(std::ostream&, const Reprezentanta&);

    friend void swap(Reprezentanta& r1, Reprezentanta& r2);

    Reprezentanta& operator=(const Reprezentanta&);

    [[nodiscard]] int find_car(const std::shared_ptr<Masina> &) const;

    [[nodiscard]] bool is_index_hired(const int& pos) const {return cars[pos]->get_hire_status();}

    void set_hire_status_index(const int& index, const bool& status) {cars[index]->set_hire_status(status);};
};

#endif //MAIN_CPP_REPREZENTANTA_H
