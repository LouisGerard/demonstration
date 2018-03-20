// -----------------------------------------------------------------------------
// Transformation d'une formule logique infixe en forme prefixe
// 22/03/2017
//
// Le programme recupere une formule logique en forme infixe donnee sous la
// forme d'un tableau de caracteres f_infixe pour la transmettre a la fonction
// Infix2prefix qui la transforme prealablement en forme postfixe avant de
// l'inverser en forme prefixe. Infix2Prefix gere deux piles : une pile des
// operateurs pile_operateurs et f_postfixe vue initialement comme pile des
// operandes a laquelle les operateurs sont ajoutes au fur et a mesure qu'ils
// sont depiles de pile_operateurs. Les operandes sont tout caractere minuscule
// entre 'a' et 'z', les operateurs sont
// '#': modalite []
// '%': modalite <>
// '-': negation
// '&': et
// '|': ou
// '>': implique
// issus de l'analyse de l'analyse syntaxique de la formule initialement
// entree par l'utilisateur (par exemple sous la forme a & (-[]b => <>c).
// -----------------------------------------------------------------------------

#include <stdio.h>
#include "infix2postfix.h"

// -----------------------------------------------------------------------------
// Gestion de la pile
// -----------------------------------------------------------------------------

char NextChar(void) {
    // Renvoie le prochain caractere trouve sur l'entree standart
    // a l'exception des blancs

    char c;

    while ((c = (char) getchar()) == ' ') {}
    return c;
}

void PushChar(char c, PILE_SYMBOLES *pile) {
    // Empile le caractere lu

    pile->symboles[pile->top++] = c;
}

char PopChar(PILE_SYMBOLES *pile) {
    // Depile le caractere lu */

    return pile->symboles[--pile->top];
}

// -----------------------------------------------------------------------------
// Transformation Infix2prefix
// -----------------------------------------------------------------------------

int Precedence(char c) {
    // Renvoie le degre de precedence de l'operateur c

    switch (c) {
        case '#':         // modalite []
        case '%':         // modalite <>
        case '-':         // negation
            return 1;
        case '&':         // et
        case '|':         // ou
        case '>':         // implique
            return 0;
        default :
            return 0;
    }
}

int IsOperator(char c) {
    // Vérifie que c est un operateur

    switch (c) {
        case '#':         // modalite []
        case '%':         // modalite <>
        case '-':         // negation
        case '&':         // et
        case '|':         // ou
        case '>':         // implique
            return 1;
        default :
            return 0;
    }
}

int IsProposition(char c) {
    // Vérifie que c est une lettre minuscule

    return ((c >= 'a') && (c <= 'z'));
}

PILE_SYMBOLES *Infix2Postfix(unsigned int taille_infixe, const char *f_infixe) {
    // Transforme la formule infixe en expression postfixe

    PILE_SYMBOLES tableau_operandes = {0};
    PILE_SYMBOLES *pile_operandes = &tableau_operandes; // sert a la fois de pile des operandes et
    // de pile de renvoi de la formule postfixe

    PILE_SYMBOLES tableau_operateurs = {0};
    PILE_SYMBOLES *pile_operateurs = &tableau_operateurs;

    signed int i, parentheses = 0;
    char c;

    for (i = taille_infixe - 1; (i >= 0); --i) {
        c = f_infixe[i];
        if (IsOperator(c)) {
            while ((pile_operateurs->top > 0) &&
                   (Precedence(pile_operateurs->symboles[pile_operateurs->top - 1]) >= Precedence(c)))
                PushChar(PopChar(pile_operateurs), pile_operandes);
            PushChar(c, pile_operateurs);
        } else if (IsProposition(c))
            PushChar(c, pile_operandes);
        else if (c == ')')
            parentheses += 1;
        else if (c == '(') {
            parentheses -= 1;
            while (pile_operateurs->top > 0)
                PushChar(PopChar(pile_operateurs), pile_operandes);
        }
    }
    while (pile_operateurs->top > 0)
        PushChar(PopChar(pile_operateurs), pile_operandes);
    PushChar('\n', pile_operandes);

    return pile_operandes;
}

// -----------------------------------------------------------------------------
// Entree-sortie
// -----------------------------------------------------------------------------

unsigned int Lire(char *formule) {
    // Lit une formule sous forme d'un tableau de caracteres

    unsigned int longueur;

    formule[F_SIZEMAX] = '\n';   // sentinelle
    longueur = 0;
    while ((formule[longueur++] = NextChar()) != '\n') {}

    return longueur - 1;
}

void Afficher(char *formule) {
    // Affiche une formule sous forme d'un tableau de caracteres

    unsigned int i;

    for (i = 0; (formule[i] != '\n'); ++i)
        printf("%c", formule[i]);
    printf("\n");
}

// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------
/*
int main(void) {
    taille_infixe = Lire(f_infixe);

    printf("taille_infixe = %d\n", taille_infixe);
    for (i = 0; (f_infixe[i] != '\n'); ++i)
        printf("%c", f_infixe[i]);
    printf("\n");

    f_postfixe = Infix2Postfix(taille_infixe, f_infixe);

    for (i = 0; (f_postfixe->symboles[i] != '\n'); ++i)
        printf("%c", f_postfixe->symboles[i]);
    printf("\n");
//     Afficher(f_postfixe->symboles);

    return 0;
}
*/