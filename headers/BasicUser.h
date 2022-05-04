//
// Created by bluth on 22/04/2022.
//

#ifndef MAIN_CPP_BASICUSER_H
#define MAIN_CPP_BASICUSER_H

#include "User.h"
#include <memory>

class BasicUser: public User {
    std::shared_ptr<Masina> car;
    double bal;
public:
    BasicUser(const std::string &username, const std::string &email, const std::string &bDay,
              const std::string &cnp, const std::string &name, const std::string &phone, const int &age,
              const double& bal = 0, const std::shared_ptr<Masina> &car = nullptr);
    ~BasicUser() override = default;

    [[nodiscard]] std::shared_ptr<User> clone() const override {
        return std::make_shared<BasicUser>(*this);
    }

    BasicUser(const BasicUser&);

    BasicUser& operator=(const BasicUser& other);

    friend void swap(BasicUser& , BasicUser&);

    void load_account(const double& value){bal += value;}

    void unhire();

    void hire(Reprezentanta&, const std::shared_ptr<Masina>&);

    friend std::ostream& operator<<(std::ostream&, const BasicUser&);

    void say_something() const;

    void afis(std::ostream& os) const override;
};


#endif //MAIN_CPP_BASICUSER_H
