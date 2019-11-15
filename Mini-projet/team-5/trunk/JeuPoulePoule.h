#ifndef JEU_POULE_POULE_H
#define JEU_POULE_POULE_H

//#define DEBUG

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Joueur.h"
#include "IHM.h"
#include <iostream>
using namespace std;

class IHM;

class Joueur;

class JeuPoulePoule
{
    private:
        vector<TypeCarte> cartes;
        IHM *ihm;
        Joueur * joueur;
        
        static unsigned int nbOeufsDisponible;
        static unsigned int nbPoulesQuiCouvent;

        unsigned int nbPoints;
        unsigned int nbManche;
        unsigned int nbCarteOeuf;
        unsigned int nbCartePoule;
        unsigned int nbCarteRenard;
        unsigned int nbCarteCoq;
        unsigned int reponseJoueur; 

        bool mancheFinie;

    public:
        // constructeur et destructeur
        JeuPoulePoule(unsigned int nbCarteOeuf=15, unsigned int nbCartePoule=10, unsigned int nbCarteRenard=10, unsigned int nbCarteCoq=1, unsigned int nbPoints=0, unsigned int nbManche=1);
        ~JeuPoulePoule();

        // méthode(s)
        void creerPaquet();
        void melanger();
        void jouer();

        // accesseur(s)
        unsigned int getNbOeufs();
        unsigned int getNbPoints();
        unsigned int getNbManche();

        // mutateur(s)
        void setNbOeufs(unsigned int nbOeufs);
        void setNbPoints(unsigned int nbPoints);
        void setNbManche(unsigned int nbManche);    
};


#endif // JEU_POULE_POULE_H