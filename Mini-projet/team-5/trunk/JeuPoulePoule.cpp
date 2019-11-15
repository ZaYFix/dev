#include "JeuPoulePoule.h"

unsigned int JeuPoulePoule::nbOeufsDisponible = 0;
unsigned int JeuPoulePoule::nbPoulesQuiCouvent = 0;

// constructeur et destructeur
JeuPoulePoule::JeuPoulePoule(unsigned int nbCarteOeuf, unsigned int nbCartePoule, unsigned int nbCarteRenard, unsigned int nbCarteCoq, unsigned int nbPoints, unsigned int nbManche):nbCarteOeuf(15), nbCartePoule(10), nbCarteRenard(10), nbCarteCoq(1), nbPoints(0),nbManche(1)
{

}

JeuPoulePoule::~JeuPoulePoule()
{
    
}

// méthode(s)

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
    mancheFinie = false;

    for(vector<TypeCarte>::iterator it=cartes.begin(); it!=cartes.end(); ++it)
    {
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
                cout << "La manche est finie !" << endl;
                cout << "Combien y'a t'il d'oeufs disponibles ?" << endl;
                cin >> reponseJoueur;
                if(reponseJoueur == nbOeufsDisponible)
                {
                    cout << "Bravo ! Vous avez gagné !" << endl;
                    mancheFinie = true;
                }
                else
                {
                    cout << "Dommage ! Il y a " << nbOeufsDisponible << " et non pas " << reponseJoueur << " !" << endl;
                    mancheFinie = true;
                }
                
        }
        #ifdef DEBUG
        cout << "nbOeufsDisponible : " << nbOeufsDisponible << endl;
        cout << "nbPoulesQuiCouvent : " << nbPoulesQuiCouvent << endl;
        #endif
        unsigned long int temps = time(NULL);
        unsigned long int tempsPlus2s = temps + 2;
        cin.clear();

        while(tempsPlus2s > temps)
            {
                temps = time(NULL);
            }

        if(mancheFinie)
        {
            cout << "Fin" << endl;
            exit(0);
        }
    }
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

// accesseurs
unsigned int JeuPoulePoule::getNbOeufs()
{
    return nbOeufsDisponible;
}

unsigned int JeuPoulePoule::getNbPoints()
{
    return nbPoints;
}

unsigned int JeuPoulePoule::getNbManche()
{
    return nbManche;
}

// mutateurs
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