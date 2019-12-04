#ifndef CUBE_H
#define CUBE_H

#include <cmath>
#include <string>
#include "Carre.h"

using namespace std;

class Cube : public Carre 
{
   protected:
      double largeur;
      
   public:
      Cube(double largeur, double x = 0, double y = 0)
      : Carre(x, y, 0), largeur(largeur) {}
      ~Cube() {}
      double perimetre()    { return 0; }
      double aire()         { return 6*(largeur * largeur); }
      double volume()       { return pow(largeur,3); }
      string description(t_desc type);
      string toString();
};

#endif
