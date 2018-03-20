//
// Created by louis on 18/03/18.
//

#include "Expression.h"

Expression::Expression(std::string postfixe) {
    if (DEBUG)
        std::cout << std::endl << postfixe << std::endl;

    operateur = postfixe.back();
    postfixe.pop_back();

    if (is_binaire(operateur)) {
        unsigned long i = postfixe.size()-1;
        while (i >= 0 && is_binaire(postfixe[i])) {}

        if (DEBUG)
            std::cout << "cut ! " << i << std::endl;

        right = new Expression(postfixe.substr(0, i));
        left = new Expression(postfixe.substr(i));
    }
    else if (is_unaire(operateur)) {
        if (DEBUG)
            std::cout << "full" << std::endl;

        left = new Expression(postfixe);
    }
}

bool Expression::is_binaire(char op)const {
    return operateurs_binaires.find(op) != -1;
}

bool Expression::is_unaire(char op)const {
    return operateurs_unaires.find(op) != -1;
}

Expression::~Expression() {
    free(left);
    free(right);
}

bool Expression::operator==(const Expression &rhs) const {
    if ((is_unaire(operateur) || is_binaire(operateur)) && operateur != rhs.operateur)
        return false;

    if (left  == nullptr ^ rhs.left == nullptr)
        return false;

    if (right  == nullptr ^ rhs.right == nullptr)
        return false;

    return  (left == nullptr || *left  == *rhs.left) &&
            (right == nullptr || *right == *rhs.right);
}

bool Expression::operator!=(const Expression &rhs) const {
    return !(rhs == *this);
}
