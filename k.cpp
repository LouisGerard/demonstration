//
// Created by louis on 26/03/18.
//

#include "k.h"

void ou(Arbre *arbre, std::string gauche, std::string droite) {
    arbre->setGauche(new Arbre(gauche));
    arbre->setDroite(new Arbre(droite));
}

void et(Arbre *arbre, std::string gauche, std::string droite) {
    arbre->diviserExpression(gauche, droite);
}

void double_non(Arbre *arbre, std::string gauche, std::string droite) {
    arbre->remplacerExpression(gauche);
}

std::vector<Regle*> k() {
    std::vector<Regle*> result;
    result.push_back(new Regle("--", &double_non));
    result.push_back(new Regle("|", &ou));
    result.push_back(new Regle("&", &et));
    return result;
}