#include "JeuPoulePoule.h"
#include "Joueur.h"
#include "IHM.h"

#include <algorithm> // pour random_shuffle
#include <iostream> // pour les cout des debug

using namespace std;


// constructeur(s) et destructeur(s)
JeuPoulePoule::JeuPoulePoule(unsigned int nbCarteOeuf, unsigned int nbCartePoule, unsigned int nbCarteRenard, unsigned int nbCarteCoq, unsigned int nbCarteChien, \
unsigned int nbCarteCanard,unsigned int nbCarteVer,unsigned int nbPoints,unsigned int nbManche, bool mancheFinie, unsigned int nbOeufsDisponible, \
unsigned int nbPoulesQuiCouvent, unsigned int nbChienDansBasseCour, unsigned int numCarte):nbCarteOeuf(15),nbCartePoule(10),nbCarteRenard(10), \
nbCarteCoq(1),nbCarteCanard(2),nbCarteChien(2),nbCarteVer(2),nbPoints(0),nbManche(1),mancheFinie(false),nbOeufsDisponible(0), nbPoulesQuiCouvent(0), \
nbChienDansBasseCour(0),nbVerDansBasseCour(0),numCarte(0)
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
    ihm->demanderNom();
    ihm->effacerIHM();
    jouer();
    finirManche();
}

void JeuPoulePoule::creerPaquet()
{
    ajouterCarteOeuf();
    ajouterCartePoule();
    ajouterCarteRenard();
    ajouterCarteCoq();
    ajouterCarteChien();
    ajouterCarteCanard();
    ajouterCarteVer();
}

void JeuPoulePoule::ajouterCarteOeuf()
{
    for (int i = 0; i < nbCarteOeuf; ++i)
    {
        cartes.push_back(OEUF);
    }
}

void JeuPoulePoule::ajouterCartePoule()
{
    for (int i = 0; i < nbCartePoule; ++i)
    {
        cartes.push_back(POULE);
    }
}

void JeuPoulePoule::ajouterCarteRenard()
{
    for (int i = 0; i < nbCarteRenard; ++i)
    {
        cartes.push_back(RENARD);
    }
}

void JeuPoulePoule::ajouterCarteCoq()
{
    for (int i = 0; i < nbCarteCoq; ++i)
    {
        cartes.push_back(COQ);
    }
}

void JeuPoulePoule::ajouterCarteChien()
{
    for (int i = 0; i < nbCarteChien; ++i)
    {
        cartes.push_back(CHIEN);
    }
}

void JeuPoulePoule::ajouterCarteCanard()
{
    for(int i = 0; i < nbCarteCanard; ++i)
    {
        cartes.push_back(CANARD);
    }  
}

void JeuPoulePoule::ajouterCarteVer()
{
    for(int i = 0; i < nbCarteVer; ++i)
    {
        cartes.push_back(VER);
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
    #ifdef DEBUG
    cout << "Cartes:" << endl;
    for(vector<TypeCarte>::iterator it=cartes.begin(); it!=cartes.end(); ++it)
    {
        cout << *it;
    }
    cout << endl;
    #endif
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
                if (nbVerDansBasseCour > 0)
                {
                    nbVerDansBasseCour--;
                    break;
                }
                if(nbOeufsDisponible > 0)
                {
                    nbOeufsDisponible--;
                    nbPoulesQuiCouvent++;
                }
                break;
            case RENARD:
                if(nbChienDansBasseCour > 0)
                {
                    nbChienDansBasseCour--;
                    break;
                }
                if(nbPoulesQuiCouvent > 0)
                {
                    nbOeufsDisponible++;
                    nbPoulesQuiCouvent--;
                }
                break;
            case COQ: 
                mancheFinie = true;
                break;
            case CHIEN:
                nbChienDansBasseCour++;
                break;
            case CANARD:
                break;
            case VER:
                nbVerDansBasseCour++;
                break;
        }
        #ifdef DEBUG
            cout << "Nombre d'oeuf(s) disponible(s) : " << nbOeufsDisponible << endl;
            cout << "Nombre d'oeuf(s) couvé(s) : " << nbPoulesQuiCouvent << endl;
            cout << "Nombre de chien(s) dans la basse cour : " << nbChienDansBasseCour << endl;
            cout << "Nombre de ver de terre dans la basse cour : " << nbVerDansBasseCour << endl;
        #endif
        if(mancheFinie)
        {
            break;
        }
        #ifndef DEBUG
        ihm->attendre(TEMPS_AFFICHAGE_CARTE);
        #endif
    }
}

void JeuPoulePoule::rejouer()
{
    viderVecteur();
    jouer();
    finirManche();
}

void JeuPoulePoule::finirManche()
{
    ihm->afficherQuestionFinDeManche();
    if(ihm->getReponseJoueurNbOeufs() == nbOeufsDisponible)
    {
        ++nbPoints;
        if (nbPoints == NOMBRE_DE_MANCHE)
        {
            gagnerPartie();
            exit(0);
        }
        gagnerManche();
    }
    else
        revoirPartie();
}

void JeuPoulePoule::gagnerManche()
{
    ihm->afficherBravoManche();
    reinitialiserValeurs();
    viderVecteur();
    rejouer();
}

void JeuPoulePoule::gagnerPartie()
{
    ihm->afficherGagnerPartie();
    reinitialiserNbPoint();
    reinitialiserValeurs();
}

void JeuPoulePoule::revoirPartie()
{
    ihm->afficherMauvaiseReponse();
    reinitialiserValeurs();
    char reponseQuestion = '\0';
    ihm->afficherRevoirPartie();
    cin >> reponseQuestion;

    if(reponseQuestion == 'o')
    {
        for(vector<TypeCarte>::iterator it=cartes.begin(); it!=cartes.end(); ++it)
        {
            indenterNumCarte();
            ihm->afficherCarte(*it);
            switch(*it)
            {
                case OEUF:
                    nbOeufsDisponible++;
                    break;
                case POULE:
                    if (nbVerDansBasseCour > 0)
                    {
                        nbVerDansBasseCour--;
                        break;
                    }
                    if(nbOeufsDisponible > 0)
                    {
                        nbOeufsDisponible--;
                        nbPoulesQuiCouvent++;
                    }
                    break;
                case RENARD:
                    if(nbChienDansBasseCour > 0)
                    {
                        nbChienDansBasseCour--;
                        break;
                    }
                    if(nbPoulesQuiCouvent > 0)
                    {
                        nbOeufsDisponible++;
                        nbPoulesQuiCouvent--;
                    }
                    break;
                case COQ: 
                    mancheFinie = true;
                    break;
                case CHIEN:
                    nbChienDansBasseCour++;
                    break;
                case CANARD:
                    break;
                case VER:
                    nbVerDansBasseCour++;
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
    nbOeufsDisponible = 0;
    nbPoulesQuiCouvent = 0;
    nbChienDansBasseCour = 0;
    nbVerDansBasseCour = 0;
    mancheFinie = false;
}

void JeuPoulePoule::reinitialiserNbPoint()
{
    nbPoints = 0;
}

void JeuPoulePoule::viderVecteur()
{
    cartes.clear();
}

// accesseur(s)
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