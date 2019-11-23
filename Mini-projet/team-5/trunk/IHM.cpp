#include "IHM.h"
#include <ctime> // pour avoir le temps
#include <stdlib.h> // pour clear la fenêtre
#include <iostream> // pour cout et cin

using namespace std;

IHM::IHM(JeuPoulePoule *jeuPoulePoule): jeuPoulePoule(jeuPoulePoule), reponseJoueurNbOeufs(0), reponseQuestion('\0')
{

}

IHM::~IHM()
{

}

void IHM::afficherNomJeu() const
{
    cout << " `7MM```Mq.   .g8``8q. `7MMF'   `7MF'`7MMF'      `7MM```YMM      `7MM```Mq.   .g8``8q. `7MMF'   `7MF'`7MMF'      `7MM```YMM\n";
    cout << "   MM   `MM..dP'    `YM. MM       M    MM          MM    `7        MM   `MM..dP'    `YM. MM       M    MM          MM    `7\n";
    cout << "   MM   ,M9 dM'      `MM MM       M    MM          MM   d          MM   ,M9 dM'      `MM MM       M    MM          MM   d\n";
    cout << "   MMmmdM9  MM        MM MM       M    MM          MMmmMM          MMmmdM9  MM        MM MM       M    MM          MMmmMM\n";
    cout << "   MM       MM.      ,MP MM       M    MM      ,   MM   Y  ,       MM       MM.      ,MP MM       M    MM      ,   MM   Y  ,\n";
    cout << "   MM       `Mb.    ,dP' YM.     ,M    MM     ,M   MM     ,M       MM       `Mb.    ,dP' YM.     ,M    MM     ,M   MM     ,M\n";
    cout << " .JMML.       ``bmmd`'    `bmmmmd`'  .JMMmmmmMMM .JMMmmmmMMM     .JMML.       ``bmmd`'    `bmmmmd`'  .JMMmmmmMMM .JMMmmmmMMM\n";
    cout << "                                                                                                                        v"<<VERSION<<"\n";
}

void IHM::afficherRegles() const
{
    cout << "Tout d'abord, voici les règles : \n";
    cout << endl;
    cout << "Le Maître de Poule Poule (MPP) sera l'ordinateur durant toute la durée du jeu.\n";
    cout << "Le MPP va empiler les cartes, une par une, les unes sur les autres au centre de la table.\n"; 
    cout << "Une fois posées, ces cartes composeront le Film. Pendant ce temps, le joueur devra compter les Œufs !\n";
    cout << "Voici les cartes disponibles pour ce niveau 1 : 15 Œufs, 10 Poules et 10 Renards et un coq.\n";
    cout << endl;
    cout << "Quand un oeuf arrive dans le film : c'est un oeuf disponible." << endl;
    cout << "Quand une poule arrive et qu'un oeuf est disponible, l'oeuf devient indisponible." << endl;
    cout << "Quand un renard arrive après une poule, il la chasse et l'oeuf redevient alors disponible." << endl;
    cout << "Lorsqu'un coq arrive, la partie est finie, indiquez le nombre d'oeuf disponible. \n";
    cout << "Vous remportez 1 point par bonne réponse et gagnez la manche au bout de 3 points." << endl << endl;
}

