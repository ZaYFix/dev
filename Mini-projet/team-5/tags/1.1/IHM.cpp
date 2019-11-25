#include "IHM.h"
#include <stdlib.h>
#include <iostream>

#define NB_MAX_POUR_UN_CARACTERE_ESPACE 9

using namespace std;

IHM::IHM(JeuPoulePoule *jeuPoulePoule): jeuPoulePoule(jeuPoulePoule)
{

}

void IHM::introduction() const
{
    cout << " `7MM```Mq.   .g8``8q. `7MMF'   `7MF'`7MMF'      `7MM```YMM      `7MM```Mq.   .g8``8q. `7MMF'   `7MF'`7MMF'      `7MM```YMM\n";
    cout << "   MM   `MM..dP'    `YM. MM       M    MM          MM    `7        MM   `MM..dP'    `YM. MM       M    MM          MM    `7\n";
    cout << "   MM   ,M9 dM'      `MM MM       M    MM          MM   d          MM   ,M9 dM'      `MM MM       M    MM          MM   d\n";
    cout << "   MMmmdM9  MM        MM MM       M    MM          MMmmMM          MMmmdM9  MM        MM MM       M    MM          MMmmMM\n";
    cout << "   MM       MM.      ,MP MM       M    MM      ,   MM   Y  ,       MM       MM.      ,MP MM       M    MM      ,   MM   Y  ,\n";
    cout << "   MM       `Mb.    ,dP' YM.     ,M    MM     ,M   MM     ,M       MM       `Mb.    ,dP' YM.     ,M    MM     ,M   MM     ,M\n";
    cout << " .JMML.       ``bmmd`'    `bmmmmd`'  .JMMmmmmMMM .JMMmmmmMMM     .JMML.       ``bmmd`'    `bmmmmd`'  .JMMmmmmMMM .JMMmmmmMMM\n";
    cout << "                                                                                                                        v1.1\n";
}

void IHM::afficherRegles() const
{
    cout << "Bonjour et bienvenue sur le Jeu « Poule Poule » !\n"; 
    cout << "Tout d'abord, voici les règles : \n";
    cout << "Le Maître de Poule Poule (MPP) sera l'ordinateur durant toute la durée du jeu.\n";
    cout << "Le MPP va empiler les cartes, une par une, les unes sur les autres au centre de la table.\n"; 
    cout << "Une fois posées, ces cartes composeront le Film. Pendant ce temps, le joueur devra juste \n";
    cout << "compter les Œufs !\n";
    cout << "Voici les cartes disponibles pour ce niveau 1 : 15 Œufs, 10 Poules et 10 Renards et un coq.\n";
    cout << endl;
    cout << "Quand un oeuf arrive dans le film : c'est un oeuf disponible." << endl;
    cout << "Quand une poule arrive et qu'un oeuf est disponible, l'oeuf devient indisponible" << endl;
    cout << "Quand un renard arrive après une poule, il la chasse et l'oeuf redevient alors disponible" << endl;
    cout << "Lorsqu'un coq arrive, la partie est finie, indiquez le nombre d'oeuf disponible. \n";
    cout << "Vous remportez 1 point par bonne réponse et gagnez la manche au bout de 3 points" << endl << endl;
}

void IHM::afficherCarte(TypeCarte typeCarte, bool exemple)
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
    if(!exemple)
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
    this->attendre();
    this->effacerIHM();
    this->afficherCarte(RENARD, true);
    cout << endl << "Il n'y a pas de poule, le renard passe son chemin." << endl << endl;
    this->attendre();
    this->attendre();
    this->effacerIHM();
    this->afficherCarte(OEUF, true);
    this->attendre();
    this->effacerIHM();
    this->afficherCarte(POULE, true);
    cout << endl << "Il y a 2 oeufs disponibles, donc la poule couvre 1 oeuf, il ne reste qu'un oeuf disponible." << endl << endl;
    this->attendre();
    this->attendre();
    this->effacerIHM();
    this->afficherCarte(OEUF, true);
    cout << endl << "Il y a 2 oeufs disponibles." << endl << endl;
    this->attendre();
    this->attendre();
    this->effacerIHM();
    this->afficherCarte(POULE, true);
    cout << endl << "Il y a 2 oeufs disponibles, la poule en couvre 1 , il n'en reste qu'un." << endl << endl;
    this->attendre();
    this->attendre();
    this->effacerIHM();
    this->afficherCarte(RENARD, true);
    cout << endl << "Il y a des poules, le renard chasse une poule, un oeuf est maintenant disponible." << endl;
    cout << "Il y a donc 2 oeufs disponibles." << endl;
    this->attendre();
    this->attendre();
    this->attendre();
    this->effacerIHM();
}

void IHM::attendre() const
{
    unsigned long int temps = time(NULL);
    unsigned long int tempsAffichage = temps + TEMPS_AFFICHAGE_CARTE;
    cin.clear();

    while(tempsAffichage > temps)
    {
        temps = time(NULL);
    }
}
