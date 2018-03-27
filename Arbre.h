//
// Created by louis on 18/03/18.
//

#ifndef MODALE_ARBRE_H
#define MODALE_ARBRE_H

#include <vector>
#include <string>
#include <utility>
#include "Monde.h"

class Regle;

class Arbre {
private:
    unsigned long expression_courante = 0;
    Arbre *gauche = nullptr;
    Arbre *droite = nullptr;
    std::vector<Monde*> mondes;
    std::vector<std::string> expressions;
    std::vector<Regle*> regles;

public:
    explicit Arbre(std::string expression);


    void setGauche(Arbre *gauche);
    void setDroite(Arbre *droite);
    void setRegles(std::vector<Regle*> regles);

    Arbre *getGauche() const;
    Arbre *getDroite() const;

    void diviserExpression(std::string gauche, std::string droite);
    void remplacerExpression(std::string nouvelle);
    void expressionSuivante();
    void run();

    virtual ~Arbre();
};


#endif //MODALE_ARBRE_H
