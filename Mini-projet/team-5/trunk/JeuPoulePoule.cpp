#include "JeuPoulePoule.h"
#include "Joueur.h"
#include "IHM.h"

#include <algorithm> // pour random_shuffle
#include <iostream> // pour les cout des debug

using namespace std;


// constructeur(s) et destructeur(s)
JeuPoulePoule::JeuPoulePoule(unsigned int nbCarteOeuf, unsigned int nbCartePoule, unsigned int nbCarteRenard, unsigned int nbCarteCoq, unsigned int nbPoints,\
unsigned int nbManche, bool mancheFinie, unsigned int nbOeufsDisponible, unsigned int nbPoulesQuiCouvent, unsigned int numCarte):nbCarteOeuf(15),nbCartePoule(10),\
nbCarteRenard(10),nbCarteCoq(1),nbPoints(0),nbManche(1),mancheFinie(false),nbOeufsDisponible(0),nbPoulesQuiCouvent(0),numCarte(0)
{
    ihm = new IHM(this);
    joueur = new Joueur;
}

JeuPoulePoule::~JeuPoulePoule()
{
    delete ihm;
    delete joueur;
}

// méthode(s)
void JeuPoulePoule::demarrer()
{
    ihm->afficherNomJeu();
    ihm->afficherBienvenue();
    ihm->afficherRegles();
    ihm->afficherQuestionExemple();
    ihm->effacerIHM();
    jouer();
    finirManche();
}

void JeuPoulePoule::creerPaquet()
{
    for (int i = 0; i < nbCarteOeuf; ++i)
    {
        cartes.push_back(OEUF);
    }

    for (int i = 0; i < nbCartePoule; ++i)
    {
        cartes.push_back(POULE);
    }

    for (int i = 0; i < nbCarteRenard; ++i)
    {
        cartes.push_back(RENARD);
    }
    
    for (int i = 0; i < nbCarteCoq; ++i)
    {
        cartes.push_back(COQ);
    }  
}

int chiffre_aleatoire(int i) 
{ 
    return rand()%i;
}

void JeuPoulePoule::melanger() 
{
    srand ( unsigned ( time(0) ) );
    random_shuffle ( this->cartes.begin(), this->cartes.end(), chiffre_aleatoire);
}

void JeuPoulePoule::jouer()
{
    creerPaquet();
    melanger();
    reinitialiserValeurs();
    
    for(vector<TypeCarte>::iterator it=cartes.begin(); it!=cartes.end(); ++it)
    {
        ihm->effacerIHM();
        indenterNumCarte();
        ihm->afficherCarte(*it);
        switch(*it)
        {
            case OEUF:
                nbOeufsDisponible++;
                break;
            case POULE:
                if(nbOeufsDisponible > 0)
                {
                    nbOeufsDisponible--;
                    nbPoulesQuiCouvent++;
                }
                break;
            case RENARD:
                if(nbPoulesQuiCouvent > 0)
                {
                    nbOeufsDisponible++;
                    nbPoulesQuiCouvent--;
                }
                break;
            case COQ: 
                mancheFinie = true;
                break;
        }
        if(mancheFinie)
        {
            break;
        }
        //ihm->attendre(TEMPS_AFFICHAGE_CARTE);
    }
}

void JeuPoulePoule::finirManche()
{
    #ifdef DEBUG
        cout << "Nombre d'oeuf(s) disponible(s) : " << nbOeufsDisponible << endl;
        cout << "Nombre d'oeuf(s) couvé(s) : " << nbPoulesQuiCouvent << endl;
    #endif

    ihm->afficherQuestionFinDeManche();
    if(ihm->getReponseJoueurNbOeufs() == nbOeufsDisponible)
    {
        ++nbPoints;
        if (nbPoints == 3)
        {
            gagnerManche();
        }
        ihm->afficherBravo();
    }
    else
        revoirPartie();
}

void JeuPoulePoule::gagnerManche()
{
    ihm->afficherGagnerManche();
    nbPoints = 0;
    mancheFinie = false;
}

void JeuPoulePoule::revoirPartie()
{
    reinitialiserValeurs();
    mancheFinie = false;
    ihm->afficherMauvaiseReponse();
    char reponseQuestion = '\0';
    ihm->afficherRevoirPartie();
    cin >> reponseQuestion;

    if(reponseQuestion == 'o')
    {
        for(vector<TypeCarte>::iterator it=cartes.begin(); it!=cartes.end(); ++it)
        {
            indenterNumCarte();
            switch(*it)
            {
                    case OEUF:
                    ihm->afficherCarte(OEUF);
                    nbOeufsDisponible++;
                    break;
                case POULE:
                    ihm->afficherCarte(POULE);
                    if(nbOeufsDisponible > 0)
                    {
                        nbOeufsDisponible--;
                        nbPoulesQuiCouvent++;
                    }
                    break;
                case RENARD:
                    ihm->afficherCarte(RENARD);
                    if(nbPoulesQuiCouvent > 0)
                    {
                        nbOeufsDisponible++;
                        nbPoulesQuiCouvent--;
                    }
                    break;
                case COQ:
                    ihm->afficherCarte(COQ);
                    mancheFinie = true;
                    break;
            }
            if(mancheFinie)
            {
                ihm->afficherNbTotalOeufs();
                break;
            }
            ihm->afficherNbTotalOeufsActuel();
        }
    }
}

void JeuPoulePoule::indenterNumCarte()
{
    ++numCarte;
}

void JeuPoulePoule::reinitialiserValeurs()
{
    numCarte = 0;
    reponseJoueur = 0;
    nbOeufsDisponible = 0;          
    nbPoulesQuiCouvent = 0;
}

// accesseur(s)
unsigned int JeuPoulePoule::getNbOeufs() const
{
    return nbOeufsDisponible;
}

unsigned int JeuPoulePoule::getNbPoints() const
{
    return nbPoints;
}

unsigned int JeuPoulePoule::getNbManche() const
{
    return nbManche;
}

unsigned int JeuPoulePoule::getNumCarte() const
{
    return numCarte;
}

unsigned int JeuPoulePoule::getNbOeufsDisponible() const
{
    return nbOeufsDisponible;
}

// mutateur(s)
void JeuPoulePoule::setNbOeufs(unsigned int nbOeufs)
{
    this->nbOeufsDisponible = nbOeufs;
}

void JeuPoulePoule::setNbPoints(unsigned int nbPoints)
{
    this->nbPoints = nbPoints;
}

void JeuPoulePoule::setNbManche(unsigned int nbManche)
{
    this->nbManche = nbManche;
}