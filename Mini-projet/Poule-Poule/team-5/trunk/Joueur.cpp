#include "Joueur.h"
#include <iostream>

// constructeur(s) et destructeur(s)
Joueur::Joueur(): nomJoueur("\0")
{
    
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
