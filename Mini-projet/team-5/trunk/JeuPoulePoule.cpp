#include "JeuPoulePoule.h"

// constructeur et destructeur
JeuPoulePoule::JeuPoulePoule()
{

}

JeuPoulePoule::~JeuPoulePoule()
{
    
}

// accesseurs
unsigned int JeuPoulePoule::getNbOeufs()
{
    return nbOeufs;
}

unsigned int JeuPoulePoule::getNbPoints()
{
    return nbPoints;
}

unsigned int JeuPoulePoule::getNbManche()
{
    return nbManche;
}

unsigned int JeuPoulePoule::getNbCartes()
{
    return nbCartes;
}

// mutateurs
void JeuPoulePoule::setNbOeufs(unsigned int nbOeufs)
{
    this->nbOeufs = nbOeufs;
}

void JeuPoulePoule::setNbPoints(unsigned int nbPoints)
{
    this->nbPoints = nbPoints;
}

void JeuPoulePoule::setNbManche(unsigned int nbManche)
{
    this->nbManche = nbManche;
}

void JeuPoulePoule::setNbCartes(unsigned int nbCartes)
{
    this->nbCartes = nbCartes;
}