#include <iostream>
#include <cassert>

#include "infix2postfix.h"
#include "Expression.h"

#define TEST false

using namespace std;

int main() {
    if (!TEST) {
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
    } else {
        Expression e1("c-b>a>-");
        Expression e2("c-b>a>-");
        assert(e1 == e2);

        Expression e3("c-b>a>");
        assert(e1 != e3);

        Expression e4("d-b>a>-");
        assert(e1 == e4);
        cout << "All tests passed !" << endl;
    }

    return 0;
}