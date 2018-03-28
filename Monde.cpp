//
// Created by louis on 25/03/18.
//

#include "Monde.h"

bool Monde::is_assigne(char p, bool val) {
    auto trouvaille = getAssignations().find(p);

    // ignorez l'erreur de clion, ca marche
    return trouvaille != assignations.end() && trouvaille->second == val;
}

void Monde::assigne(char p, bool val) {
    assignations.insert({p, val});
}

Monde::Monde(Monde *other) {
    assignations = other->assignations;
    for (Monde *l : other->liens)
        liens.push_back(new Monde(l));
}

const std::vector<Monde *> &Monde::getLiens() const {
    return liens;
}

void Monde::lier(Monde *other) {
    liens.push_back(other);
    for (MondeContrainte *c : contraintes)
        c->check(other, c->getDeepness()-1);
}

const std::unordered_map<char, bool> &Monde::getAssignations() const {
    return assignations;
}

void Monde::contraindre(MondeContrainte *contrainte) {
    contraintes.push_back(contrainte);
    contrainte->check();
}
