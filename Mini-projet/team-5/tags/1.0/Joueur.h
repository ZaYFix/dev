#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>

using namespace std;

class Joueur
{
    private:
        string nomJoueur;
        
    public:
        // constructeur(s) et destructeur(s)
        Joueur(string nomJoueur="Joueur1");
        ~Joueur();

        // accesseur(s)
        string getNomJoueur() const;

        // mutateur(s)
        void setNomJoueur(string nomJoueur); 
};

#endif // JOUEUR_H
