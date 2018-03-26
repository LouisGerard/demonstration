//
// Created by louis on 18/03/18.
//

#include "Regle.h"

Regle::Regle(const std::string &operateurs, void (*function)(Arbre *, std::string, std::string)) :
        operateurs(operateurs),
        function(function) {}

void Regle::operator()(Arbre *arbre) {
    std::string expression = arbre->getExpression();
    std::string sub = expression.substr(0, expression.size()-operateurs.size());

    std::string gauche, droite;
    unsigned long i = sub.size()-1;
    while (i >= 0 && is_binaire(sub[i])) {
        --i;
    }

    droite = sub.substr(0, i);
    gauche = sub.substr(i);
    function(new Arbre(expression), gauche, droite);
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
