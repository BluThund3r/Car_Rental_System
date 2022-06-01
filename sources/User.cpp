//
// Created by bluth on 13/04/2022.
//
#include "../headers/User.h"
#include "../headers/not_unique_user.h"
#include <iostream>

std::unordered_set<std::string> User::uNames;

User::User():
    username("*gol*"), email("*gol*"), b_day("*gol*"), cnp("*gol*"), name("*gol*"),
    phone("*gol*"), age(0) {}

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

bool User::existsUsername(const std::string &username) {
    return (uNames.find(username) != uNames.end());
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

void User::clear() {
    username = "";
    email = "";
    b_day = "";
    cnp = "";
    name = "";
    phone = "";
    age = 0;
}

void swap(User& u1, User& u2) {
    using std::swap;
    swap(u1.username, u2.username);
    swap(u1.name, u2.name);
    swap(u1.email, u2.email);
    swap(u1.b_day, u2.b_day);
    swap(u1.cnp, u2.cnp);
    swap(u1.phone, u2.phone);
    swap(u1.age, u2.age);
}