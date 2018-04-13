#include <iostream>
#include <cassert>

#include "infix2postfix.h"
#include "Monde.h"
#include "Regle.h"
#include "k.h"

#define TEST false

using namespace std;

int main() {
    if (!TEST) {
        cout << endl << "\033[1;31;40m"
             << ",------.                                          ,--.                   ,--.                        " << endl
             << "|  .-.  \\  ,---. ,--,--,--. ,---. ,--,--,  ,---.,-'  '-.,--.--. ,--,--.,-'  '-. ,---. ,--.,--.,--.--." << endl
             << "|  |  \\  :| .-. :|        || .-. ||      \\(  .-''-.  .-'|  .--'' ,-.  |'-.  .-'| .-. :|  ||  ||  .--'" << endl
             << "|  '--'  /\\   --.|  |  |  |' '-' '|  ||  |.-'  `) |  |  |  |   \\ '-'  |  |  |  \\   --.'  ''  '|  |" << endl
             << "`-------'  `----'`--`--`--' `---' `--''--'`----'  `--'  `--'    `--`--'  `--'   `----' `----' `--'" << endl
             << endl
             << "                    ,--.        ,--." << endl
             << ",--,--,--. ,---.  ,-|  | ,--,--.|  |" << endl
             << "|        || .-. |' .-. |' ,-.  ||  | \033[4;32mpar Louis GERARD & Mehri GOLCHIN KHARAZI\033[1;31;24m" << endl
             << "|  |  |  |' '-' '\\ `-' |\\ '-'  ||  |" << endl
             << "`--`--`--' `---'  `---'  `--`--'`--'" << endl
             << endl << "\033[0m"
             << "Choisissez votre systeme : " << endl
             << "1 pour K" << endl
             << "2 pour T" << endl;
        char sys_lu;
        cin >> sys_lu;
        vector<Regle*> sys;
        switch (sys_lu) {
            case '1':
                sys = k();
                break;
            case '2':
                sys = t();
                break;
            default:
                cerr << "Mauvais système !" << endl;
                return -1;
        }
        cout << "Veuillez entrer une formule : ";
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
        cout << "Forme négative postfixe : " << postfixe << endl;
        Arbre arbre(postfixe);
        arbre.setRegles(sys);
        if (arbre.run()) {
            cout << "Il existe une assignation qui rend la formule fausse : " << endl;
            Arbre *bloquant = &arbre;
            while (true) {
                if (bloquant->getGauche() != nullptr && bloquant->getGauche()->isNope())
                    bloquant = bloquant->getGauche();
                else if (bloquant->getDroite() != nullptr && bloquant->getDroite()->isNope())
                    bloquant = bloquant->getDroite();
                else
                    break;
            }
            bloquant->getMonde()->print();
        }
        else
            cout << "La formule est toujours vraie." << endl;

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
        Monde *m = new Monde();
        m->assigne('a', true);
        Monde m2 = Monde(*m);
    }

    return 0;
}