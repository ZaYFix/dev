#include <iostream>
using namespace std;

#include "Joueur.h"
#include "JeuPoulePoule.h"
#include "IHM.h"

int main()
{
    IHM ihm;
    Joueur joueur;
    JeuPoulePoule jpp;

    string nomJoueur;

    ihm.afficherRegles();
    cout << "Veuillez saisir votre nom : ";
    cin >> nomJoueur;
    joueur.setNomJoueur(nomJoueur);
    cout << "Votre nom est : " << joueur.getNomJoueur() << endl;

    jpp.jouer();
    return 0;
}