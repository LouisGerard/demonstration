#include <iostream>
#include <cassert>

#include "infix2postfix.h"
#include "Expression.h"
#include "Monde.h"
#include "Regle.h"

#define TEST true

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
        string exp = "ab>-";
        Regle r1(">-");
        assert(r1.is_appliquable(exp));
        Regle r2("&-");
        assert(!r2.is_appliquable(exp));

        pair<Arbre*, Arbre*> aze = r1(exp);
        cout << "Toutes les epreuves passees" << endl;
    }

    return 0;
}