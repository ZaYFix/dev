#include <iostream>

#define COLONNES_MAX 80
#define LIGNES_MAX 43

using namespace std;

void afficheMotif(int nbColonne, int nbLigne, char motif)
{
    for(int i=1; i<= nbColonne * nbLigne;i++)
    {
        cout << motif;
        if((i % nbLigne) == 0)
        {
            cout << endl;
        }
    }
}

int main() 
{
    int nbColonne = 0;
    int nbLigne = 0;
    char motif;
    
    cin >> nbColonne;
    cin >> nbLigne;
    cin >> motif;
    
    while((nbColonne > COLONNES_MAX) || (nbLigne > LIGNES_MAX))
    {
        cin >> nbColonne;
        cin >> nbLigne;
        cin >> motif;
    }
    afficheMotif(nbColonne, nbLigne, motif);
    
    return 0;
}


