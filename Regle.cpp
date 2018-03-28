//
// Created by louis on 18/03/18.
//

#include "Regle.h"

Regle::Regle(const std::string &operateurs, fonction f) :
        operateurs(operateurs),
        f(f) {}

void Regle::operator()(Arbre *arbre, std::string expression) {
    std::string sub = expression.substr(0, expression.size()-operateurs.size());

    std::string gauche, droite;
    unsigned long i = sub.size()-1;
    unsigned long split = sub.size()-1;
    while (i >= 0) {
        if (is_binaire(sub[i]))
            split -= 2;
        else if (is_unaire(sub[i]))
            --split;
        else
            break;
        --i;
    }

    droite = sub.substr(0, split);
    gauche = sub.substr(split);
    f(arbre, gauche, droite);
}

bool Regle::is_appliquable(const std::string &expression) {
    for (unsigned long i = expression.size()-1; i >= 0; --i) {
        unsigned long operateurs_i = i - (expression.size() - operateurs.size());
        if (operateurs_i >= operateurs.size())
            return true;
        if (expression[i] != operateurs[operateurs_i])
            return false;
    }
    return false;
}
