#include <iostream>

#define COLONNES_MAX 80
#define LIGNES_MAX 43

using namespace std;

void afficheMotif(int nbColonne, int nbLigne, char motif)
{
    for(int i=0; i<nbColonne;i++)
    {
        for(int j=0; j<nbLigne;j++)
        {
            cout << motif;
        }
        cout << "" << endl;
    }
}

int main() 
{
    int nbColonne = 0;
    int nbligne = 0;
    char motif;
    
    cin >> nbColonne;
    cin >> nbligne;
    cin >> motif;
    
    while((nbColonne > COLONNES_MAX) || (nbligne > LIGNES_MAX))
    {
        cin >> nbColonne;
        cin >> nbligne;
        cin >> motif;
    }
    afficheMotif(nbColonne, nbligne, motif);
    
    return 0;
}

