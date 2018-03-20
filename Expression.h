//
// Created by louis on 18/03/18.
//

#ifndef MODALE_EXPRESSION_H
#define MODALE_EXPRESSION_H

#include <iostream>

class Expression {
private:
    Expression *left = nullptr;
    Expression *right = nullptr;
    char operateur;

    std::string operateurs_binaires = ">&|";
    std::string operateurs_unaires  = "-#%";

    bool is_unaire(char op);
    bool is_binaire(char op);

public:
    explicit Expression(std::string postfixe);

    virtual ~Expression();

};


#endif //MODALE_EXPRESSION_H
