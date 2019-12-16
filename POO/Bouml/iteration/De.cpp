
#include "De.h"
#include <iostream>

De::De(): nbFaces(6)
{
    srand(time(NULL));
}

De::De(int nbFaces):nbFaces(nbFaces)
{

}

De::~De()
{

}

//Accesseur qui retourne la valeur du dé
int De::getValeur() 
{
    return valeur;
}

//Lance le dé !
void De::lancer() 
{
    valeur = rand() % nbFaces +1;
}

