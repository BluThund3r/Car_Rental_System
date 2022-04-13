#include <iostream>
#include <string>
#include <vector>
#include <optional>


class Masina{
    int fab_year, no_km;
    std::string reg_plate, fuel, color, model, co;
    bool is_hired;
    double hire_price;

public:
    Masina(const std::string& reg_plate, const std::string& co, const std::string& model, const std::string& color, const std::string& fuel, int fab_year, int no_km, double hire_price, bool is_hired);
    Masina(const Masina& other);
    Masina& operator=(const Masina& other);
    bool operator==(const Masina&) const;
    ~Masina();
    std::string get_reg_plate() const {return reg_plate;}
    friend std::ostream& operator<<(std::ostream& os, const Masina& car);
    bool get_hire_status() const {return is_hired;}
    double get_price() const {return hire_price;}
    void set_hire_status(bool status){is_hired = status;}
};

Masina::Masina(const std::string& reg_plate, const std::string& co, const std::string& model, const std::string& color, const std::string& fuel, int fab_year, int no_km, double hire_price, bool is_hired = false):
        fab_year(fab_year),
        no_km(no_km),
        reg_plate(reg_plate),
        fuel(fuel),
        color(color),
        model(model),
        co(co),
        is_hired(is_hired),
        hire_price(hire_price)
{
    std::cout << "Masina cu numarul de inmatriculare " << reg_plate << " a fost adaugata in aplicatie.\n";
}

Masina::Masina(const Masina& other):
        fab_year(other.fab_year),
        no_km(other.no_km),
        reg_plate(other.reg_plate),
        fuel(other.fuel),
        color(other.color),
        model(other.model),
        co(other.co),
        is_hired(other.is_hired),
        hire_price(other.hire_price)
{}

Masina& Masina::operator=(const Masina& other){
    reg_plate = other.reg_plate;
    fuel = other.fuel;
    color = other.color;
    model = other.model;
    co = other.co;
    fab_year = other.fab_year;
    no_km = other.no_km;
    is_hired = other.is_hired;
    hire_price = other.hire_price;
    return *this;
}

bool Masina::operator==(const Masina& m) const{
    return this->reg_plate == m.reg_plate;
}

Masina::~Masina(){
    std::cout << "Masina cu numarul de inmatriculare " << reg_plate << " a fost stearsa din aplicatie!\n";
}

std::ostream& operator<<(std::ostream& os, const Masina& car){
    os  << "========== Masina ==========\n"
        << "\tNumarul de inmatriculare: " << car.reg_plate <<'\n'
        << "\tMarca: " << car.co << '\n'
        << "\tModelul: " << car.model << '\n'
        << "\tCuloarea: " << car.color << '\n'
        << "\tAnul fabricatiei: " << car.fab_year << '\n'
        << "\tNumarul de kilometri parcursi: " << car.no_km << '\n';
    if(car.fuel == "electrica")
        os << "\tMasina electrica\n";
    else
        os << "\tTipul combustibilului: " << car.fuel << '\n';
    os  << "\tPretul de inchiriere: " << car.hire_price << " RON / zi\n"
        << "\tDisponibilitate: " << ((car.is_hired)? "Indisponibila momentan\n" : "Disponibila\n");

    os << "================== End Masina ==================\n";
    return os;
}

class Reprezentanta{
    static int gen_id;
    std::vector<Masina> cars;
    std::string address;
    int id;

public:
    int get_id() const {return id;}
    void delete_car(const Masina&);
    void add_car(Masina&);
    Reprezentanta(const std::vector<Masina>& , const std::string&);
    ~Reprezentanta();
    friend std::ostream& operator<<(std::ostream&, const Reprezentanta&);
    int find_car(const Masina&);
    bool is_index_hired(int pos){return cars[pos].get_hire_status();}
    void set_hire_status_index(int index, bool status) {cars[index].set_hire_status(status);};
};

int Reprezentanta::gen_id = 0;

int Reprezentanta::find_car(const Masina &m){                      // returneaza pozitia pe care se afla masina data ca parametru in vectorul de cars din reprezentanta sau -1 daca nu exista masina respectiva in reprezentanta
    for(int i = 0; i < (int)cars.size(); ++ i)
        if(cars[i] == m)
            return i;

    return -1;
}

void Reprezentanta::add_car(Masina& m){
    cars.push_back(m);
}

void Reprezentanta::delete_car(const Masina& m){
    int pos = this->find_car(m);
    if(pos != -1) {
        cars.erase(cars.begin() + pos);
        return;
    }

    std::cout << "Masina cu numarul de inmatriculare " << m.get_reg_plate() << " nu este inregistrata la aceasta reprezentanta!\n";
}

Reprezentanta::Reprezentanta(const std::vector<Masina>& cars , const std::string& address):
        cars(cars), address(address), id(++gen_id){
    std::cout << "Reprezentanta cu id-ul " << id << " a fost adaugata in aplicatie.\n";
}

