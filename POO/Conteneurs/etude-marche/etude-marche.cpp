#include <iostream>
#include <vector>

#define NB_PERSONNES_MAX 1000
#define NB_PRODUIT_PREFERE_MAX 10

using namespace std;

int main()
{
    int nbPersonnes = 0;
    int numeroProduit = 0;
    int plusGrandNumeroSaisie = 0;
    
    do
    {
        cin >> nbPersonnes;
    } while(nbPersonnes > NB_PERSONNES_MAX);
    
    vector<int> produitPreferes(NB_PRODUIT_PREFERE_MAX, 0);
    
    for(int i =0;i<nbPersonnes;i++)
    {
        cin >> numeroProduit;
        
        if (numeroProduit > NB_PRODUIT_PREFERE_MAX)
        {
            cout << "Produit introuvable" << endl;
        }
        
        produitPreferes[numeroProduit] = produitPreferes[numeroProduit] + 1;
        
        if(numeroProduit > plusGrandNumeroSaisie)
        {
            plusGrandNumeroSaisie = numeroProduit;
        }
    }
    
    cout << endl;
    
    for(int i=0; i <= plusGrandNumeroSaisie;i++)
    {
        cout << produitPreferes[i] << endl;
    }
     
    return 0;   
}
