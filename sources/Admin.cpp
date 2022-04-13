//
// Created by bluth on 13/04/2022.
//

#include "../headers/Admin.h"
#include <iostream>

Admin::~Admin(){
    std::cout << "Contul admin-ului cu username-ul " << username << " a fost sters din aplicatie!\n";
}

Admin::Admin(const Reprezentanta& rep, const std::string& username, const std::string& email, const std::string& pass, const std::string& nr_telefon):
        rep(rep),
        pass(pass),
        username(username),
        email(email),
        nr_telefon(nr_telefon){
    std::cout << "Contul admin-ului cu username-ul " << username << " a fost creat.\n";
}

std::ostream& operator<<(std::ostream& os, const Admin& admin){
    os  << "========== Admin ==========\n"
        << "\tUsername: " << admin.username << '\n'
        << "\tEmail: " << admin.email << '\n'
        << "\tParola: " << "[CRYPTED]" << '\n'
        << "\tNumar de telefon: " << admin.nr_telefon << '\n'
        << "Reprezentanta: \n\n" << admin.rep;

    os << "================== End Admin ==================\n";
    return os;
}