Reprezentanta::~Reprezentanta(){
    std::cout << "Reprezentanta cu id-ul " << id << " a fost stearsa din aplicatie!\n";
}

std::ostream& operator<<(std::ostream& os, const Reprezentanta& rep){
    os  << "========== Reprezentanta ==========\n"
        << "\tId: " << rep.id << '\n'
        << "\tAdresa: " << rep.address << '\n'
        << "\tNumar de masini: " << rep.cars.size() << '\n';
    if(!rep.cars.empty()) {
        std::cout << "\nMasinile din reprezentanta:\n\n";
        for(int i = 0; i < (int)rep.cars.size(); ++ i)
            os << rep.cars[i] << "\n";
    }
    else
        std::cout << "Reprezentanta nu are masini in momentul de fata.\n";

    os << "================== End Reprezentanta ==================\n";
    return os;
}

class User{
    std::string username, email, pass, b_day, cnp, name;
    int age;
    double bal;
    std::optional<Masina> hired_car;


public:
    void hire(Reprezentanta&, const Masina&);
    void unhire();
    User(const std::string& username, const std::string& email, const std::string& pass, const std::string& b_day, const std::string& cnp, const std::string& name, int age, double bal, const std::optional<Masina>&);
    ~User();
    friend std::ostream& operator<<(std::ostream& os, const User& user);
    void load_account(double value){bal += value;}
};

void User::unhire(){
    if(!hired_car){
        std::cout << "Utilizatorul nu are nici o masina inchiriata!\n";
        return;
    }

    hired_car->set_hire_status(false);
    std::cout << "Utilizatorul " << username << " a predat masina " << hired_car->get_reg_plate() << "!\n";
    hired_car = std::nullopt;
}

void User::hire(Reprezentanta& r, const Masina& m){
    if(hired_car){
        std::cout << "Utilizatorul " << this->username << " nu poate inchiria doua masini simultan!\n";
        return;
    }

    if(bal < m.get_price()){
        std::cout << "Utilizatorul " << this->username << " nu are bani suficienti pentru a inchiria masina!\n";
        return;
    }

    int pos = r.find_car(m);
    if(pos == -1){
        std::cout << "Masina cu numarul de inmatriculare " << m.get_reg_plate() <<" nu se afla la aceasta reprezentanta!\n";
        return;
    }

    if(r.is_index_hired(pos)){
        std::cout << "Masina cu numarul de inmatriculare " << m.get_reg_plate() << " este deja inchiriata!\n";
        return;
    }

    hired_car = m;
    bal -= m.get_price();
    r.set_hire_status_index(pos, true);
    std::cout << "Utilizatorul " << this->username << " a inchiriat masina " << m.get_reg_plate() << " de la reprezentanta " << r.get_id() << "!\n";

}

User::User(const std::string& username, const std::string& email, const std::string& pass, const std::string& b_day, const std::string& cnp, const std::string& name, int age, double bal, const std::optional<Masina>& hired_car = std::nullopt):
        username(username), email(email), pass(pass), b_day(b_day), cnp(cnp), name(name), age(age), bal(bal), hired_car(hired_car){
    std::cout << "A fost creat contul utilizatorului cu username-ul " << username << ".\n";
}

User::~User(){
    std::cout << "Contul utilizatorului cu username-ul " << username << " a fost sters din aplicatie!\n";
}

std::ostream& operator<<(std::ostream& os, const User& user){
    os  << "========== Utilizator ==========\n"
        << "\tUsername: " << user.username << '\n'
        << "\tEmail: " << user.email << '\n'
        << "\tParola: " << "[CRYPTED]" << '\n'
        << "\tData nasterii: " << user.b_day << '\n'
        << "\tCNP: " << user.cnp << '\n'
        << "\tNume: " << user.name << '\n'
        << "\tVarsta: " << user.age << '\n'
        << "\tSuma de bani in cont: " << user.bal << " RON" << '\n';
    if(user.hired_car)
        os << "Utilizatorul are inchiriata masina cu numarul de inmatriculare " << user.hired_car->get_reg_plate() << ".\n";
    else
        os << "Utilizatorul NU are nici o masina inchiriata in momentul de fata.\n";

    os << "================== End User ==================\n";
    return os;
}

class Admin{
    Reprezentanta rep;
    std::string pass, username, email, nr_telefon;

public:
    Admin(Reprezentanta& rep, const std::string& username, const std::string& email, const std::string& pass, const std::string& nr_telefon);
    ~Admin();
    friend std::ostream& operator<<(std::ostream& os, const Admin& admin);
};

Admin::~Admin(){
    std::cout << "Contul admin-ului cu username-ul" << username << " a fost sters din aplicatie!\n";
}

Admin::Admin(Reprezentanta& rep, const std::string& username, const std::string& email, const std::string& pass, const std::string& nr_telefon):
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