void IHM::afficherCarte(TypeCarte typeCarte, bool afficheNumeroCarte) const
{    
    cout << " * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << " *                                           *\n";
    cout << " *                                           *\n";
    switch (typeCarte)
    {
    case POULE:        
        cout << " *          ,~.                              *\n";
        cout << " *       ,-'__ `-,                           *\n";
        cout << " *      {,-'  `. }              ,')          *\n";
        cout << " *     ,( a )   `-.__         ,',')~,        *\n";
        cout << " *    <=.) (         `-.__,==' ' ' '}        *\n";
        cout << " *        ')                        /)       *\n";
        cout << " *          \\   ,                    )       *\n";
        cout << " *           |  \\       `~.         /        *\n";
        cout << " *           \\   `._        \\      /         *\n";
        cout << " *            \\     `._____,'    ,'          *\n";
        cout << " *             `-.             ,'            *\n";
        cout << " *                `-._     _,-'              *\n";
        cout << " *                    77jj'                  *\n";
        cout << " *                   //_||                   *\n";
        cout << " *                __//--'/`                  *\n";
        cout << " *              ,--'/`  '                    *\n";
        cout << " *                                           *\n";
        break;    
    case OEUF:        
        cout << " *                  ████████                 *\n";
        cout << " *                ██        ██               *\n";              
        cout << " *              ██            ██             *\n";             
        cout << " *            ██                ██           *\n";               
        cout << " *            ██                ██           *\n";               
        cout << " *          ██                    ██         *\n";               
        cout << " *          ██                    ██         *\n";               
        cout << " *        ██                        ██       *\n";               
        cout << " *        ██                        ██       *\n";               
        cout << " *        ██                        ██       *\n";               
        cout << " *        ██                        ██       *\n";               
        cout << " *          ██                    ██         *\n";               
        cout << " *          ██                    ██         *\n";               
        cout << " *            ██                ██           *\n";               
        cout << " *              ████        ████             *\n";               
        cout << " *                  ████████                 *\n";
        cout << " *                                           *\n";
        break;
    case RENARD:        
        cout << " *              ,-.      .-,                 *\n";
        cout << " *              |-.\\ __ /.-|                 *\n";
        cout << " *              \\  `    `  /                 *\n";
        cout << " *              / _     _  \\                 *\n";
        cout << " *              | _`q  p _ |                 *\n";
        cout << " *              '._=/  \\=_.'                 *\n";
        cout << " *                |`\\()/` `\\                 *\n";
        cout << " *                |         \\                *\n";
        cout << " *                |         \\                *\n";
        cout << " *                \\ ,--,   .- \\              *\n";
        cout << " *                |-'    '/    \\             *\n";
        cout << " *                | | | | |     ;            *\n";
        cout << " *                | | |.;.,..__ |            *\n";
        cout << " *              .-"";`           `|            *\n";
        cout << " *             /    |           /            *\n";
        cout << " *             `-../____,..---'`             *\n";
        cout << " *                                           *\n";        
        break;    
    case COQ:
        cout << " *                                           *\n"; 
        cout << " *                                           *\n"; 
        cout << " *                                           *\n"; 
        cout << " *         ___//             ________        *\n";
        cout << " *        /@_ \\            / / / _/ \\        *\n";
        cout << " *        ~ O\\ \\_         | /_/_/ _//\\       *\n";
        cout << " *          o \\  \\________/// / //__/'''     *\n";
        cout << " *             |  \\           ___/           *\n";
        cout << " *             \\_ \\___________/              *\n";
        cout << " *                 \\___    __/               *\n";
        cout << " *                     \\  /                  *\n";
        cout << " *                     || |                  *\n";
        cout << " *                     || |                  *\n";
        cout << " *                   _/_/|\\_                 *\n";
        cout << " *                                           *\n"; 
        cout << " *                                           *\n"; 
        cout << " *                                           *\n"; 
        break;
    default:
        break;
    }
    if(!afficheNumeroCarte)
    {
        if (this->jeuPoulePoule->getNumCarte() > NB_MAX_POUR_UN_CARACTERE_ESPACE)
        {
            //on retire un caractère d'espace 
            cout << " *                   - " << this->jeuPoulePoule->getNumCarte() << " -                  *\n";
        }
        else
        {
            cout << " *                   - " << this->jeuPoulePoule->getNumCarte() << " -                   *\n";
        }
    }
    else
    {
        cout << " *                                           *\n";
    }
    cout << " *                                           *\n";
    cout << " * * * * * * * * * * * * * * * * * * * * * * *\n";
}

void IHM::effacerIHM() const
{
    system("clear");
}

