//
// Created by bluth on 13/04/2022.
//

#ifndef MAIN_CPP_USER_H
#define MAIN_CPP_USER_H
#include <unordered_set>
#include "Masina.h"
#include "Reprezentanta.h"

class User{
    void addUsername();

protected:
    static std::unordered_set<std::string> uNames;
    std::string username, email, b_day, cnp, name, phone;
    int age;


public:
    User(const std::string& username, const std::string& email, const std::string& b_day,
         const std::string& cnp, const std::string& name,
         const std::string& phone, const int& age);

    virtual ~User() = 0;

    friend std::ostream& operator<<(std::ostream& os, const User& user);

    [[nodiscard]] int getAge() const {return this->age;}

    [[nodiscard]] virtual std::shared_ptr<User> clone() const = 0;

    void say_something() const;

    virtual void afis(std::ostream& os) const = 0;

};


#endif //MAIN_CPP_USER_H
