#include "Joueur.h"
#include <iostream>

// constructeur(s) et destructeur(s)
Joueur::Joueur(): nomJoueur("\0")
{
    if(nomJoueur == "\0")
    {
        cout << "Quel nom voulez vous avoir ? ";
        cin >> nomJoueur;
        cout << endl;
        setNomJoueur(nomJoueur);
    }
}

Joueur::~Joueur()
{

}

// accesseur(s)
string Joueur::getNomJoueur() const
{
    return this->nomJoueur;
}

// mutateur(s)
void Joueur::setNomJoueur(string nomJoueur)
{
    this->nomJoueur = nomJoueur;
}
