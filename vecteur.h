//
// Created by Béranger Quintana on 05/03/2021.
//

#ifndef TD1_VECTEUR_H
#define TD1_VECTEUR_H

#include <iostream>

using namespace std;
class vecteur
{
protected:
    int dim;
    float* elements;

public:
    //Déclaration de nouveaux constructeurs
    vecteur(int n_dim);
    vecteur(int n_dim, float const_value);
    vecteur(const vecteur & copy);

    //Destructeur
    ~vecteur();

    //Fonctions
    void print();
    int get_dim() const;
    float* get_elements() const;
    void put(int place, float value);
    void put_all();

    //Opérateurs d'indiçage
    float & operator [](int indice);
    float operator[](int indice) const;
    vecteur & operator = (const vecteur & other);

    //Opérateur arithmétique
    vecteur & operator +=(const vecteur & other);

};

//Opérateur arithmétique
vecteur operator + (const vecteur & a, const vecteur & b);

void test_td1(vecteur & tab , vecteur & tab2 , vecteur & tab3);

void test_td2(vecteur & tab, vecteur & tab2, vecteur & tab3);


#endif //TD1_VECTEUR_H
