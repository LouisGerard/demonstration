//
// Created by louis on 26/03/18.
//

#include <cstring>
#include <utility>
#include "k.h"

void ou(Arbre *arbre, std::string gauche, std::string droite) {
    arbre->diviserArbre(gauche, droite);
}

void et(Arbre *arbre, std::string gauche, std::string droite) {
    arbre->diviserExpression(std::move(gauche), std::move(droite));
}

void double_non(Arbre *arbre, std::string gauche, std::string droite) {
    arbre->remplacerExpression(std::move(gauche));
}

std::vector<Regle*> k() {
    std::vector<Regle*> result;
    result.push_back(new Regle("--", &double_non));
    result.push_back(new Regle("|", &ou));
    result.push_back(new Regle("&", &et));
    return result;
}