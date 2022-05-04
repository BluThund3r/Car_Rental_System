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

int main() {
    M_Combustibil c1{"PH 10 GDB", "Renault", "Megane 4", "rosie", 2019, 10000, 199.99, 60, M_Combustibil::motorina};
    M_Combustibil c2{"B 24 FGS","Audi", "A5", "negru", 2017, 25641, 299.99, 60, M_Combustibil::benzina};
    M_Combustibil c3{"AG 45 DSG","Ford", "Mustang", "portocaliu", 2019, 6545, 299.99, 65, M_Combustibil::benzina};
    M_Combustibil c4{"B 999 VLR","BMW", "Seria 3", "negru", 2015, 3415, 350, 60, M_Combustibil::gpl};
    M_Combustibil c5{"PH 34 GHO","VolksWagen", "Arteon", "albastru", 2020, 5000, 249.99, 68, M_Combustibil::motorina};
    Electrica e1{"B 456 CPP","Tesla", "Model 3", "cyan", 2019, 1560, 399.99, 50000};
    Electrica e2{"BV 89 HFY","Dacia", "Spring", "alb", 2021, 500, 174.99, 27000};
    Electrica e3{"IS 10 GDB","Renault", "Megane", "verde", 2022, 7849, 250, 40000};
    Hybrid h1{"VL 15 SDG","Toyota", "Corola", "argintie", 2017, 89456, 174.99, 6500, M_Combustibil::motorina, 50 };
    Hybrid h2{"TR 67 GGO","VolksWagen", "Arteon", "galben", 2018, 10000, 249.99, 10000, M_Combustibil::benzina, 65};
    try {
        Electrica t1{"PH 10 GDB","Tesla", "Model 3", "cyan", 2019, 1560, 399.99, 50000};
    }
    catch(not_unique_car& err) {
        std::cout << err.what() << '\n';
    }

    Reprezentanta r1{{}, "Aleea Scolii, nr. 34, Bucuresti"};
    Reprezentanta r2{{}, "Strada Nalbei, nr. 78, Ploiesti"};
    Reprezentanta r3{{}, "Strada Torcatori, nr. 63, Pitesti"};
    Reprezentanta r4{{}, "Bulevardul Independentei, nr. 41, Brasov"};

    std::shared_ptr<Masina> m1 = std::make_shared<M_Combustibil>(c1);
    std::shared_ptr<Masina> m2 = std::make_shared<M_Combustibil>(c2);
    std::shared_ptr<Masina> m3 = std::make_shared<M_Combustibil>(c3);
    std::shared_ptr<Masina> m4 = std::make_shared<M_Combustibil>(c4);
    std::shared_ptr<Masina> m5 = std::make_shared<M_Combustibil>(c5);
    std::shared_ptr<Masina> m6 = std::make_shared<Electrica>(e1);
    std::shared_ptr<Masina> m7 = std::make_shared<Electrica>(e2);
    std::shared_ptr<Masina> m8 = std::make_shared<Electrica>(e3);
    std::shared_ptr<Masina> m9 = std::make_shared<Hybrid>(h1);
    std::shared_ptr<Masina> m10 = std::make_shared<Hybrid>(h2);

    r1.add_car(m1);
    r1.add_car(m2);
    r1.add_car(m3);
    r2.add_car(m4);
    r2.add_car(m6);
    r3.add_car(m5);
    r3.add_car(m7);
    r3.add_car(m8);
    r4.add_car(m9);
    r4.add_car(m10);

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

    Admin a1{"Admin1", "admin1@gmail.com", "16-06-1990", "5054654164894", "Popescu Marinescu", "0716485134", 31, r1};
    Admin a2{"Admin2", "admin2@yahoo.com", "25-09-2000", "6456154948431", "Ionescu Cristina", "0794321658", 21, r2};
    Admin a3{"Admin3", "admin3@hotmail.com", "13-03-1989", "1467894516486", "Stanciu Stan","0796541789", 33,r3};
    Admin a4{"Admin4", "admin4@outlook.com", "04-01-1987", "1894632158492", "Olteanu Mihai","0794569871", 35,r4};

    BasicUser u1{"User1", "user1@gmail.com", "23-07-1989", "2890723694216", "Sandu Maria Ioana", "0745164861", 32, 699.99};
    BasicUser u2{"User2", "user2@gmail.com", "19-04-2000", "5000419251987", "Ionita Daniel-Andrei", "0715679451", 22, 30.85};

    try {
        BasicUser u4{"User1", "user4@gmail.com", "19-04-2000", "5000419251987", "Ionita Daniel-Andrei", "0715679451", 22, 30.85};
        Admin a5{"Admin3", "admin5@hotmail.com", "13-03-1989", "1467894516486", "Stanciu Stan","0796541789", 33,r3};
    }
    catch(not_unique_user& err) {
        std::cout << err.what() << '\n';
    }

    std::cout <<'\n' <<  r1 << "\n" << r3 << '\n';
    std::cout << u1 << '\n' << u2 << '\n';

    try {
        m1->charge(100000);
        m6->charge(100000);
        m3->charge(-100);
    }
    catch(negative_qtty& err){
        std::cout << err.what() << "\nVa rugam incercati din nou, cu o cantitate pozitiva\n";
    }

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