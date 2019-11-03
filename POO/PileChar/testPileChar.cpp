/*
 * Le but est de tester progressivement l'implémentation d'une structure de pile pouvant traiter des char.
 * 
 */

#include <iostream>

using namespace std;

#include "PileChar.h"

int main() 
{
   /* Question 1 */
   cout << "Question 1 :\n";
   PileChar pile1(10);
   cout << endl;
   
   /* Question 2 */   
   cout << "Question 2 :\n";
   PileChar pile2;
   cout << endl;
    
   /* Question 3 */   
   cout << "Question 3 :\n";
   PileChar pile3a;
   PileChar pile3b(20);
   PileChar* pile3c = new PileChar(30);
   delete pile3c;
   cout << endl;

   /* Question 4 */   
   cout << "Question 4 :\n"; 
   PileChar pile4(5);
   
   pile4.depiler();
   
   pile4.empiler('h');
   pile4.empiler('e');
   pile4.empiler('l');
   pile4.empiler('l');   
   pile4.empiler('o');   
   pile4.empiler(' ');   
   pile4.empiler('!');   
   
   cout << "Contenu de pile4 : "; pile4.afficher();
   cout << "Nombre d'éléments présents sur pile4 : " << pile4.compter() << endl;
   cout << "Taille de pile4 : " << pile4.taille() << endl;
   
   char c = pile4.depiler();
   cout << "Caractère dépilé : " << c << endl;
   cout << "Contenu de pile4 : "; pile4.afficher();
   cout << "Nombre d'éléments présents sur pile4 : " << pile4.compter() << endl;
   cout << endl;
   
   /* Question 5 */   
   cout << "Question 5 :\n";
   PileChar pile5a(pile4); // Appel du constructeur de copie pour instancier pile5a
   PileChar pile5b = pile1; // Appel du constructeur de copie pour instancier pile5b
   
   cout << "Contenu de pile5a : "; pile5a.afficher();
   cout << "Nombre d'éléments présents sur pile5a : " << pile5a.compter() << endl;
   cout << "Taille de pile5a : " << pile5a.taille() << endl;
   
   cout << "Contenu de pile5b : "; pile5b.afficher();
   cout << "Nombre d'éléments présents sur pile5b : " << pile5b.compter() << endl;
   cout << "Taille de pile5b : " << pile5b.taille() << endl;
   cout << endl;
   
   /* Question 6 */   
   cout << "Question 6 :\n";
   PileChar pile6; // Appel du constructeur par défaut pour créer pile6
  
   pile6 = pile4; // Appel de l'opérateur d'affectation pour copier pile4 dans pile6
   
   pile6.empiler('o');   
   
   cout << "Contenu de pile6 : "; pile6.afficher();
   cout << "Nombre d'éléments présents sur pile6 : " << pile6.compter() << endl;
   cout << "Taille de pile6 : " << pile6.taille() << endl;
   cout << endl;
   
   /* Question 7 */   
   cout << "Question 7 :\n";
   PileChar pile7;
   
   pile7.empiler('s');
   pile7.empiler('o');
   pile7.empiler('l');
   pile7.empiler('e');
   pile7.empiler('i');
   pile7.empiler('l');
   cout << "Contenu de pile7 : "; pile7.afficher();
   cout << "Contenu inverse de pile7 : "; affiche_inverse(pile7);
   cout << "Contenu de pile7 : "; pile7.afficher();
   cout << endl;
   
   /* Question 8 */   
   cout << "Question 8 :\n";
   PileChar pile8a("Bonjour");  // chaine C

   cout << "Contenu de pile8a : "; pile8a.afficher();
   cout << "Nombre d'éléments présents sur pile8a : " << pile8a.compter() << endl;
   cout << "Taille de pile8a : " << pile8a.taille() << endl;
   cout << "Contenu inverse de pile8a : "; affiche_inverse(pile8a);

   string message = "Hello world";
   PileChar pile8b(message); // chaine C++
   
   cout << "Contenu de pile8b : "; pile8b.afficher();
   cout << "Nombre d'éléments présents sur pile8b : " << pile8b.compter() << endl;
   cout << "Taille de pile8b : " << pile8b.taille() << endl;
   cout << "Contenu inverse de pile8b : "; affiche_inverse(pile8b);
   cout << endl;

   return 0;
}
