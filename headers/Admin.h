//
// Created by bluth on 22/04/2022.
//

#ifndef MAIN_CPP_ADMIN_H
#define MAIN_CPP_ADMIN_H


#include "User.h"
#include "Reprezentanta.h"

class Admin: public User {
    Reprezentanta rep;
public:
    Admin(const std::string &username, const std::string &email, const std::string &bDay,
          const std::string &cnp, const std::string &name, const std::string &phone, const int &age,
          const Reprezentanta &rep);

    Admin(const Admin&);

    ~Admin() override = default;

    [[nodiscard]] std::shared_ptr<User> clone() const override {
        return std::make_shared<Admin>(*this);
    }

//    Admin& operator=(const Admin& other);
//
//    friend void swap(Admin&, Admin&);

    friend std::ostream& operator<<(std::ostream&, const Admin&);

    void say_something() const;

    void afis(std::ostream&) const override;
};


#endif //MAIN_CPP_ADMIN_H
