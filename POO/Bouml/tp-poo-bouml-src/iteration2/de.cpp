
#include "De.h"
#include <iostream>

De::De(){
}

De::De(int nbFaces){
}

De::~De(){
}

//Accesseur qui retourne la valeur du D�
int De::getValeur() {
    return valeur;
}

//Lance le d� !
void De::lancer() {
    srand (time(NULL));
    valeur = rand() % nbFaces;
}

