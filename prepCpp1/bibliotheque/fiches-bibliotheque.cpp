#include <iostream>
#include <stdio.h>
#include <limits>

#define CHAR_MAX 64

using namespace std;

int main() 
{
    int nbFicheCorriger = 0;
    char nomAuteur[CHAR_MAX];
    char lettreManquante;
    int positionLettre = 0;
    
    cin >> nbFicheCorriger;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for(int i=0;i < nbFicheCorriger; i++)
    {
        scanf("%63[^\n]s", nomAuteur);
        cin >> lettreManquante;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cin >> positionLettre;
        cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        positionLettre = positionLettre-1;
        
        for ( int j = CHAR_MAX; j > positionLettre ; j--)
        {
            nomAuteur[i] = nomAuteur[i-1];
        }
        nomAuteur[positionLettre] = lettreManquante;
        cout << nomAuteur << endl;
    }
    return 0;
}
