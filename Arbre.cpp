//
// Created by louis on 18/03/18.
//

#include "Arbre.h"


Arbre::Arbre(std::string expression) : expression(std::move(expression)) {}

const std::string &Arbre::getExpression() const {
    return expression;
}
