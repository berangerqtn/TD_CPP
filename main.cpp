//
// Created by Béranger Quintana on 05/03/2021.
//

#include "vecteur_intelligent.h"

int main() {
    //Génération de deux objets tab et tab2 en faisant appel à nos deux constructeurs.
    vecteur tab(3);
    vecteur tab2(3,0.1);
    //Création d'un vecteur
    vecteur tab3(tab2);

    vecteur_intel tab_i1(3);
    vecteur_intel tab_i2(5);
    vecteur_intel tab_i3(10);

    tab_i1.print();
    tab_i2.print();
    tab_i3.print();

    cout<<"Test opérateur += intelligent"<<endl;
    tab_i1+=tab_i2;
    tab_i1.print();

    cout<<"Test opérateur + intelligent"<<endl;
    tab_i2=tab_i1+tab_i3;
    tab_i2.print();
    //test_td1(tab,tab2,tab3);

    //test_td2(tab,tab2,tab3);

    return 0;
}
