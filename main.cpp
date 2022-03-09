#include <iostream>
#include <string>
#include <vector>

class Masina{
    int an_fabricatie, nr_kilometri;
    std::string nr_inmatriculare, tip_combustibil, culoare, model, marca;
    bool disponibila;
    float pret_inchiriere;

public:
    Masina(const std::string& nr_inmatriculare, const std::string& marca, const std::string& model, const std::string& culoare, const std::string& tip_combustibil, int an_fabricatie, int nr_kilometri, float pret_inchiriere, bool disponibila):
            nr_inmatriculare(nr_inmatriculare),
            tip_combustibil(tip_combustibil),
            culoare(culoare),
            model(model),
            marca(marca),
            an_fabricatie(an_fabricatie),
            nr_kilometri(nr_kilometri),
            disponibila(disponibila),
            pret_inchiriere(pret_inchiriere)
    {
        std::cout << "Masina cu numarul de inmatriculare " << nr_inmatriculare << " a fost adaugata in aplicatie.\n";
    }

    Masina(const Masina& other):
            nr_inmatriculare(other.nr_inmatriculare),
            tip_combustibil(other.tip_combustibil),
            culoare(other.culoare),
            model(other.model),
            marca(other.marca),
            an_fabricatie(other.an_fabricatie),
            nr_kilometri(other.nr_kilometri),
            disponibila(other.disponibila),
            pret_inchiriere(other.pret_inchiriere)
    {}

    Masina& operator=(const Masina& other){
        nr_inmatriculare = other.nr_inmatriculare;
        tip_combustibil = other.tip_combustibil;
        culoare = other.culoare;
        model = other.model;
        marca = other.marca;
        an_fabricatie = other.an_fabricatie;
        nr_kilometri = other.nr_kilometri;
        disponibila = other.disponibila;
        pret_inchiriere = other.pret_inchiriere;
        return *this;
    }

    ~Masina(){
        std::cout << "Masina cu numarul de inmatriculare " << nr_inmatriculare << " a fost stearsa din aplicatie!\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Masina& car);
};

std::ostream& operator<<(std::ostream& os, const Masina& car){
    os  << "========== Masina ==========\n"
        << "\tNumarul de inmatriculare: " << car.nr_inmatriculare <<'\n'
        << "\tMarca: " << car.marca << '\n'
        << "\tModelul: " << car.model << '\n'
        << "\tCuloarea: " << car.culoare << '\n'
        << "\tAnul fabricatiei: " << car.an_fabricatie << '\n'
        << "\tNumarul de kilometri parcursi: " << car.nr_kilometri << '\n';
    if(car.tip_combustibil == "electrica")
        os << "\tMasina electrica\n";
    else
        os << "\tTipul combustibilului: " << car.tip_combustibil << '\n';
    os  << "\tPretul de inchiriere: " << car.pret_inchiriere << " RON / zi\n"
        << "\tDisponibilitate: " << ((car.disponibila)? "Disponibila\n" : "Indisponibila momentan\n");

    return os;
}

class User{
    std::string username, email, parola, data_nasterii, cnp, nume, prenume;
    int varsta;
    float bal;
    bool are_masina;

public:
    User(std::string username, std::string email, std::string parola, std::string data_nasterii, std::string cnp, std::string nume, std::string prenume, int varsta, float bal, bool are_masina):
            username(username), email(email), parola(parola), data_nasterii(data_nasterii), cnp(cnp), nume(nume), prenume(prenume), varsta(varsta), bal(bal), are_masina(are_masina)
    {
        std::cout << "A fost creat contul utilizatorului cu username-ul " << username << ".\n";
    }

    ~User(){
        std::cout << "Contul utilizatorului cu username-ul " << username << " a fost sters din aplicatie!\n";
    }
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

std::ostream& operator<<(std::ostream& os, const User& user){
    os  << "========== Utilizator ==========\n"
        << "\tUsername: " << user.username << '\n'
        << "\tEmail: " << user.email << '\n'
        << "\tParola: " << user.parola << '\n'
        << "\tData nasterii: " << user.data_nasterii << '\n'
        << "\tCNP: " << user.cnp << '\n'
        << "\tNume: " << user.nume << '\n'
        << "\tPrenume: " << user.prenume << '\n'
        << "\tVarsta: " << user.varsta << '\n'
        << "\tSuma de bani in cont: " << user.bal << " RON" << '\n';
    if(user.are_masina)
        os << "Utilizatorul are o masina inchiriata in momentul de fata.\n";
    else
        os << "Utilizatorul NU are nici o masina inchiriata in momentul de fata\n";

    return os;
}

class Reprezentanta{
    std::vector<Masina> masini;
    std::string adresa;
    int id, nr_masini, nr_masini_disp;

public:
    Reprezentanta(std::vector<Masina> masini , std::string adresa, int id, int nr_masini, int nr_masini_disp):
            masini(masini), adresa(adresa), id(id), nr_masini(nr_masini), nr_masini_disp(nr_masini_disp)
    {
        std::cout << "Reprezentanta cu id-ul " << id << "a fost adaugata in aplicatie.\n";
    }

    ~Reprezentanta(){
        std::cout << "Reprezentanta cu id-ul " << id << " a fost stearsa din aplicatie!\n";
    };

    friend std::ostream& operator<<(std::ostream& os, const Reprezentanta& rep);
};

std::ostream& operator<<(std::ostream& os, const Reprezentanta& rep){
    os  << "========== Reprezentanta ==========\n"
        << "\tId: " << rep.id << '\n'
        << "\tAdresa: " << rep.adresa << '\n'
        << "\tNumar de masini: " << rep.nr_masini << '\n'
        << "\tNumar de masini disponibile: " << rep.nr_masini_disp << '\n'
        << "\n\tMasinile din reprezentanta:\n\n";

    for(int i = 0; i < rep.nr_masini; ++ i)
        os << rep.masini[i] << "\n";

    return os;
}

class Admin{
    Reprezentanta rep;
    std::string parola, username, email, nr_telefon;

public:
    Admin(const Reprezentanta& rep, const std::string& username, const std::string& email, const std::string& parola, const std::string& nr_telefon):
            rep(rep), username(username), email(email), parola(parola), nr_telefon(nr_telefon){
        std::cout << "Contul admin-ului cu username-ul " << username << "a fost creat.\n";
    }

    ~Admin(){
        std::cout << "Contul admin-ului cu username-ul" << username << " a fost sters din aplicatie!\n";
    };

    friend std::ostream& operator<<(std::ostream& os, const Admin& admin);
};

std::ostream& operator<<(std::ostream& os, const Admin& admin){
    os  << "========== Admin ==========\n"
        << "\tUsername: " << admin.username << '\n'
        << "\tEmail: " << admin.email << '\n'
        << "\tParola: " << admin.parola << '\n'
        << "\tNumar de telefon: " << admin.nr_telefon << '\n'
        << "\tReprezentanta: " << admin.rep;

    return os;
}

int main() {
    Masina m1{"PH 10 GOD","Renault", "Megane 4", "rosie", "motorina", 2019, 10000, 400, false};
    Masina m2{"B 456 CPP","Tesla", "Model Spy", "cyan", "electrica", 2209, 156150, 400, true};
    std::cout << m1 << '\n' << m2 << '\n';
    m1 = m2;
    std::cout << m1 << '\n' << m2;
    return 0;
}
