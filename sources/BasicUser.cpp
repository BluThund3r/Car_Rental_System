//
// Created by bluth on 22/04/2022.
//

#include <iostream>
#include "../headers/BasicUser.h"

BasicUser::BasicUser(const std::string &username, const std::string &email,
                     const std::string &bDay, const std::string &cnp, const std::string &name, const std::string &phone,
                     const int &age, const double& bal, const std::shared_ptr<Masina> &car) :
                     User(username, email, bDay, cnp, name, phone, age),
                     car(car),
                     bal(bal)
                     {}

BasicUser::BasicUser(const BasicUser& other):
        User(other),
        car(other.car->clone()),
        bal(other.bal){}

//BasicUser& BasicUser::operator=(const BasicUser& other) {
//    auto copy{other};
//    swap(copy, *this);
//    return *this;
//}
//
//void swap(BasicUser& u1, BasicUser& u2) {
//    using std::swap;
//    swap(u1.username, u2.username);
//    swap(u1.name, u2.name);
//    swap(u1.email, u2.email);
//    swap(u1.b_day, u2.b_day);
//    swap(u1.cnp, u2.cnp);
//    swap(u1.phone, u2.phone);
//    swap(u1.age, u2.age);
//    swap(u1.bal, u2.bal);
//    swap(u1.car, u2.car);
//}

void BasicUser::unhire(){
    if(!car){
        std::cout << "Utilizatorul nu are nici o masina inchiriata!\n";
        return;
    }

    car->set_hire_status(false);
    std::cout << "Utilizatorul " << username << " a predat masina " << car->get_reg_plate() << "!\n";
    car = nullptr;
}

void BasicUser::hire(Reprezentanta& r, const std::shared_ptr<Masina>& m){
    if(car){
        std::cout << "Utilizatorul " << this->username << " nu poate inchiria doua masini simultan!\n";
        return;
    }

    if(bal < m->get_price()){
        std::cout << "Utilizatorul " << this->username << " nu are bani suficienti pentru a inchiria masina!\n";
        return;
    }

    int pos = r.find_car(m); // arunca exceptie daca nu e masina in r

    if(r.is_index_hired(pos)){
        std::cout << "Masina cu numarul de inmatriculare " << m->get_reg_plate() << " este deja inchiriata!\n";
        return;
    }

    car = m->clone();
    bal -= car->get_price();
    r.set_hire_status_index(pos, true);
    std::cout << "Utilizatorul " << this->username << " a inchiriat masina " << m->get_reg_plate() << " de la reprezentanta " << r.get_id() << "!\n";

}

std::ostream& operator<<(std::ostream& os, const BasicUser& user) {
    user.afis(os);
    return os;
}

void BasicUser::say_something() const {
    std::cout << "Sunt un BasicUser!\n";
}

void BasicUser::afis(std::ostream &os) const {
    os  << "========== Basic User ==========\n"
        << "\tUsername: " << username << '\n'
        << "\tEmail: " << email << '\n'
        << "\tData nasterii: " << b_day << '\n'
        << "\tCNP: " << cnp << '\n'
        << "\tNume: " << name << '\n'
        << "\tNumar de telefon: " << phone << '\n'
        << "\tVarsta: " << age << '\n'
        << "\tSuma de bani din cont: " << bal << '\n';
     if(!car)
         os << "\tUtilizatorul nu are nici o masina inchiriata\n";
     else
         os << "\tUtilizatorul are inchiriata masina: " << car->get_reg_plate() << '\n';

     os << "================== End Basic User ==================\n";
}
