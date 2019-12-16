#include "joueur.h"
#include "De.h"

Joueur::Joueur(string nom) : nom(nom)
{
    De *de1 = new De;
    De *de2 = new De;
    
    des.push_back(de1);
    des.push_back(de2);
}

Joueur::~Joueur()
{

}

string Joueur::getNom() const 
{
    return nom;
}

void Joueur::setNom(string nom) 
{
    this->nom = nom;
}

void Joueur::jouerAuxDes()
{
    des[0]->lancer();
    des[1]->lancer();
    
    int valeurDe1 = des[0]->getValeur();
    int valeurDe2 = des[1]->getValeur();
    
    cout <<"Dé 1: " << valeurDe1 << " Dé 2: " << valeurDe2 << endl; 
    
    if (valeurDe1 == valeurDe2)
    {
        cout<< "Bravo " << nom << ", c'est un double, +20 points ! " << endl; 
    }
    else if (valeurDe2 ==  1 + valeurDe1 || valeurDe1 == 1 + valeurDe2 )
    {
        cout << "Bravo " << nom << ", c'est une suite, +15 points ! "  << endl;
    }
    else if ( valeurDe2 + valeurDe1 > 7)
    {
        cout << "Bravo " << nom << " tu as obtenu plus de 7, +10 points !" << endl;
    }
    else 
    {
        cout << "Bravo " << nom << " +" << valeurDe2 + valeurDe1 << " point(s) !" << endl;
    }
    
}
    
