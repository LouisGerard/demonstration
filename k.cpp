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

void non_ou(Arbre *arbre, std::string gauche, std::string droite) {
    et(arbre, gauche+'-', droite+'-');
}

void non_et(Arbre *arbre, std::string gauche, std::string droite) {
    ou(arbre, gauche+'-', droite+'-');
}

void implique(Arbre *arbre, std::string gauche, std::string droite) {
    ou(arbre, gauche+'-', std::move(droite));
}

void non_implique(Arbre *arbre, std::string gauche, std::string droite) {
    et(arbre, std::move(gauche), droite+'-');
}

void boite(Arbre *arbre, std::string gauche, std::string droite) {
    arbre->contraindreMonde(std::move(gauche));
}

void non_boite(Arbre *arbre, std::string gauche, std::string droite) {
    arbre->creerMonde(gauche+'-');
}

void double_non(Arbre *arbre, std::string gauche, std::string droite) {
    arbre->remplacerExpression(std::move(gauche));
}

std::vector<Regle*> k() {
    std::vector<Regle*> result;
    result.push_back(new Regle("--", &double_non));
    result.push_back(new Regle("&-", &non_et));
    result.push_back(new Regle("|-", &non_ou));
    result.push_back(new Regle(">-", &non_implique));
    result.push_back(new Regle("#-", &non_boite));
    result.push_back(new Regle("|", &ou));
    result.push_back(new Regle("&", &et));
    result.push_back(new Regle(">", &implique));
    result.push_back(new Regle("#", &boite));
    return result;
} // todo add systems