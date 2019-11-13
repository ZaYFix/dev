#include "Joueur.h"

// constructeur et destructeur
Joueur::Joueur(string nomJoueur): nomJoueur("Joueur1")
{

}

Joueur::~Joueur()
{

}

// accesseurs
string Joueur::getNomJoueur() const
{
    return nomJoueur;
}

// mutateurs
void Joueur::setNomJoueur(string nomJoueur)
{
    this->nomJoueur = nomJoueur;
}