#include <iostream>
#include <stack>
using namespace std;

typedef enum
{
AUCUN = 0,
GAUCHE = 1,
DROITE = 2,
DROIT = 3,
HAUT = 4,
BAS = 5
} Deplacement;

// Pour réaliser une saisie d’un Deplacement avec cin
std::istream& operator>>(std::istream& is, Deplacement& d)
{
int tmp ;
if(is >> tmp)
d = static_cast<Deplacement>(tmp);
return is ;
}
int main()
{
    Deplacement deplacement;
    stack<Deplacement> historiqueDeplacements;
    
    do { 
        cin >> deplacement;
        historiqueDeplacements.push(deplacement);
    } while(deplacement != 0);
    
    while(!historiqueDeplacements.empty())
    {
        switch(historiqueDeplacements.top())
        {
            case GAUCHE:
                deplacement = DROITE;
                break;
            case DROITE:
                deplacement = GAUCHE;
                break;
            case DROIT:
                deplacement = DROIT;
                break;
            case HAUT:
                deplacement = BAS;
                break;
            case BAS:
                deplacement = HAUT;
                break;
            default: 
                deplacement = AUCUN;
                break;
        }
        
        if(deplacement != 0)
        {
            cout << deplacement << endl;
        }
        
        historiqueDeplacements.pop();
    }
return 0;
}