void IHM::afficherExemple()
{
    this->effacerIHM();
    this->afficherCarte(OEUF, true);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();
    this->afficherCarte(RENARD, true);
    cout << endl << "Il n'y a pas de poule, le renard passe son chemin." << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();
    this->afficherCarte(OEUF, true);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();
    this->afficherCarte(POULE, true);
    cout << endl << "Il y a 2 oeufs disponibles, donc la poule couvre 1 oeuf, il ne reste qu'un oeuf disponible." << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();
    this->afficherCarte(OEUF, true);
    cout << endl << "Il y a 2 oeufs disponibles." << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();
    this->afficherCarte(POULE, true);
    cout << endl << "Il y a 2 oeufs disponibles, la poule en couvre 1 , il n'en reste qu'un." << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();
    this->afficherCarte(RENARD, true);
    cout << endl << "Il y a des poules, le renard chasse une poule, un oeuf est maintenant disponible." << endl;
    cout << "Il y a donc 2 oeufs disponibles." << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();
    cout << "Vous êtes prêts ? C'est parti !" << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
}

void IHM::attendre(unsigned int tempsAffichageDefini) const
{
    unsigned long int tempsReel = time(NULL);
    unsigned long int tempsAffichage = tempsReel + tempsAffichageDefini;

    while(tempsAffichage > tempsReel)
    {
        tempsReel = time(NULL);
    }
}

void IHM::afficherBienvenue() const
{
    cout << "Bonjour et bienvenue ! ";
}

void IHM::afficherQuestionExemple()
{
    cout << "Voulez-vous un exemple ? (o/n)" << endl;
    this->setReponseQuestion();
    while(!(reponseQuestion == 'o' ) || !(reponseQuestion == 'n' ))
    {
        if (reponseQuestion == 'o')
        {
            afficherExemple();
            break;
        }
        if (reponseQuestion == 'n')
        {
            break;
        }
        else
        {
            afficherValeurIncorrecte();
            afficherQuestionExemple();
        }       
    }
}

void IHM::afficherGagnerManche() const
{
    cout << "Bravo "/*TODO << joueur->getNomJoueur()*/ << " ! Vous avez comptabilité 3 points, vous avez donc gagné une manche !" << endl;
}

void IHM::afficherQuestionFinDeManche()
{
    cout << "Combien y'a t'il d'oeuf(s) disponible(s) ?" << endl;
    cin >> reponseJoueurNbOeufs;
}

void IHM::afficherBravo() const
{
    cout << "Bravo " /*TODO<< jeuPoulePoule->getNomJoueur()*/ << " vous avez gagné !" << endl;
}

void IHM::afficherMauvaiseReponse() const
{
    cout << "Mauvaise réponse." << endl;
}

void IHM::afficherRevoirPartie() const
{
    cout << "Voulez vous revoir la partie "/*TODO << joueur->getNomJoueur()*/" ? (o/n)" << endl;
}

void IHM::afficherNbTotalOeufs() const
{
    cout << endl;
    cout << "Donc il y a au total " << jeuPoulePoule->getNbOeufsDisponible() << " oeuf(s)." << endl;
}

void IHM::afficherNbTotalOeufsActuel() const
{
    cout << endl;
    cout << "Il y a " << jeuPoulePoule->getNbOeufsDisponible() << " oeuf(s)." << endl;
    cout << endl;
}

void IHM::afficherValeurIncorrecte() const
{
    cout << "Valeur incorrecte ! Veuillez réessayer." << endl;
}

// accesseur(s)
char IHM::getReponseQuestion() const
{
    return this->reponseQuestion;
}

unsigned int IHM::getReponseJoueurNbOeufs() const
{
    return this->reponseJoueurNbOeufs;
}

// mutateur(s)
void IHM::setReponseQuestion()
{
    cin >> reponseQuestion;
    this->reponseQuestion = reponseQuestion;
}