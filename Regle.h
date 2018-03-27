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
    fonction f;
public:
    Regle(const std::string &operateurs, fonction f);

    void operator()(Arbre *arbre, std::string expression);
    bool is_appliquable(const std::string &expression);
};


#endif //MODALE_REGLE_H
