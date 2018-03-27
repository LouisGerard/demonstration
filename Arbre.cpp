//
// Created by louis on 18/03/18.
//

#include "Arbre.h"
#include "Regle.h"


Arbre::Arbre(std::string expression) {
    expressions.push_back(expression);
}

void Arbre::setGauche(Arbre *gauche) {
    Arbre::gauche = gauche;
}

void Arbre::setDroite(Arbre *droite) {
    Arbre::droite = droite;
}

Arbre *Arbre::getGauche() const {
    return gauche;
}

Arbre *Arbre::getDroite() const {
    return droite;
}

Arbre::~Arbre() {
    free(gauche);
    free(droite);
    for (Monde *m : mondes)
        free(m);
    for (Regle *r : regles)
        free(r);
}

void Arbre::run() {
    while (!expressions.empty()) {
        std::string e = expressions[expression_courante];
        // todo si lettre seule, assigner
        for (Regle *r : regles)
            if (r->is_appliquable(e))
                (*r)(this, e);
    }
}

void Arbre::setRegles(std::vector<Regle *> regles) {
    Arbre::regles = std::move(regles);
}

void Arbre::remplacerExpression(std::string nouvelle) {
    expressions[expression_courante] = std::move(nouvelle);
}

void Arbre::diviserExpression(std::string gauche, std::string droite) {
    expressions.erase(expressions.begin() + expression_courante);
    expressions.push_back(gauche);
    expressions.push_back(droite);
}

void Arbre::expressionSuivante() {
    ++expression_courante;
}
