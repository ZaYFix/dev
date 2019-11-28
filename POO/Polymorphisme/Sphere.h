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
      : Figure(x, y, 0), rayon(rayon) {}
      ~Sphere() {}
      double perimetre()    { return Figure::perimetre(); }
      double aire()         { return (pow(rayon,2)*M_PI); }
      string toString();
};

#endif
