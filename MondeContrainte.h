//
// Created by louis on 29/03/18.
//

#ifndef MODALE_MONDECONTRAINTE_H
#define MODALE_MONDECONTRAINTE_H

#include <string>

class Arbre;
class Monde;

class MondeContrainte {
private:
    Arbre *arbre;
    unsigned profondeur;
    std::string expression;
public:

    MondeContrainte(Arbre *arbre, unsigned int profondeur, const std::string &expression);
    void check();
    void check(Monde *m, unsigned profondeur);

    unsigned int getDeepness() const;
};


#endif //MODALE_MONDECONTRAINTE_H
