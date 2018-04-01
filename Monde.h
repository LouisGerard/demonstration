//
// Created by louis on 25/03/18.
//

#ifndef MODALE_MONDE_H
#define MODALE_MONDE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "MondeContrainte.h"

class Monde {
private:
    std::vector<Monde*> liens;
    std::vector<MondeContrainte*> contraintes;
    std::unordered_map<char, bool> assignations;
    void print(unsigned profondeur);
    std::string indent(unsigned profondeur);

public:
    void contraindre(MondeContrainte *contrainte);
    Monde() = default;
//    explicit Monde(Monde *other);
    void assigne(char p, bool val);
    bool is_assigne(char p, bool val);

    void lier(Monde *other);
    const std::vector<Monde *> &getLiens() const;
    const std::unordered_map<char, bool> &getAssignations() const;

    void print();
};


#endif //MODALE_MONDE_H
