//
// Created by louis on 18/03/18.
//

#ifndef MODALE_ARBRE_H
#define MODALE_ARBRE_H

#include <vector>
#include <string>
#include <utility>
#include <stack>
#include "Monde.h"

class Regle;

class Arbre {
private:
    Arbre *gauche = nullptr;
    Arbre *droite = nullptr;
    std::stack<std::string> expressions;
    std::vector<Regle*> regles;
    bool nope = false;
    Monde* monde;

public:
    explicit Arbre(std::string expression);
    explicit Arbre(std::string expression, Monde* monde);

    Monde *getMonde() const;
    Arbre *getGauche() const;
    Arbre *getDroite() const;

    const std::vector<Regle *> &getRegles() const;

    bool isNope() const;

    void setGauche(Arbre *gauche);
    void setDroite(Arbre *droite);
    void setRegles(std::vector<Regle*> &regles);
    void setNope(bool nope);

    void diviserArbre(std::string gauche, std::string droite);
    void diviserExpression(std::string gauche, std::string droite);
    void remplacerExpression(std::string nouvelle);
    void creerMonde(std::string expression);
    void contraindreMonde(std::string expression);

    bool run();

    virtual ~Arbre();
};


#endif //MODALE_ARBRE_H
