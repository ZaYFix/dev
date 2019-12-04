#ifndef CARRE_H
#define CARRE_H

#include <cmath>
#include <string>
#include "Figure.h"

using namespace std;

class Carre : public Figure 
{
   protected:
      double largeur;
      
   public:
      Carre(double largeur, double x = 0, double y = 0)
      : Figure(x, y, 0), largeur(largeur) {}
      ~Carre() {}
      double perimetre()   { return largeur * 4; }
      double aire()        { return largeur * largeur; }
      double volume()      { return 0;}
      string description(t_desc type);
      string toString();
};

#endif
