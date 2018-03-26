//
// Created by louis on 18/03/18.
//

#ifndef MODALE_ARBRE_H
#define MODALE_ARBRE_H

#include <vector>
#include <string>
#include <utility>
#include "Monde.h"

class Arbre {
private:
    Arbre *gauche = nullptr;
    Arbre *droite = nullptr;
    std::vector<Monde*> mondes;
    std::string expression;

public:
    explicit Arbre(std::string expression);

    const std::string &getExpression() const;
};


#endif //MODALE_ARBRE_H
