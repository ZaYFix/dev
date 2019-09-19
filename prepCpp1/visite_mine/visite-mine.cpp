#include <iostream>

#define TOTAL_DEPLACEMENTS_MAX 1000

typedef enum
{
    AUCUN = 0,
    GAUCHE = 1,
    DROITE = 2,
    DROIT = 3,
    HAUT = 4,
    BAS = 5
} Deplacement;

using namespace std;

int main()
{
    int nbDeplacements = 0;
    
    cin >> nbDeplacements;
    
    while(nbDeplacements > TOTAL_DEPLACEMENTS_MAX)
    {
        cin >> nbDeplacements;
    }
    
    int parcours[nbDeplacements];
    
    // Aller
    for(int i=0;i<nbDeplacements;i++)
    {
        cin >> parcours[i];
    }
    
    // Retour
    for(int i=0;i<nbDeplacements;i++)
    {
        switch(parcours[i])
        {
            case GAUCHE:
                cout <<  DROITE << endl;
                break;
            case DROITE:
                cout <<  GAUCHE << endl;
                break;
            case DROIT:
                cout <<  BAS << endl;
                break;
            case HAUT:
                cout << BAS << endl;
                break;
            case BAS:
                cout <<  HAUT << endl;
                break;
        }
    }
    return 0;
}
