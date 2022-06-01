#include <iostream>
#include "headers/Reprezentanta.h"
#include "headers/Admin.h"
#include "headers/Electrica.h"
#include "headers/M_Combustibil.h"
#include "headers/Hybrid.h"
#include "headers/BasicUser.h"
#include "headers/not_unique_car.h"
#include "headers/not_unique_user.h"
#include "headers/negative_qtty.h"
#include "headers/not_found.h"
#include "headers/user_not_has_car.h"
#include "headers/null_username.h"
#include "headers/Factory.h"
#include "headers/FactoryElectrica.h"
#include "headers/FactoryCombustibil.h"
#include "headers/FactoryHybrid.h"
#include "headers/BasicUserBuilder.h"
#include "headers/BuilderAdmin.h"
#include "headers/IDgen.h"
#include "headers/empty_exception.h"

template <typename T>
T Max(const std::vector<T>& v) {
    if(v.empty())
        throw empty_exception();
    T max = v[0];
    for(auto& val : v)
        if(val > max)
            max = val;

    return max;
}

template <>
std::shared_ptr<Masina> Max(const std::vector<std::shared_ptr<Masina>>& v) {
    if(v.empty())
        throw empty_exception();
    auto max = v[0];
    for(auto& m : v)
        if(m->get_price() > max->get_price())
            max = m;

    return max;
}

template <>
Reprezentanta Max(const std::vector<Reprezentanta>& v) {
    if(v.empty())
        throw empty_exception();
    auto max = v[0];
    for(auto& m : v)
        if(m.getNoCars() > max.getNoCars())
            max = m;

    return max;
}

template <typename T>
T Min(const std::vector<T>& v) {
    if(v.empty())
        throw empty_exception();
    T min = v[0];
    for(auto& val : v)
        if(val < min)
            min = val;

    return min;
}

template <>
std::shared_ptr<Masina> Min(const std::vector<std::shared_ptr<Masina>>& v) {
    if(v.empty())
        throw empty_exception();
    auto min = v[0];
    for(auto& m : v)
        if(m->get_price() < min->get_price())
            min = m;

    return min;
}

template <>
Reprezentanta Min(const std::vector<Reprezentanta>& v) {
    if(v.empty())
        throw empty_exception();
    auto min = v[0];
    for(auto& m : v)
        if(m.getNoCars() < min.getNoCars())
            min = m;

    return min;
}

