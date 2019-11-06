#include <iostream>
#include <iomanip>

using namespace std;

#include "Article.h"
#include "Ligne.h"

int main() 
{  
   cout << "Itération 1 : " << endl; 
 
   /* Question 1 */
   /*
   cout << "Question 1 : " << endl; 
   Article a1; // un article   
   a1.setTitre("Le Trone de fer, tome 14");
   a1.setPrix(12.);
   cout << "Titre de l'article : " << a1.getTitre() << endl;
   cout << "Prix  de l'article : " << a1.getPrix() << endl;
   
   // un autre article
   Article a2("A Game of Thrones - Le Trône de fer, tome 1", 13.29);
   cout << "Titre de l'article : " << a2.getTitre() << endl;
   cout << "Prix  de l'article : " << a2.getPrix() << endl;   
   cout << endl;
   */
   
   /*
    * Vous devez obtenir :
    * Titre de l'article : Le Trone de fer, tome 14
    * Prix  de l'article : 12
    * Titre de l'article : A Game of Thrones - Le Trône de fer, tome 1
    * Prix  de l'article : 13.29
    * 
    */

   /* Question 2 */
   /*
   cout << "Question 2 : " << endl;
   Ligne l1; // une ligne vide   
   
   cout << "Quantité commandée pour cette ligne de commande : " << l1.getQuantite() << endl;
   cout << endl;
   */
   
   /*
    * Vous devez obtenir :
    * Quantité commandée pour cette ligne de commande : 0
    * 
    */
   
   
   /* Question 3 */  
   /*
   cout << "Question 3 : " << endl; 
   Ligne l2; // une autre ligne
   l2.setArticle(&a2);
   l2.setQuantite(3);
   cout << "Quantité commandée pour cette ligne de commande : " << l2.getQuantite() << endl;
   cout << "Titre de l'article : " << l2.getArticle()->getTitre() << endl;
   cout << "Prix  de l'article : " << l2.getArticle()->getPrix() << endl;
   cout << "Total pour cette ligne : " << l2.getMontant() << endl;
   
   Article a3("Le Trône de fer, Tome 13 : Le Bûcher d'un roi", 17.96);       
   Ligne l3(&a3, 0);
   cout << "Quantité commandée pour cette ligne de commande : " << l3.getQuantite() << endl;
   cout << "Titre de l'article : " << l3.getArticle()->getTitre() << endl;
   cout << "Prix  de l'article : " << l3.getArticle()->getPrix() << endl;
   cout << "Total pour cette ligne : " << l3.getMontant() << endl;
   cout << endl;
   */
   
   /*
    * Vous devez obtenir :
    * Quantité commandée pour cette ligne de commande : 3
    * Titre de l'article : A Game of Thrones - Le Trone de fer, tome 1
    * Prix  de l'article : 13.29
    * Total pour cette ligne : 39.87
    * Quantité commandée pour cette ligne de commande : 0
    * Titre de l'article : Le Trone de fer, Tome 13 : Le Bucher d'un roi
    * Prix  de l'article : 17.96
    * Total pour cette ligne : 0
    * 
    */
   
   
   /* Question 4 */
   /*
   cout << "Question 4 : " << endl; 

   l1.setArticle(&a1);
   l1.setQuantite(2);
   
   cout << setfill(' ') << setw(3) << "Qte"; 
   cout << "|" << setfill(' ') << setw(50) << "Description"; 
   cout << "|" << setfill(' ') << setw(8) << "Prix uni"; 
   cout << "|" << setfill(' ') << setw(15) << "Total\n";
   cout << setfill('-') << setw(80) << "\n";
   
   // on affiche les 3 lignes de la commande
   l1.afficher();
   cout << endl;
   l2.afficher();
   cout << endl;
   l3.afficher();
   cout << endl;
   cout << endl;
   */
   
   /*
    * Vous devez obtenir :
    * Qte|                                       Description|Prix uni|         Total
    * -------------------------------------------------------------------------------
    *   2|..........................Le Trone de fer, tome 14|      12|      24 euros
    *   3|.......A Game of Thrones - Le Trone de fer, tome 1|   13.29|   39.87 euros
    *   0|.....Le Trone de fer, Tome 13 : Le Bucher d'un roi|   17.96|       0 euros
    * 
    */ 

   return 0;
}
