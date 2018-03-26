//
// Created by louis on 25/03/18.
//

#ifndef MODALE_MONDE_H
#define MODALE_MONDE_H

#include <vector>
#include <unordered_map>

class Monde {
private:
    std::unordered_map<char, bool> assignations;
    std::vector<Monde*> liens;
public:
    bool is_assigne(char p, bool val);
    bool is_possible(char p, bool val);
    bool is_necessaire(char p, bool val);
};


#endif //MODALE_MONDE_H