int main() {

    FactoryElectrica fe;
    FactoryCombustibil fc;
    std::shared_ptr<Factory> fh(new FactoryHybrid);
    std::shared_ptr<Masina> m1 = fc.createRenault();
    std::shared_ptr<Masina> m2 = fc.createAudi();
    std::shared_ptr<Masina> m3 = fc.createFord();
    std::shared_ptr<Masina> m4 = fc.createBMW();
    std::shared_ptr<Masina> m5 = fc.createVW();
    std::shared_ptr<Masina> m7 = fe.createDacia();
    std::shared_ptr<Masina> m8 = fe.createRenault();
    std::shared_ptr<Masina> m9 = fh->createToyota();
    std::shared_ptr<Masina> m10 = fh->createVW();
    Electrica e1{"B 456 CPP","Tesla", "Model 3", "cyan", 2019, 1560, 399.99, 50000};
    std::shared_ptr<Masina> m6 = std::make_shared<Electrica>(e1);
    std::vector<std::shared_ptr<Masina>> v = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10};
    std::cout << "Masina cu cel mai mare pret de inchiriere din intreaga aplicatie este: " << Max(v)->get_reg_plate() << '\n';
    std::cout << "Masina cu cel mai mic pret de inchiriere din intreaga aplicatie este: " << Min(v)->get_reg_plate() << '\n';

    try {
        Hybrid t1{"B 456 CPP","Tesla", "Model 3", "cyan", 2019, 1560, 399.99, 6000, Hybrid::motorina, 50};
    }
    catch(not_unique_car& err) {
        std::cout << err.what() << '\n';
    }

    Reprezentanta r1{"Aleea Scolii, nr. 34, Bucuresti"};
    Reprezentanta r2{"Strada Nalbei, nr. 78, Ploiesti"};
    Reprezentanta r3{"Strada Torcatori, nr. 63, Pitesti"};
    Reprezentanta r4{"Bulevardul Independentei, nr. 41, Brasov"};


    r1.add_car(m1);
    r1.add_car(m2);
    r1.add_car(m3);
    r2.add_car(m4);
    r2.add_car(m6);
    r3.add_car(m5);
    r3.add_car(m7);
    r3.add_car(m8);
    r3.add_car(m9);
    r4.add_car(m10);

    std::vector<Reprezentanta> rep = {r1, r2, r3, r4};
    std::cout << "Reprezentanta cu cele mai multe masini din intreaga aplicatie este Reprezentanta #" << Max(rep).get_id() << '\n';
    std::cout << "Reprezentanta cu cele mai putine masini din intreaga aplicatie este Reprezentanta #" << Min(rep).get_id() << '\n';

    Masina *tempMasina = new Hybrid{"DJ 10 APB", "VolksWagen", "Arteon", "galben", 2018, 10000, 249.99, 10000, M_Combustibil::benzina, 65};
    tempMasina->honk();
    if(auto* tempMasina2 = dynamic_cast<Electrica *>(tempMasina)) {
        std::cout << "Conversia a reusit!\n";
        tempMasina2->honk();
    }
    else
        std::cout << "Eroare... Conversia nu a reusit!\n";

    if(auto* tempMasina2 = dynamic_cast<M_Combustibil *>(tempMasina)) {
        std::cout << "Conversia a reusit!\n";
        tempMasina2->honk();
    }
    else
        std::cout << "Eroare... Conversia nu a reusit!\n";

    if(auto* tempMasina2 = dynamic_cast<Hybrid *>(tempMasina)) {
        std::cout << "Conversia a reusit!\n";
        tempMasina2->honk();
    }
    else
        std::cout << "Eroare... Conversia nu a reusit!\n";

    delete tempMasina;

    BasicUser u3{"User3", "user2@gmail.com", "19-04-2000", "5000419251987", "Ionita Daniel-Andrei", "0715679451", 22, 30.85};
    [[maybe_unused]] User& tempUser = u3;

    try {
        auto& tempUser2 = dynamic_cast<BasicUser&>(u3);
        std::cout << "Conversia a reusit!\n";
        tempUser2.say_something();

        auto& tempUser3 = dynamic_cast<Admin&>(u3);
        std::cout << "Conversia a reusit!\n";
        tempUser3.say_something();
    }
    catch(std::bad_cast&) {
        std::cout << "Eroare... Conversia nu a reusit!\n";
    }

    BuilderAdmin ba;
    BasicUserBuilder bu;

    Admin a1 = ba.username("Admin1").bDay("16-06-1990").name("Popescu Marinescu").phone("0716485134").build();
    Admin a2 = ba.email("admin2@yahoo.com").name("Ionescu Cristina").age(21).username("Admin2").rep(r2).build();
    Admin a3 = ba.phone("0796541789").username("Admin3").cnp("1467894516486").bDay("13-03-1989").rep(r3).build();
    Admin a4 = ba.age(35).phone("0794569871").rep(r4).bDay("04-01-1987").name("Olteanu Mihai").email("admin4@outlook.com").username("Admin4").build();

    BasicUser u1 = bu.username("User1").age(32).name("Sandu Maria-Ioana").bDay("23-07-1989").bal(700).build();
    BasicUser u2 = bu.age(22).bal(39).name("Ionita Daniel-Andrei").cnp("5000419251987").bDay("19-04-2000").username("User2").email("user2@gmail.com").build();

    try {
        BasicUser b5 = bu.bDay("15-08-2002").phone("0754925647").car(m1).build();
        BasicUser u4{"User1", "user4@gmail.com", "19-04-2000", "5000419251987", "Ionita Daniel-Andrei", "0715679451", 22, 30.85};
        Admin a5{"Admin3", "admin5@hotmail.com", "13-03-1989", "1467894516486", "Stanciu Stan","0796541789", 33,r3};
    }
    catch(not_unique_user& err) {
        std::cout << err.what() << '\n';
    }
    catch(null_username& err) {
        std::cout << err.what() << '\n';
    }

    std::cout <<'\n' <<  r1 << "\n" << r3 << '\n';
    std::cout << u1 << '\n' << u2 << '\n';

    try {
        u1.hire(r1, m6);
        u1.hire(r1, m2);
        u2.hire(r2, m6);
        u2.hire(r3, m8);
        u2.load_account(10000);
        u2.hire(r3, m8);
    }
    catch(not_found& err) {
        std::cout << err.what() << '\n';
    }

    u1.hire(r1, m2);
    u2.load_account(1000);
    u2.hire(r3, m7);

    try {
        u1.chargeCar(100000);
        u2.chargeCar(100000);
        u2.chargeCar(-100);
    }
    catch(user_not_has_car& err) {
        std::cout << err.what() << '\n';
    }
    catch(negative_qtty& err){
        std::cout << err.what() << "\nVa rugam incercati din nou, cu o cantitate pozitiva\n";
    }

    std::cout << '\n' << u1 << '\n' << u2 << '\n';
    u1.unhire();
    u2.unhire();
    try {
        std::string tempStr = r2.delete_car(m1)->get_reg_plate();
        std::cout << "Masina " << tempStr << " a fost stearsa de la Reprezentanta 2\n";
    }
    catch(not_found& err) {
        std::cout << err.what() << '\n';
    }

    std::cout << "Masina " << r2.delete_car(m6)->get_reg_plate() << " a fost stearsa de la Reprezentanta 2\n";
    std::cout << '\n' << r2 << '\n';
    std::cout << a4;

    return 0;
}