//
// Created by bluth on 13/04/2022.
//
#include "../headers/User.h"
#include <iostream>

void User::unhire(){
    if(!hired_car){
        std::cout << "Utilizatorul nu are nici o masina inchiriata!\n";
        return;
    }

    hired_car->set_hire_status(false);
    std::cout << "Utilizatorul " << username << " a predat masina " << hired_car->get_reg_plate() << "!\n";
    hired_car = std::nullopt;
}

void User::hire(Reprezentanta& r, const Masina& m){
    if(hired_car){
        std::cout << "Utilizatorul " << this->username << " nu poate inchiria doua masini simultan!\n";
        return;
    }

    if(bal < m.get_price()){
        std::cout << "Utilizatorul " << this->username << " nu are bani suficienti pentru a inchiria masina!\n";
        return;
    }

    int pos = r.find_car(m);
    if(pos == -1){
        std::cout << "Masina cu numarul de inmatriculare " << m.get_reg_plate() <<" nu se afla la aceasta reprezentanta!\n";
        return;
    }

    if(r.is_index_hired(pos)){
        std::cout << "Masina cu numarul de inmatriculare " << m.get_reg_plate() << " este deja inchiriata!\n";
        return;
    }

    hired_car = m;
    bal -= m.get_price();
    r.set_hire_status_index(pos, true);
    std::cout << "Utilizatorul " << this->username << " a inchiriat masina " << m.get_reg_plate() << " de la reprezentanta " << r.get_id() << "!\n";

}

User::User(const std::string& username, const std::string& email, const std::string& pass, const std::string& b_day, const std::string& cnp, const std::string& name, const int& age, const double& bal, const std::optional<Masina>& hired_car):
        username(username), email(email), pass(pass), b_day(b_day), cnp(cnp), name(name), age(age), bal(bal), hired_car(hired_car){
    std::cout << "A fost creat contul utilizatorului cu username-ul " << username << ".\n";
}

User::~User(){
    std::cout << "Contul utilizatorului cu username-ul " << username << " a fost sters din aplicatie!\n";
}

std::ostream& operator<<(std::ostream& os, const User& user){
    os  << "========== Utilizator ==========\n"
        << "\tUsername: " << user.username << '\n'
        << "\tEmail: " << user.email << '\n'
        << "\tParola: " << "[CRYPTED]" << '\n'
        << "\tData nasterii: " << user.b_day << '\n'
        << "\tCNP: " << user.cnp << '\n'
        << "\tNume: " << user.name << '\n'
        << "\tVarsta: " << user.age << '\n'
        << "\tSuma de bani in cont: " << user.bal << " RON" << '\n';
    if(user.hired_car)
        os << "Utilizatorul are inchiriata masina cu numarul de inmatriculare " << user.hired_car->get_reg_plate() << ".\n";
    else
        os << "Utilizatorul NU are nici o masina inchiriata in momentul de fata.\n";

    os << "================== End User ==================\n";
    return os;
}
