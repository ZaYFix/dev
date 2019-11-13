#include <iostream>
#include <iomanip>

using namespace std;

#include "Client.h"
#include "Commande.h"
#include "Ligne.h"
#include "Article.h"

int main() 
{
   /* Question 12 */
   cout << "Question 12 : " << endl; 
   
   Commande uneCommande;   
   Client leClient;
   
   leClient.passeUneCommande(&uneCommande);
    
   uneCommande.saisir();
   
   uneCommande.afficher();   
   
   cout << endl;
    
   return 0;
}
