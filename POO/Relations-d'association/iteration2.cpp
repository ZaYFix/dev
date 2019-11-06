#include <iostream>
#include <iomanip>

using namespace std;

#include "Commande.h"
#include "Ligne.h"
#include "Article.h"

int main() 
{
   cout << "Itération 2 : " << endl;
   
   /* Question 5 */
   /*
   cout << "Question 5 : " << endl;   
   Commande c1; // une commande
   c1.setReference("A00001");
   c1.setDate("10/04/2013");
   cout << "Référence de la commande : " << c1.getReference() << endl;
   cout << "Date de la commande      : " << c1.getDate() << endl;
   
   Commande c2("A00002", "11/04/2013"); // une autre commande
   cout << "Référence de la commande : " << c2.getReference() << endl;
   cout << "Date de la commande      : " << c2.getDate() << endl;   
   cout << endl;
   */
   
   /* Question 6 */
   /*
   cout << "Question 6 : " << endl; 
   // des articles
   Article gratuit("A Game of Thrones - Le Trone de fer, tome 1");   
   Article a2("A Game of Thrones - Le Trone de fer, tome 2", 13.29);
   Article a3("Le Trone de fer, Tome 13 : Le Bucher d'un roi", 17.96);   
   Commande c3("A00003", "10/04/2013");

   c3.ajouterLigneArticle(&a2, 3);
   c3.ajouterLigneArticle(&a3, 2);
   c3.ajouterLigneArticle(&gratuit, 1);
   
   cout << "Nombre d'articles commandés pour cette commande : " << c3.getNbLignes() << endl;
   cout << "Quantité d'articles commandés pour cette commande : " << c3.getNbArticles() << endl;
   cout << "Montant de la commande : " << c3.getTotal() << endl;
   cout << endl;
   */
   
   /* Question 7 */
   /*
   cout << "Question 7 : " << endl; 
   
   c3.afficher();
   cout << endl;
   */
   
   return 0;
}
