//
// Created by bluth on 13/04/2022.
//

#ifndef MAIN_CPP_REPREZENTANTA_H
#define MAIN_CPP_REPREZENTANTA_H

#include "Masina.h"
#include <vector>

class Reprezentanta{
    static int gen_id;
    std::vector<Masina> cars;
    std::string address;
    int id;

public:
    int get_id() const {return id;}
    void delete_car(const Masina&);
    void add_car(const Masina&);
    Reprezentanta(const std::vector<Masina>& , const std::string&);
    ~Reprezentanta();
    friend std::ostream& operator<<(std::ostream&, const Reprezentanta&);
    int find_car(const Masina&) const;
    bool is_index_hired(const int& pos) const {return cars[pos].get_hire_status();}
    void set_hire_status_index(const int& index, const bool& status) {cars[index].set_hire_status(status);};
};

#endif //MAIN_CPP_REPREZENTANTA_H
