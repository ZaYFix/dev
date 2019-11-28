#ifndef PARALLELEPIPEDE_H
#define PARALLELEPIPEDE_H

#include <cmath>
#include <string>
#include "Rectangle.h"

using namespace std;

class Parallelepipede : public Rectangle
{
   protected:
      double largeur;
      double longueur;
      double hauteur;
      
   public:
      Parallelepipede(double largeur, double longueur, double hauteur, double x = 0, double y = 0) 
      : Rectangle(x, y, 0), largeur(largeur), longueur(longueur), hauteur(hauteur) {}
      ~Parallelepipede() {}
      double perimetre()   { return Figure::perimetre(); }
      double aire()        { return (2*(longueur*largeur+longueur*hauteur+largeur*hauteur)); }
      double volume()      { return (longueur*largeur*hauteur);}
      string toString();
};

#endif
