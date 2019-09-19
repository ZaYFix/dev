#include <iostream>

#define SOMME 's'
#define PRODUIT 'p'

using namespace std;

int main() 
{
    int premierNombre = 0;
    int deuxiemeNombre = 0;
    int resultatCalcul = 0;
    char operateur;
    
    cin >> premierNombre >> deuxiemeNombre >> operateur;
    
    switch(operateur)
    {
        case SOMME :
            resultatCalcul = premierNombre + deuxiemeNombre;
            cout << resultatCalcul << endl;
            break;
            
        case PRODUIT :
            resultatCalcul = premierNombre * deuxiemeNombre;
            cout << resultatCalcul << endl;
            break;
            
        default:
            cout << "Désolé, je ne connais pas cette opération ! " << endl;
    }
    return 0;
}
