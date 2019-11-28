#ifndef FIGURE_H
#define FIGURE_H

#include <string>

using namespace std;

typedef enum {courte, longue} t_desc;

class Figure 
{
   protected:
      double x, y, z; //coordonnées du centre
      
   public:
      Figure(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
      virtual ~Figure() {}
      virtual double perimetre()   { return 0; }
      virtual double aire()        { return 0; }
      virtual double volume()      { return 0; }
      virtual string description(t_desc type) { return "Figure"; }
      virtual string toString();
};

#endif
