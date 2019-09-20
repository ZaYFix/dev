//==============================================================
// Programme : mastermind
//
// Role :     Jeu du Mastermind
//
// Principe : Saisie d'un code secret
//            Saisie d'un essai et le compare au code secret
//            Affichage du nombre de chiffres bien et mal places
//
// Version : 1.0.1
// Date de creation : 19/09/2019
// Auteur : Ackermann Théo (theoackrm@gmail.com)
// Etablissement : LT LA SALLE Avignon
//
//==============================================================

#include "mastermind.h"

#define REDONDANCE 1
#define TAILLE_CODE 5
#define ESSAIS_MAX 12

// Programme principal
int main() 
{
    // TODO :
    
    // 1. Instancier un objet de type Mastermind en utilisant le constructeur par défaut
    Mastermind mastermind(REDONDANCE, TAILLE_CODE, ESSAIS_MAX);
    
    // Avant de jouer, il est conseillé d'afficher les règles du jeu
    mastermind.usage();
    
    // 2. Implémenter le diagramme de séquence "jouer une manche"
    
    mastermind.choisirSolution();
    
    do
    {
        mastermind.saisirEssai();
        mastermind.verifierEssai();
        mastermind.afficherResultat();
        mastermind.estFinie();
    }
    while (mastermind.estFinie() == false);
    
    return 0;
}

