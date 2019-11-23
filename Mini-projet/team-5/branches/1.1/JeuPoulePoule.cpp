#include "JeuPoulePoule.h"
#include "Joueur.h"
#include "IHM.h"

#include <algorithm> // pour random_shuffle
#include <iostream>

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
    ihm->introduction();
    ihm->attendre();
    cout << "Bonjour et bienvenue ! ";
    string reponseQuestion = "\0";
    ihm->afficherRegles();
    cout << "Voulez-vous un exemple ? (o/n)" << endl;
    cin >> reponseQuestion;
    if (reponseQuestion == "o")
    {
        ihm->afficherExemple();
    }
    jouer();
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
    #ifdef DEBUG
    cout << "Cartes non mélangées" << endl;
    for(vector<TypeCarte>::iterator it=cartes.begin(); it!=cartes.end(); ++it)
    {
        cout << *it;
    }
    cout << endl;
    #endif
    srand ( unsigned ( time(0) ) );
    random_shuffle ( this->cartes.begin(), this->cartes.end() );
    random_shuffle ( this->cartes.begin(), this->cartes.end(), chiffre_aleatoire);
    #ifdef DEBUG
    cout << "Cartes mélangées" << endl;
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
    reponseJoueur = 0;
    nbOeufsDisponible = 0;
    nbPoulesQuiCouvent = 0;
    reponseQuestion ='\0';
    for(vector<TypeCarte>::iterator it=cartes.begin(); it!=cartes.end(); ++it)
    {
        ihm->effacerIHM();
        indenterNumCarte();
        switch(*it)
        {
            case OEUF:
                #ifdef DEBUG
                cout << "Oeuf" << endl;
                #endif
                ihm->afficherCarte(OEUF);
                nbOeufsDisponible++;
                break;
            case POULE:
                #ifdef DEBUG
                cout << "Poule" << endl;
                #endif
                ihm->afficherCarte(POULE);

                if(nbOeufsDisponible > 0)
                {
                    nbOeufsDisponible--;
                    nbPoulesQuiCouvent++;
                }
                break;
            case RENARD:
                #ifdef DEBUG
                cout << "Renard" << endl;
                #endif
                ihm->afficherCarte(RENARD);
                if(nbPoulesQuiCouvent > 0)
                {
                    nbOeufsDisponible++;
                    nbPoulesQuiCouvent--;
                }
                break;
            case COQ:
                #ifdef DEBUG
                cout << "Coq" << endl;
                #endif
                ihm->afficherCarte(COQ);
                cout << "Combien y'a t'il d'oeufs disponibles ?" << endl;
                #ifdef DEBUG
                cout << "nbOeufsDisponible : " << nbOeufsDisponible << endl;
                cout << "nbPoulesQuiCouvent : " << nbPoulesQuiCouvent << endl;
                #endif
                cin >> reponseJoueur;
                if(reponseJoueur == nbOeufsDisponible)
                {
                    cout << "Bravo "<< joueur->getNomJoueur() << "! Vous avez gagné !" << endl;
                    mancheFinie = true;
                }
                else
                {
                    cout << "Dommage ! Il y a " << nbOeufsDisponible << " et non pas " << reponseJoueur << " !" << endl;
                    cout << "Voulez vous revoir la partie ? (o/n)" << endl;
                    cin >> reponseQuestion;
                    if (reponseQuestion == "o")
                    {
                        revoirPartie();
                    }
                    mancheFinie = true;
                }
             
            if(mancheFinie)
            {
                cout << "La manche est finie !" << endl;
                exit(0);
            }   
        }
        #ifdef DEBUG
        cout << "nbOeufsDisponible : " << nbOeufsDisponible << endl;
        cout << "nbPoulesQuiCouvent : " << nbPoulesQuiCouvent << endl;
        #endif
        ihm->attendre();
    }
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

void JeuPoulePoule::revoirPartie()
{
    cout << "Revisualisation de la partie" << endl;
    numCarte = 0;
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
            cout << "Donc il y a au total " << nbOeufsDisponible << " oeuf(s)." << endl;
            break;
        }
        cout << "Il y a " << nbOeufsDisponible << " oeuf(s)." << endl;
    }
}

void JeuPoulePoule::indenterNumCarte()
{
    ++numCarte;
}