#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include "headers/Masina.h"
#include "headers/Reprezentanta.h"
#include "headers/User.h"
#include "headers/Admin.h"

int main() {
    Masina m1{"PH 10 GDB","Renault", "Megane 4", "rosie", "motorina", 2019, 10000, 199.99};
    Masina m2{"B 456 CPP","Tesla", "Model 3", "cyan", "electrica", 2209, 1560, 399.99};
    Masina m3{"BV 89 HFY","Dacia", "Spring", "alb", "electrica", 2021, 500, 174.99};
    Masina m4{"VL 15 SDG","Toyota", "Corola", "argintie", "hibrid (motorina + electrica)", 2017, 89456, 174.99};
    Masina m5{"PH 34 GHO","VolksWagen", "Arteon", "albastru", "motorina", 2020, 5000, 249.99};
    Masina m6{"TR 67 GGO","VolksWagen", "Arteon", "galben", "benzina", 2018, 10000, 249.99};
    Masina m7{"B 24 FGS","Audi", "A5", "negru", "motorina", 2017, 25641, 299.99};
    Masina m8{"AG 45 DSG","Ford", "Mustang", "portocaliu", "motorina", 2019, 6545, 299.99};
    Masina m9{"IS 10 GDB","Renault", "Captur", "verde", "benzina", 2018, 7849, 250};
    Masina m10{"B 999 VLR","BMW", "Seria 3", "negru", "benzina", 2019, 3415, 350};

    Reprezentanta r1{{m1, m2, m3, m4, m5}, "Aleea Scolii, nr. 34, Bucuresti"};
    Reprezentanta r2{{m6, m10}, "Strada Nalbei, nr. 78, Ploiesti"};
    Reprezentanta r3{{}, "Strada Torcatori, nr. 63, Pitesti"};
    Reprezentanta r4{{m9, m7}, "Bulevardul Independentei, nr. 41, Brasov"};

    Admin a1{r1, "Admin1", "admin1@gmail.com", "admin1*admin_", "0742167985"};
    Admin a2{r2, "Admin2", "admin2@yahoo.com", "admin2__pass", "0794321658"};
    Admin a3{r3, "Admin3", "admin3@hotmail.com", "pass*!example__", "0796541789"};
    Admin a4{r4, "Admin4", "admin4@outlook.com", "asdfPOWEr!!123", "0794569871"};

    User u1{"User1", "user1@gmail.com", "password1", "16-06-2002", "5020616249775", "Popescu Ion Gheorghe", 19, 1456.25};
    User u2{"User2", "user2@gmail.com", "password2", "23-07-1989", "2890723694216", "Sandu Maria Ioana", 32, 699.99};
    User u3{"User3", "user3@gmail.com", "password3", "19-04-2000", "5000419251987", "Ionita Daniel-Andrei", 21, 30.85};

    std::cout << r1 << "\n\n" << r3 << '\n';
    std::cout << u1 << '\n' << u2 << '\n' << u3 << '\n';
    u1.hire(r1, m6);
    u1.hire(r1, m2);
    u2.hire(r2, m6);
    u3.hire(r3, m8);
    r3.add_car(m8);
    u3.hire(r3, m8);
    u3.load_account(10000);
    u3.hire(r3, m8);
    std::cout << u1 << '\n' << u2 << '\n' << u3 << '\n';
    u1.unhire();
    u2.unhire();
    u3.unhire();
    r2.delete_car(m1);
    r2.delete_car(m6);
    std::cout << r2 << '\n';
    std::cout << a4;

    return 0;
}
