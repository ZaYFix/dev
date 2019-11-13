#ifndef JEU_POULE_POULE_H
#define JEU_POULE_POULE_H

#include <iostream>
using namespace std;

class JeuPoulePoule
{
    private:
        unsigned int nbOeufs;
        unsigned int nbPoints;
        unsigned int nbManche;
        unsigned int nbCartes;

    public:
        // constructeur et destructeur
        JeuPoulePoule();
        ~JeuPoulePoule();

        // accesseur(s)
        unsigned int getNbOeufs();
        unsigned int getNbPoints();
        unsigned int getNbManche();
        unsigned int getNbCartes();

        // mutateur(s)
        void setNbOeufs(unsigned int nbOeufs);
        void setNbPoints(unsigned int nbPoints);
        void setNbManche(unsigned int nbManche);
        void setNbCartes(unsigned int nbCartes);
    
};


#endif // JEU_POULE_POULE_H