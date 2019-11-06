#include <iostream>
#include <iomanip>

using namespace std;

#include "Client.h"
#include "Commande.h"
#include "Ligne.h"
#include "Article.h"

int main() 
{
   cout << "Itération 3 : " << endl; 

   /* Question 8 */
   /*
   cout << "Question 8 : " << endl; 
   Client unClient;
   
   unClient.setNom("VAIRA");
   unClient.setNumero(1);
   cout << "Nom du client : " << unClient.getNom() << endl;
   cout << "Référence du client : " << unClient.getNumero() << endl;
   
   Client unBonClient("DURAND", 2);
   cout << "Nom du client : " << unBonClient.getNom() << endl;
   cout << "Référence du client : " << unBonClient.getNumero() << endl;
   cout << endl;   
   */

   /* Question 9, 10 et 11 */
   /*
   cout << "Question 9, 10 et 11 : " << endl; 
   
   //unClient.afficher();
   
   Commande commande("A00004", "09/10/2014");   
   Article a2("A Game of Thrones - Le Trone de fer, tome 2", 13.29), a3("Le Trone de fer, Tome 13 : Le Bucher d'un roi", 17.96);
   
   commande.ajouterLigneArticle(&a2, 2);
   commande.ajouterLigneArticle(&a3, 1);
   
   // réalise l'association dans le sens Client -> Commande   
   unClient.passeUneCommande(&commande); 
   
   // dans l'autre sens : Commande -> Client
   commande.estPasseeParUnClient(&unClient);
   
   commande.afficher();   
   cout << endl;
   */
    
   return 0;
}
