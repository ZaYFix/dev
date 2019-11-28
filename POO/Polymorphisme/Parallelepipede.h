#ifndef PARALLELEPIPEDE_H
#define PARALLELEPIPEDE_H

#include <cmath>
#include <string>
#include "Parallelepipede.h"

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
      double perimetre()   { return 2*(largeur+longueur); }
      double aire()        { return largeur * longueur; }
      string toString();
};

#endif
