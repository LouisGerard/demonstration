//
// Created by louis on 18/03/18.
//

#include "Arbre.h"
#include "Regle.h"


Arbre::Arbre(std::string expression) {
    expressions.push(expression);
    mondes.push(new Monde());
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
    while(!mondes.empty()) {
        free(mondes.top());
        mondes.pop();
    }
    for (Regle *r : regles)
        free(r);
}

bool Arbre::run() {
    while (!expressions.empty() && gauche == nullptr && droite == nullptr) {
        std::string e = expressions.top();

        // assigner
        char premier_operateur = e[e.size() - 1];
        bool val = true;
        if (premier_operateur == '-') {
            val = false;
            premier_operateur = e[e.size() - 2];
        }
        if (isalpha(premier_operateur)) {
            if (mondes.top()->is_assigne(premier_operateur, !val))
                break;
            mondes.top()->assigne(premier_operateur, val);
            expressions.pop();
            continue;
        }

        // appliquer les règles
        for (Regle *r : regles)
            if (r->is_appliquable(e)) {
                (*r)(this, e);
                break;
            }
    }
    if (gauche != nullptr && gauche->run())
        return true;
    return droite != nullptr && droite->run();
}

void Arbre::setRegles(std::vector<Regle *> regles) {
    Arbre::regles = std::move(regles);
}

void Arbre::remplacerExpression(std::string nouvelle) {
    expressions.pop();
    expressions.push(nouvelle);
}

void Arbre::diviserExpression(std::string gauche, std::string droite) {
    expressions.pop();
    expressions.push(gauche);
    expressions.push(droite);
}

Arbre::Arbre(Arbre *other) {
    expressions = other->expressions;
    regles = other->regles;
    mondes = other->mondes;
}

void Arbre::diviserArbre(std::string gauche, std::string droite) {
    auto ag = new Arbre(this);
    ag->remplacerExpression(std::move(gauche));
    setGauche(ag);

    auto ad = new Arbre(this);
    ad->remplacerExpression(std::move(droite));
    setDroite(ad);
}
