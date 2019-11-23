#ifndef JEU_POULE_POULE_H
#define JEU_POULE_POULE_H

#include <string>
#include <vector>

#define DEBUG

using namespace std;

class IHM;
class Joueur;

typedef enum
{
    OEUF = 0,
    POULE = 1,
    RENARD = 2,
    COQ = 3
} TypeCarte;

class JeuPoulePoule
{
    private:        
        IHM *ihm;
        Joueur *joueur;
        vector<TypeCarte> cartes;
        unsigned int nbPoints;
        unsigned int nbManche;
        unsigned int nbCarteOeuf;
        unsigned int nbCartePoule;
        unsigned int nbCarteRenard;
        unsigned int nbCarteCoq;
        unsigned int reponseJoueur; 
        unsigned int nbOeufsDisponible;
        unsigned int nbPoulesQuiCouvent;
        unsigned int numCarte;
        bool mancheFinie;

    public:
        // constructeur(s) et destructeur(s)
        JeuPoulePoule(unsigned int nbCarteOeuf=15,unsigned int nbCartePoule=10,unsigned int nbCarteRenard=10,unsigned int nbCarteCoq=1,unsigned int nbPoints=0,\
        unsigned int nbManche=1, bool mancheFinie=false, unsigned int nbOeufsDisponible=0, unsigned int nbPoulesQuiCouvent=0, unsigned int numCarte=0);
        ~JeuPoulePoule();

        // méthode(s)
        void demarrer();
        void creerPaquet();
        void melanger();
        void jouer();
        void finirManche();
        void gagnerManche();
        void revoirPartie();
        void indenterNumCarte();
        void reinitialiserValeurs();

        // accesseur(s)
        unsigned int getNbOeufs() const;
        unsigned int getNbPoints() const;
        unsigned int getNbManche() const;
        unsigned int getNumCarte() const;
        unsigned int getNbOeufsDisponible() const;

        // mutateur(s)
        void setNbOeufs(unsigned int nbOeufs);
        void setNbPoints(unsigned int nbPoints);
        void setNbManche(unsigned int nbManche);    
};


#endif // JEU_POULE_POULE_H