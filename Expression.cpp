//
// Created by louis on 18/03/18.
//

#include "Expression.h"

Expression::Expression(std::string postfixe) {
    std::cout << std::endl << postfixe << std::endl;

    operateur = postfixe.back();
    postfixe.pop_back();

    if (is_binaire(operateur)) {
        unsigned long i = postfixe.size()-1;
        while (i >= 0 && is_binaire(postfixe[i])) {}

        std::cout << "cut ! " << i << std::endl;
        right = new Expression(postfixe.substr(0, i));
        left = new Expression(postfixe.substr(i));
    }
    else if (is_unaire(operateur)) {
        std::cout << "full" << std::endl;
        left = new Expression(postfixe);
    }
}

bool Expression::is_binaire(char op) {
    return operateurs_binaires.find(op) != -1;
}

bool Expression::is_unaire(char op) {
    return operateurs_unaires.find(op) != -1;
}

Expression::~Expression() {
    free(left);
    free(right);
}
