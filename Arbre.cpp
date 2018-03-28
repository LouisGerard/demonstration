//
// Created by louis on 18/03/18.
//

#include "Arbre.h"
#include "Regle.h"


Arbre::Arbre(std::string expression) {
    expressions.push(expression);
    monde = new Monde();
}

void Arbre::setGauche(Arbre *gauche) {
    Arbre::gauche = gauche;
}

void Arbre::setDroite(Arbre *droite) {
    Arbre::droite = droite;
}

Arbre::~Arbre() {
    free(gauche);
    free(droite);
    free(monde);
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
            if (monde->is_assigne(premier_operateur, !val))
                break;
            monde->assigne(premier_operateur, val);
            expressions.pop();
            continue;
        }

        // appliquer les règles
        for (Regle *r : regles)
            if (r->is_appliquable(e)) {
                (*r)(this, e);
                break;
            }

        // règle contradictoire
        if (nope)
            return false;
    }
    if (gauche != nullptr && gauche->run())
        return true;
    if (droite != nullptr && droite->run())
        return true;
    return expressions.empty();
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
    monde = new Monde(other->monde);
}

void Arbre::diviserArbre(std::string gauche, std::string droite) {
    auto ag = new Arbre(this);
    ag->remplacerExpression(std::move(gauche));
    setGauche(ag);

    auto ad = new Arbre(this);
    ad->remplacerExpression(std::move(droite));
    setDroite(ad);
}

void Arbre::contraindreMonde(std::string expression) {
    unsigned profondeur = 1;
    for (unsigned long i = expression.size()-1; i >= 0; --i)
        if (expression[i] == '#')
            ++profondeur;
        else
            break;
    MondeContrainte *contrainte = new MondeContrainte(this,
                                                      profondeur,
                                                      expression.substr(0, expression.size()-profondeur+1));
    monde->contraindre(contrainte);
    /*for (Monde *l : monde->getLiens()) {
        Arbre a(expression, l);
        if (!a.run()) {
            nope = true;
            break;
        }
    }*/
    expressions.pop();
}

Arbre::Arbre(std::string expression, Monde *monde) {
    expressions.push(expression);
    Arbre::monde = monde;
}

void Arbre::creerMonde(std::string expression) {
    auto *nouveauMonde = new Monde();
    monde->lier(nouveauMonde);

    Arbre a(expression, nouveauMonde);
    if (!a.run())
        nope = true;
    expressions.pop();
}

void Arbre::setNope(bool nope) {
    Arbre::nope = nope;
}

Monde *Arbre::getMonde() const {
    return monde;
}
