//
// Created by bluth on 22/04/2022.
//

#include <iostream>
#include "../headers/Admin.h"

Admin::Admin(const std::string &username, const std::string &email, const std::string &bDay,
             const std::string &cnp, const std::string &name, const std::string &phone, const int &age,
             const Reprezentanta &rep) : User(username, email, bDay, cnp, name, phone, age), rep(rep) {}

Admin::Admin(const Admin& other): User(other), rep(other.rep){}

Admin& Admin::operator=(const Admin& other) {
    auto copy{other};
    swap(copy, *this);
    return *this;
}

void swap(Admin& u1, Admin& u2) {
    swap((User&)u1, (User&)u2);
    using std::swap;
    swap(u1.rep, u2.rep);
}

std::ostream& operator<<(std::ostream& os, const Admin& user) {
    user.afis(os);
    return os;
}

void Admin::say_something() const {
    std::cout << "Sunt un Admin\n";
}

void Admin::afis(std::ostream &os) const {
    os  << "========== Admin ==========\n"
        << "\tUsername: " << username << '\n'
        << "\tEmail: " << email << '\n'
        << "\tData nasterii: " << b_day << '\n'
        << "\tCNP: " << cnp << '\n'
        << "\tNume: " << name << '\n'
        << "\tNumar de telefon: " << phone << '\n'
        << "\tVarsta: " << age << '\n';
    if(rep.get_id())
        os << "\tAdmin-ul raspunde de Reprezentanta #" << rep.get_id() << '\n';
    else
        os << "\tAdmin-ul nu raspunde de nici o Reprezentanta\n";
    os << "================== End Admin ==================\n";
}

void Admin::clear() {
    User::clear();
    Reprezentanta r{};
    rep = r;
}