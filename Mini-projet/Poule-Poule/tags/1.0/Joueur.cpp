#include "Joueur.h"

// constructeur(s) et destructeur(s)
Joueur::Joueur(string nomJoueur): nomJoueur("Joueur1")
{

}

Joueur::~Joueur()
{

}

// accesseur(s)
string Joueur::getNomJoueur() const
{
    return nomJoueur;
}

void Joueur::setNomJoueur(string nomJoueur)
{
    this->nomJoueur = nomJoueur;
}
