#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>

using namespace std;

class Joueur
{
    public:
        Joueur(string nom);
        ~Joueur();        

        string getNom() const;
        void setNom(string nom);

    private:
        string nom;
};

#endif
