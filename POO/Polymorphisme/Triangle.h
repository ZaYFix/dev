#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <string>
#include "Figure.h"

using namespace std;

class Triangle : public Figure 
{
   protected:
      double base, hauteur;
      
   public:
      Triangle(double base, double hauteur, double x = 0, double y = 0)
      : Figure(x, y, 0), base(base), hauteur(hauteur) {}
      ~Triangle() {}
      double perimetre()   { return sqrt(base * base + hauteur * hauteur) + base + hauteur; }
      double aire()        { return base * hauteur / 2; }
      double volume()      { return 0;}
      string description(t_desc type);
      string toString();
};

#endif
