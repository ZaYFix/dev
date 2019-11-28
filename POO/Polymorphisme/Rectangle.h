#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <cmath>
#include <string>
#include "Carre.h"

using namespace std;

class Rectangle : public Carre
{
   protected:
      double largeur;
      double longueur;
      
   public:
      Rectangle(double largeur, double longueur, double x = 0, double y = 0) 
      : Carre(x, y, 0), largeur(largeur), longueur(longueur) {}
      ~Rectangle() {}
      double perimetre()   { return 2*(largeur+longueur); }
      double aire()        { return largeur * longueur; }
      string toString();
};

#endif
