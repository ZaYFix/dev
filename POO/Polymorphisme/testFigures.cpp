#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>

using namespace std;

#include "Figure.h"
#include "Triangle.h"
#include "Carre.h"
#include "Cercle.h"
#include "Cube.h"
#include "Parallelepipede.h"
#include "Rectangle.h"
#include "Sphere.h"

int main() 
{
   cout << endl;
   
   Triangle        triangle(5,8); // base, hauteur
   //cout << "Triangle :" << endl;  
   cout << "Je suis un " << triangle.description(courte) << endl;  
   cout << triangle.description(longue);
   cout << "Perimetre = " << triangle.perimetre() << endl;
   cout << "Aire = "      << triangle.aire() << endl;
   cout << "Volume = "    << triangle.volume() << endl << endl;

   Carre           carre(4); // largeur  
   //cout << "Carre :" << endl;  
   cout << "Je suis un " << carre.description(courte) << endl;  
   cout << carre.description(longue);
   cout << "Périmetre = " << carre.perimetre() << endl;
   cout << "Aire = "      << carre.aire() << endl;
   cout << "Volume = "    << carre.volume() << endl << endl;

   Rectangle       rectangle(5, 4); // largeur, longueur
   cout << "Rectangle : " << endl;
   cout << "Périmetre = " << rectangle.perimetre() << endl;
   cout << "Aire = "      << rectangle.aire() << endl;
   cout << "Volume = "    << rectangle.volume() << endl << endl;
   
   Cercle          cercle(2); // rayon
   cout << "Cercle : " << endl;  
   cout << "Périmetre = " << cercle.perimetre() << endl;
   cout << "Aire = "      << cercle.aire() << endl;
   cout << "Volume = "    << cercle.volume() << endl << endl;
   
   Cube            cube(6); // largeur
   cout << "Cube : " << endl;  
   cout << "Périmetre = " << cube.perimetre() << endl;
   cout << "Aire = "      << cube.aire() << endl;
   cout << "Volume = "    << cube.volume() << endl << endl;
   
   Parallelepipede parallelepipede(5, 4, 9); // largeur, longueur, hauteur
   cout << "Parallelepipede : " << endl;  
   cout << "Périmetre = " << parallelepipede.perimetre() << endl;
   cout << "Aire = "      << parallelepipede.aire() << endl;
   cout << "Volume = "    << parallelepipede.volume() << endl << endl;
   
   Sphere          sphere(3); // rayon
   cout << "Sphere : " << endl;  
   cout << "Périmetre = " << sphere.perimetre() << endl;
   cout << "Aire = "      << sphere.aire() << endl;
   cout << "Volume = "    << sphere.volume() << endl << endl;
   
   Figure          *fig;
   list<Figure *>  liste;
   list<Figure *>::iterator iL;   
   fstream *fichier = NULL;
   string  figure;
   int     x, y, z;
   double  base, hauteur, largeur;
   
   liste.push_back(&triangle);
   liste.push_back(&carre);
//   liste.push_back(&rectangle);
//   liste.push_back(&cercle);
//   liste.push_back(&cube);
//   liste.push_back(&parallelepipede);
//   liste.push_back(&sphere);
   
   fichier = new fstream("Figures.txt", fstream::out);
   for (iL = liste.begin(); iL != liste.end(); iL++) 
   {
      fig = *iL;
      *fichier << fig->description(courte) << " " << fig->toString() << endl;
   }   
   fichier->close();
   delete fichier;
   
   fichier = new fstream("Figures.txt", fstream::in);
   *fichier >> figure;
   while (! fichier->eof()) 
   {
      *fichier >> x >> y >> z;
      cout << figure;
      cout << " " << x << " " << y << " " << z;
      if (figure == "Figure")   
         cout << endl;
      if (figure == "Triangle") 
      {
         *fichier >> base >> hauteur;
         cout << " " << base << " " << hauteur << endl;
      }
      if (figure == "Carré") 
      {
         *fichier >> largeur;
         cout << " " << largeur << endl;
      }      
      // if (figure == "Rectangle") 
      // {
      //    *fichier >> largeur >> longueur;
      //    cout << largeur << longueur << endl;
      // }
//       if (figure == "Cercle") 
//       {
//          *fichier >> rayon;
//          cout << rayon << endl;
//       }
//       if (figure == "Cube") 
//       {
//          *fichier >> largeur;
//          cout << largeur << endl;
//       }
//       if (figure == "Parallélépipède") 
//       {
//          *fichier >> largeur >> longueur >> hauteur >> dx >> dy;
//          cout << largeur << longueur << hauteur << dx << dy << endl;
//       }
//       if (figure == "Sphère") 
//       {
//          *fichier >> rayon ;
//          cout << rayon << endl;
//       }
      while (fichier->get() != '\n');
      *fichier >> figure;
   }   
   fichier->close();
   delete fichier;
   
   return 0;
}
