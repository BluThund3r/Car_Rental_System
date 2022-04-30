//
// Created by bluth on 22/04/2022.
//

#include <iostream>
#include "../headers/Admin.h"

Admin::Admin(const std::string &username, const std::string &email, const std::string &pass, const std::string &bDay,
             const std::string &cnp, const std::string &name, const std::string &phone, const int &age,
             const Reprezentanta &r) : User(username, email, pass, bDay, cnp, name, phone, age), r(r) {}

Admin::Admin(const Admin& other): User(other), r(other.r){}

Admin& Admin::operator=(const Admin& other) {
    auto copy{other};
    swap(copy, *this);
    return *this;
}

void swap(Admin& u1, Admin& u2) {
    using std::swap;
    swap(u1.username, u2.username);
    swap(u1.name, u2.name);
    swap(u1.email, u2.email);
    swap(u1.pass, u2.pass);
    swap(u1.b_day, u2.b_day);
    swap(u1.cnp, u2.cnp);
    swap(u1.phone, u2.phone);
    swap(u1.age, u2.age);
    swap(u1.r, u2.r);
}

std::ostream& operator<<(std::ostream& os, const Admin& user) {
     os  << "========== Admin ==========\n"
        << "\tUsername: " << user.username << '\n'
        << "\tEmail: " << user.email << '\n'
        << "\tParola: " << "[CRYPTED]" << '\n'
        << "\tData nasterii: " << user.b_day << '\n'
        << "\tCNP: " << user.cnp << '\n'
        << "\tNume: " << user.name << '\n'
        << "\tNumar de telefon: " << user.phone << '\n'
        << "\tVarsta: " << user.age << '\n'
        << "\tAdmin-ul raspunde de Reprezentanta #" << user.r.get_id() << '\n'
        << "================== End Admin ==================\n";
    return os;
}

void Admin::say_something() const {
    std::cout << "Sunt un Admin\n";
}