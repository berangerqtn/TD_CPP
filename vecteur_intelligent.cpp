//
// Created by beran on 12/03/2021.
//
#include "vecteur_intelligent.h"
vecteur_intel & vecteur_intel::operator +=(const vecteur_intel & b){
    if (this->dim<b.get_dim()){

        float*temp=new float[b.get_dim()];

        for (int i=0;i<this->dim;i++)
            temp[i]=this->elements[i]+b[i];
        for (int i=this->dim;i<b.get_dim();i++)
            temp[i]=b.elements[i];

        delete [] this->elements;
        this->elements=temp;
        this->dim=b.get_dim();
    }
    else
    {
        for (int i=0;i<b.get_dim();i++)
            this->elements[i]+=b[i];
    }
    return *this;
}


vecteur_intel operator + (const vecteur_intel &a , const vecteur_intel &b) {
    vecteur_intel temp(a);
    return temp+=b;
}