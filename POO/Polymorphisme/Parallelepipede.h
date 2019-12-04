#ifndef PARALLELEPIPEDE_H
#define PARALLELEPIPEDE_H

#include <cmath>
#include <string>
#include "Rectangle.h"

using namespace std;

class Parallelepipede : public Rectangle
{
   protected:
      double largeur, longueur, hauteur;
      int dx, dy;
      
   public:
      Parallelepipede(double largeur, double longueur, double hauteur, double x = 0, double y = 0) 
      : Rectangle(x, y, 0), largeur(largeur), longueur(longueur), hauteur(hauteur), dx(0), dy(0) {}
      ~Parallelepipede() {}
      double perimetre()   { return 0; }
      double aire()        { return (2*(longueur*largeur+longueur*hauteur+largeur*hauteur)); }
      double volume()      { return (longueur*largeur*hauteur);}
      string description(t_desc type);
      string toString();
};

#endif
