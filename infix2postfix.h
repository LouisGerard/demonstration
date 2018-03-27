//
// Created by louis on 18/03/18.
//

#ifndef MODALE_INFIX2POSTFIX_H
#define MODALE_INFIX2POSTFIX_H

#include <cstdio>
#include <string>
#include "Arbre.h"

#define F_SIZEMAX 51

typedef struct pile_symboles {
    unsigned int top;
    char symboles[F_SIZEMAX];
} PILE_SYMBOLES;

typedef void (*fonction)(Arbre*, std::string, std::string);

unsigned int Lire(char *formule);
PILE_SYMBOLES *Infix2Postfix(unsigned int taille_infixe, const char *f_infixe);

bool is_unaire(char op);
bool is_binaire(char op);

#endif //MODALE_INFIX2POSTFIX_H
