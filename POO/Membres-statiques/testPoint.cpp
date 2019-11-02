#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#include "Point.h"

int main() 
{
   Point p0, p1(4, 0.0), p2(2.5, 2.5);
   
   /* Question 1 */
   
   cout << "Question 1 : " << endl; 
   Point *pp = new Point(1,1);
   
   cout << "Il y a " << Point::compte() << " points\n";
   
   delete pp;
   
   cout << "Il y a " << Point::compte() << " points\n";   
   cout << endl;
   
   
   /* Question 2 */
   
   cout << "Question 2 : " << endl; 
   double distance = Point::distance(p1, p2);
   
   cout << "p1 = ";
   p1.affiche();
   cout << "p2 = ";
   p2.affiche();
   cout << "La distance entre p1 et p2 est de " << distance << endl;
   
   Point pointMilieu = Point::milieu(p1, p2);
   cout << "Le point milieu entre p1 et p2 est "; pointMilieu.affiche();
   cout << endl;

   return 0;
}
