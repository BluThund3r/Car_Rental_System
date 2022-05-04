//
// Created by bluth on 13/04/2022.
//
#include "../headers/User.h"
#include "../headers/not_unique_user.h"
#include <iostream>

std::unordered_set<std::string> User::uNames;

User::User(const std::string& username, const std::string& email, const std::string& b_day, const std::string& cnp,
           const std::string& name, const std::string& phone, const int& age):
        username(username),
        email(email),
        b_day(b_day),
        cnp(cnp),
        name(name),
        phone(phone),
        age(age)
{
    addUsername();
}

std::ostream& operator<<(std::ostream& os, const User& user){
    user.afis(os);
    return os;
}

User::~User() {}

void User::addUsername() {
    if(uNames.find(username) != uNames.end())
        throw not_unique_user();
    uNames.insert(username);
}

void User::say_something() const {
    std::cout << "Sunt un User abstract!\n";
}

void User::afis(std::ostream& os) const {
     os  << "========== User ==========\n"
        << "\tUsername: " << username << '\n'
        << "\tEmail: " << email << '\n'
        << "\tData nasterii: " << b_day << '\n'
        << "\tCNP: " << cnp << '\n'
        << "\tNume: " << name << '\n'
        << "\tNumar de telefon: " << phone << '\n'
        << "\tVarsta: " << age << '\n'
        << "================== End User ==================\n";
}