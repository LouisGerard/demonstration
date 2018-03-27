//
// Created by louis on 25/03/18.
//

#include "Monde.h"

bool Monde::is_assigne(char p, bool val) {
    std::unordered_map<char, bool>::const_iterator trouvaille = assignations.find(p);
    // ignorez l'erreur de clion, ca marche
    return trouvaille != assignations.end() && trouvaille->second == val;
}

bool Monde::is_possible(char p, bool val) {
    for (Monde *m : liens)
        if (m->is_assigne(p, val))
            return true;
    return false;
}

bool Monde::is_necessaire(char p, bool val) {
    for (Monde *m : liens)
        if (!m->is_assigne(p, val))
            return false;
    return true;
}

void Monde::assigne(char p, bool val) {
    assignations.insert({p, val});
}
