//
// Created by beran on 12/03/2021.
//

#ifndef PROG_TD_VECTEUR_INTELLIGENT_H
#define PROG_TD_VECTEUR_INTELLIGENT_H
#include "vecteur.h"

class vecteur_intel : public vecteur{
private:

public:
    vecteur_intel(int dim):vecteur(dim){};
    vecteur_intel(int dim, float val):vecteur(dim,val){};
    vecteur_intel(const vecteur_intel &v):vecteur(v){};

    vecteur_intel & operator +=(const vecteur_intel & b);
};
vecteur_intel operator + (const vecteur_intel & a, const vecteur_intel & b);

#endif //PROG_TD_VECTEUR_INTELLIGENT_H
