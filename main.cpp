#include <iostream>

#include "infix2postfix.h"
#include "Expression.h"

using namespace std;

int main() {
    string postfixe;
    char f_infixe[F_SIZEMAX];
    unsigned int taille_infixe;
    unsigned int i;

    taille_infixe = Lire(f_infixe);

    PILE_SYMBOLES *f_postfixe;
    f_postfixe = Infix2Postfix(taille_infixe, f_infixe);

    for (i = 0; (f_postfixe->symboles[i] != '\n'); ++i) {
        postfixe += f_postfixe->symboles[i];
    }
    postfixe += '-'; // preuve par l'absurde
    cout << postfixe << endl;
    Expression expression(postfixe);

    return 0;
}