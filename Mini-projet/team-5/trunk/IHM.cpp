#include "IHM.h"
#include <iostream>

using namespace std;

IHM::IHM(TypeCarte typeCarte): typeCarte(typeCarte)
{

}

IHM::IHM():typeCarte(OEUF)
{
    
}

void IHM::afficherRegles() const
{
    cout << "Tout d'abord, le Maître de Poule Poule (MPP) sera l'ordinateur durant toute la durée du jeu.\n";
    cout << "Le MPP va empiler les cartes, une par une, les unes sur les autres au centre de la table.\n"; 
    cout << "Une fois posées, ces cartes composeront le Film. Pendant ce temps, les joueurs devront juste \n";
    cout << "compter les Œufs !\n";
    cout << "Voici les cartes disponible pour ce niveau 1 : 15 Œufs, 10 Poules et 10 Renards et un coq.\n";
    cout << endl;
    cout << "Quand un oeuf arrive dans le film : c'est un oeuf disponible." << endl;
    cout << "Quand une poule arrive et qu'un oeuf est disponible, l'oeuf devient indisponible" << endl;
    cout << "Quand un renard arrive après une poule, il l'a chasse et l'oeuf redevient alors disponible" << endl;
    cout << "Si vous avez compté 5 oeufs disponibles signalez le et vous gagnerez un point, \n";
    cout << "vous gagner la manche au bout de 3 points" << endl << endl;

    cout << "Exemple : " << endl;
    this->afficherCarte(OEUF);
    this->afficherCarte(RENARD);
    cout << endl << "Il n'y a pas de poule, le renard passe son chemin" << endl << endl;
    this->afficherCarte(OEUF);
    this->afficherCarte(POULE);
    cout << endl << "Il y a 2 oeufs disponibles, donc la poule couvre 1 oeuf, il ne reste qu'un oeuf disponible" << endl << endl;
    this->afficherCarte(OEUF);
    cout << endl << "Il y a 2 oeufs disponibles" << endl << endl;
    this->afficherCarte(POULE);
    cout << endl << "Il y a 2 oeufs disponibles, la poule en couvre 1 , il n'en reste qu'un" << endl << endl;
    this->afficherCarte(RENARD);
    cout << endl << "Il y a des poule, le renard chasse une poule, un oeuf est maintenant disponible" << endl;
    cout << "Il y a donc 2 oeufs disponibles" << endl;
}

void IHM::afficherCarte(TypeCarte typeCarte) const
{
    if (typeCarte == POULE)
    {
        cout << " * * * * * * * * * * * * * * * * * * * * * * *\n";
        cout << " *                                           *\n";
        cout << " *                                           *\n";
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
        cout << " *                                           *\n";
        cout << " *                                           *\n";
        cout << " * * * * * * * * * * * * * * * * * * * * * * *\n";
    }
    else
    {
        if (typeCarte == OEUF)
        {
            cout << " * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << " *                                           *\n";
            cout << " *                                           *\n";
            cout << " *                                           *\n";
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
            cout << " *                                           *\n";
            cout << " * * * * * * * * * * * * * * * * * * * * * * *\n";
        }
        else
        {  
            if (typeCarte = RENARD)
            {
                cout << " * * * * * * * * * * * * * * * * * * * * * * *\n";
                cout << " *                                           *\n";
                cout << " *                                           *\n";
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
                cout << " *                                           *\n";
                cout << " *                                           *\n";
                cout << " * * * * * * * * * * * * * * * * * * * * * * *\n";
            }
        }
    }
}

    
