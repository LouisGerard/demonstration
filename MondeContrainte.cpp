//
// Created by louis on 29/03/18.
//

#include "MondeContrainte.h"
#include "Arbre.h"

MondeContrainte::MondeContrainte(Arbre *arbre, unsigned int profondeur, const std::string &expression)
        : arbre(arbre), profondeur(profondeur), expression(expression) {}

void MondeContrainte::check() {
    check(arbre->getMonde(), profondeur);
}

void MondeContrainte::check(Monde *m, unsigned profondeur) {
    if (profondeur == 0) {
        Arbre a(expression, m);
        if (!a.run()) {
            arbre->setNope(true);
        }
    }
    else
        for (Monde *l : m->getLiens()) {
            check(l, profondeur-1);
        }
}

unsigned int MondeContrainte::getDeepness() const {
    return profondeur;
}
