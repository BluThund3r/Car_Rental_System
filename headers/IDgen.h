//
// Created by bluth on 01/06/2022.
//

#ifndef MAIN_CPP_IDGEN_H
#define MAIN_CPP_IDGEN_H

#include <string>
#include <vector>

class Masina;
class Reprezentanta;

template <typename T>
class IDgen {
    static int incrID;
public:
    int generate();
};

template <typename T> int IDgen<T>::incrID = 0;

template <typename T>
int IDgen<T>::generate() {
    return ++ incrID;
}

template <>
class IDgen<Masina> {
public:
    std::string generate() {
        srand(time(NULL));
        std::string regPlate;
        const std::vector<std::string> judete = {"AB", "AR", "AG", "BC", "BH", "BN", "BT", "BV", "BR", "B", "BZ", "CS",
                                                 "CL", "CJ", "CT", "CV", "DB", "DJ", "GL", "GR", "GJ", "HR", "HD", "IL",
                                                 "IS", "IF", "MM", "MH", "MS", "NT", "OT", "PH", "SM", "SJ", "SB", "SV",
                                                 "TR", "TM", "TL", "VS", "VL", "VN" };

        regPlate += judete[rand() % judete.size()];
        if(regPlate == "B") {
            regPlate += " ";
            int numar = rand() % 999 + 1;
            if(numar < 10)
                regPlate += "0" + std::to_string(numar);
            else
                regPlate += std::to_string(numar);
        }

        else {
            regPlate += " ";
            int numar = rand() % 99 + 1;
            if(numar < 10)
                regPlate += "0" + std::to_string(numar);
            else
                regPlate += std::to_string(numar);
        }

        regPlate += " ";
        for(int i = 0; i < 3; ++ i)
            regPlate += (char)(rand() % 26 + 65);

        return regPlate;
    }
};

#endif //MAIN_CPP_IDGEN_H
