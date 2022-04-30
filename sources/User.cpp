//
// Created by bluth on 13/04/2022.
//
#include "../headers/User.h"
#include "../headers/not_unique_user.h"
#include <iostream>

std::unordered_set<std::string> User::uNames;

User::User(const std::string& username, const std::string& email, const std::string& pass, const std::string& b_day, const std::string& cnp, const std::string& name, const std::string& phone, const int& age):
        username(username),
        email(email),
        pass(pass),
        b_day(b_day),
        cnp(cnp),
        name(name),
        phone(phone),
        age(age)
{
    addUsername(username);
}

std::ostream& operator<<(std::ostream& os, const User& user){
    os  << "========== User ==========\n"
        << "\tUsername: " << user.username << '\n'
        << "\tEmail: " << user.email << '\n'
        << "\tParola: " << "[CRYPTED]" << '\n'
        << "\tData nasterii: " << user.b_day << '\n'
        << "\tCNP: " << user.cnp << '\n'
        << "\tNume: " << user.name << '\n'
        << "\tNumar de telefon: " << user.phone << '\n'
        << "\tVarsta: " << user.age << '\n'
        << "================== End User ==================\n";
    return os;
}

User::~User() {}

void User::addUsername(const std::string &username) {
    if(uNames.find(username) != uNames.end())
        throw not_unique_user();
    uNames.insert(username);
}

void User::say_something() const {
    std::cout << "Sunt un User abstract!\n";
}