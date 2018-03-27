#include <iostream>
#include <cassert>

#include "infix2postfix.h"
#include "Monde.h"
#include "Regle.h"
#include "k.h"

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

    } else {
        /*string exp1 = "ab>-";
        Regle r1(">-", &ou);
        assert(r1.is_appliquable(exp1));
        Regle r2("&-", &ou);
        assert(!r2.is_appliquable(exp1));

        Arbre *a = new Arbre("ab|");
        Regle ou_r ("|", &ou);
        assert(ou_r.is_appliquable(a->getExpression()));
        ou_r(a);
        assert(a->getGauche() != nullptr);
        assert(a->getGauche()->getExpression() == "b");
        assert(a->getDroite() != nullptr);
        assert(a->getDroite()->getExpression() == "a");
        free(a);*/
        Arbre a("ab|");
        a.setRegles(k());
        a.run();
        cout << "Toutes les epreuves passees" << endl;
    }

    return 0;
}