#include <iostream>
#include <iomanip>

using namespace std;

#include "Point.h"

int main() 
{
   /* Question 1 */
   
   cout << "Question 1 : constructeur par défaut" << endl;   
   Point p0;
   

   /* Question 2 */ 
   
   cout << "Question 2 : constructeur" << endl;   
   Point p1(1., 2.);
   Point p2(4., 0.);
   
    
   /* Question 3 */  
   
   cout << "Question 3 : accesseurs et mutateurs" << endl;   
   cout.precision(2);

   cout << "L'abscisse de p0 est " << p0.getX() << endl;   
   cout << "L'abscisse de p1 est " << p1.getX() << endl;
   cout << "L'abscisse de p1 est " << p2.getX() << endl;
   cout << endl; 
   
   cout << "L'ordonnée de p0 est " << p0.getY() << endl;   
   cout << "L'ordonnée de p1 est " << p1.getY() << endl;
   cout << "L'ordonnée de p1 est " << p2.getY() << endl;
   cout << endl; 

   p0.setX(5.5);
   cout << "L'abscisse de p0 est maintenant " << p0.getX() << endl;   
   p0.setY(6.5);
   cout << "L'ordonnée de p0 est maintenant " << p0.getY() << endl;   
   cout << endl; 
   
   
   /* Question 4 */
   
   cout << "Question 4 : allocation dynamique" << endl;   
   Point *p3; // je suis pointeur non initialisé sur un objet de type Point
   p3 = new Point(2. , 2.); // j'alloue dynamiquement un objet de type Point
   
   // Comme p3 est une adresse, je dois utiliser l'opérateur -> pour accéder aux membres de cet objet
   cout << "L'abscisse de p3 est " << p3->getX() << endl;   
   p3->setY(0); // je modifie la valeur de l'attribut y de p3
   (*p3).setY(1); // cette écriture est possible : je pointe l'objet puis j'appelle sa méthode
   cout << "L'ordonnée de p3 est " << p3->getY() << endl;
   cout << "L'adresse de p3 est " << p3 << endl;
   delete p3; // ne pas oublier de libérer la mémoire allouée pour cet objet
   p3 = NULL;
   cout << endl; 
   
    
   /* Question 5 */
   
   cout << "Question 5 : tableau d'objets" << endl;   
   Point tableauDe10Points[10]; // typiquement : les cases d’un tableau de Point
   
   cout << "Un tableau de 10 Point : " << endl;
   for(int i = 0; i < 10; i++)
   {
      cout << "P" << i << " = <" << tableauDe10Points[i].getX() << "," << tableauDe10Points[i].getY() << ">\n";
   }
   cout << endl; 
   
    
   /* Question 6 */
   
   cout << "Question 6 : objet constant" << endl;   
   const Point p4(7., 8.);
   cout << "L'abscisse de p4 est " << p4.getX() << endl;
   //p4.setX(5.); // essayez quand même !
   cout << "L'ordonnée de p4 est " << p4.getY() << endl;      
   cout << endl; 
   
    
   /* Question 7 */ 
   
   cout << "Question 7 : rendre des services" << endl;   
   cout << "p0 = ";
   p0.affiche();
   cout << "p1 = ";
   p1.affiche();
   cout << "p2 = ";
   p2.affiche();
   //cout << "p3 = "; 
   //p3->affiche(); // essayez quand même !!
   cout << "p4 = ";
   p4.affiche();
   cout << endl;
   
   
   /* Question 8 */
   /*
   cout << "Question 8 : calcul de la distance entre 2 points" << endl;   
   double distance = p1.distance(p2);
   cout << "La distance entre p1 et p2 est de " << distance << endl;
   cout << endl;
   */
   
   /* Question 9 */
   /*
   cout << "Question 9 : calcul le point milieu entre 2 points" << endl;   
   Point pointMilieu = p1.milieu(p2);   
   cout << "Le point milieu entre p1 et p2 est "; 
   pointMilieu.affiche();
   cout << endl;
   */
   
   /* Question 10 */
   
   cout << "Question 10 : destructeur" << endl;      
   cout << endl;
   
   
   return 0;
}
