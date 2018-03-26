//
// Created by louis on 18/03/18.
//

#ifndef MODALE_REGLE_H
#define MODALE_REGLE_H

#include <utility>
#include "infix2postfix.h"
#include "Arbre.h"

class Regle {
private:
    std::string operateurs;
    void (*function) (Arbre*, std::string, std::string);
public:
    Regle(const std::string &operateurs, void (*function)(Arbre *, std::string, std::string));

    void Regle::operator()(Arbre *arbre);
    bool is_appliquable(const std::string &expression);
};


#endif //MODALE_REGLE_H
