#ifndef CERCLE_H
#define CERCLE_H

#include <cmath>
#include <string>
#include "Figure.h"

using namespace std;

class Cercle : public Figure 
{
   protected:
      int rayon;
      
   public:
      Cercle(int rayon, double x = 0, double y = 0)
      : Figure(x, y, 0), rayon(rayon) {}
      ~Cercle() {}
      double perimetre()    { return (2*M_PI*rayon); }
      double aire()         { return (pow(rayon,2)*M_PI); }
      string toString();
};

#endif
