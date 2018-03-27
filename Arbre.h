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
    std::stack<Monde*> mondes;
    std::stack<std::string> expressions;
    std::vector<Regle*> regles;

public:
    explicit Arbre(std::string expression);
    explicit Arbre(Arbre *other);


    void setGauche(Arbre *gauche);
    void setDroite(Arbre *droite);
    void setRegles(std::vector<Regle*> regles);

    Arbre *getGauche() const;
    Arbre *getDroite() const;

    void diviserArbre(std::string gauche, std::string droite);
    void diviserExpression(std::string gauche, std::string droite);
    void remplacerExpression(std::string nouvelle);
    bool run();

    virtual ~Arbre();
};


#endif //MODALE_ARBRE_H
