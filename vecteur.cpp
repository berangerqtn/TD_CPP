//
// Created by Béranger Quintana on 05/03/2021.
//
#include "vecteur.h"
//définition du constructeur alouant la dimmension au vecteur de floats.

//Crée un vecteur de dimension n qui va de 0 à n

vecteur::vecteur(int n_dim){
    dim=n_dim;
    elements = new float[n_dim];

    for (int i=0;i<n_dim;i++){
        elements[i]=float(i);
    }
}

vecteur::vecteur(int n_dim, float const_value){
    dim= n_dim;
    elements = new float[n_dim];

    for (int i=0;i<n_dim;i++){
        elements[i]=const_value;
    }
}

vecteur::vecteur(vecteur& copy){
    this->dim=copy.dim;
    this->elements = new float[this->dim];

    for (int i=0; i<this->dim ; i++){
        this->elements[i]=copy.elements[i];
    }
}

//Définition du destructeur
vecteur::~vecteur(){
    delete[] elements;
}


//Définition des fonctions

void vecteur::print() {
    for (int i=0;i<dim;i++){
        cout << elements[i] << " " ;
    }
    cout << endl;
}
int vecteur::get_dim() const{
    return dim;
}

void vecteur::put(int place , float value){
    this->elements[place]=value;
}

void vecteur::put_all(){
    float val;
    for (int i =0 ; i<dim;i++){
        cout<<"Quelle valeur en "<<i+1<<"eme position ?"<<endl;
        cin >> val;
        vecteur::put(i,val);
        cout << endl;
    }
}

float & vecteur::operator [](int indice){
    if (indice>this->dim){
        cout<<"On ne peut éditer un indice supérieur à la dimension du vecteur"<<endl;
        exit(-1);
    }
    return this->elements[indice];

}
float vecteur::operator [](int indice) const {
    if (indice>this->dim) {
        cout<<"On ne peut éditer un indice supérieur à la dimension du vecteur"<<endl;
        exit(-1);
    }
    return this->elements[indice];
}

vecteur & vecteur::operator =(const vecteur & other){
    this->dim=other.dim;
    delete this->elements;
    this->elements = new float[this->dim];
    for (int i=0;i<this->dim;i++){
        this->elements[i]=other.elements[i];
    }
    return *this;
}

float * vecteur::get_elements() const{
    float *a;
    a = new float[this->dim];
    for (int i=0;i<this->get_dim();i++)
        a[i]=this->elements[i];
    return a;
}

vecteur & vecteur::operator+=(const vecteur &other) {
    if (this->dim!=other.dim)
        exit(-1);

    for (int i=0;i<this->dim;i++)
        this->elements[i]+=other.elements[i];

    return *this;
}

vecteur operator + (const vecteur &a , const vecteur &b) {
    if (a.get_dim() != b.get_dim())
        exit(-1);

    vecteur temp(a.get_dim());

    for (int i=0;i<temp.get_dim();i++)
        temp.put(i,a[i]+b[i]);

    return temp;
}


void test_td1(vecteur & tab, vecteur & tab2, vecteur & tab3) {
    //Affichage de nos vecteurs.
    cout<<"Vecteur 1 : ";
    tab.print();
    cout<<"Vecteur 2 :  ";
    tab2.print();
    cout<<"Vecteur 3 :  ";
    tab3.print();


    //Test des méthodes de modification d'une valeur précise du vecteur.
    tab2.put(8,25.0);
    cout<<"Vecteur 2 apres modification du vecteur 2 : ";
    tab2.print();
    //On vérifie que le constructeur de recopie fonctionne bien.
    cout<<"Vecteur 3 apres modification du vecteur 2 : ";
    tab3.print();

    //Test de la méthode de modification de toutes les valeurs d'un vecteur.
    tab3.put_all();
    tab3.print();

}

void test_td2(vecteur & tab, vecteur & tab2, vecteur & tab3) {
    //Test de la surcharge de l'opérateur []
    cout<<"Test de l'opérateur []"<<endl;
    tab3[2]=1;
    tab3.print();

    float v =tab3[2];
    cout<<v<<endl;

    //Test de la surcharge de l'opérateur =
    cout<<"Test de l'opérateur ="<<endl;
    vecteur tab4=tab3;
    tab3.put_all();
    tab3.print();
    tab4.print();

    cout<<"Test de l'opérateur +"<<endl;
    tab.print();
    tab2.print();

    tab3=tab+tab2;

    tab3.print();

    cout<<"Test de l'opérateur +="<<endl;
    tab3+=tab2;
    tab3.print();
}

