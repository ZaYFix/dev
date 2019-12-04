#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>
#include <string>
#include "Cercle.h"

using namespace std;

class Sphere : public Cercle 
{
   protected:
      int rayon;
      
   public:
      Sphere(int rayon, double x = 0, double y = 0)
      : Cercle(x, y, 0), rayon(rayon) {}
      ~Sphere() {}
      double perimetre()    { return 0; }
      double aire()         { return (4*M_PI*pow(rayon,2)); }
      double volume()       { return ((4*M_PI*pow(rayon,3))/3); }
      string description(t_desc type);
      string toString();
};

#endif
