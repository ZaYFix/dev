#include <iostream>
using namespace std;

#include "Joueur.h"
#include "Carte.h"
#include "JeuPoulePoule.h"
#include "IHM.h"

int main()
{
    Joueur joueur;
    joueur.setNomJoueur("Theo");
    cout << joueur.getNomJoueur() << endl;
    return 0;
}