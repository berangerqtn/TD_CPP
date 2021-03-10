//
// Created by Béranger Quintana on 05/03/2021.
//

#include "vecteur.h"

int main() {
    //Génération de deux objets tab et tab2 en faisant appel à nos deux constructeurs.
    vecteur tab(3);
    vecteur tab2(3,0.1);

    //Création d'un vecteur
    vecteur tab3(tab2);

    //test_td1(tab,tab2,tab3);

    test_td2(tab,tab2,tab3);

    return 0;
}
