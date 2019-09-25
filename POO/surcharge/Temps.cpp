#include "Temps.h"
#include <iostream>
#include <iomanip>

#define HEURE_EN_SECONDE 3600
#define MINUTE_EN_SECONDE 60

using namespace std;

Temps::Temps()
{
    
}

Temps::Temps(long secondes):valeur(secondes)
{
    
}

Temps::Temps(int heure, int minute, int seconde):valeur((heure*HEURE_EN_SECONDE)+(minute*MINUTE_EN_SECONDE)+seconde)
{
    
}

int Temps::getSeconde() const
{
    return ((valeur % 3600) % 60);
}

int  Temps::getMinute() const
{
    return ((valeur % 3600) / 60);
}

int  Temps::getHeure() const
{
    return (valeur / 3600);
}

long Temps::getValeur() const
{
    return valeur;
}

ostream & operator << (ostream & sortie, const Temps &t)
{
    sortie << setfill('0') << setw(2) << t.getHeure() << ":" << setfill('0') << setw(2) << t.getMinute() << ":" << setfill('0') << setw(2) << t.getSeconde();
    return sortie ;
}
/*
istream & operator >> (istream & entree, type_de_base & objet)
{
// Lecture des informations correspondant aux différents membres de objet
// en utilisant les possibilités classiques de >> pour les types de base
// c’est-à-dire des instructions de la forme :
// entree >> ..... ;
return entree ;
}*/
