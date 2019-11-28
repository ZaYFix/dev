#include "Carre.h"

#include <sstream>
#include <string>

using namespace std;

string Carre::description(t_desc type)
{
   string desc;
   if(type == courte)
   {
      desc = "Carré";
   }
   else if(type == longue)
   {
      ostringstream oss;
      desc = Figure::description(type) + " <|- Carre\n";
      desc += "{\n";
      desc += "\tx = "; oss << x; desc += oss.str() + "\n";
      desc += "\ty = "; oss.str(""); oss << y; desc += oss.str() + "\n";
      desc += "\tz = "; oss.str(""); oss << z; desc += oss.str() + "\n";
      desc += "\tlargeur = "; oss.str(""); oss << largeur; desc += oss.str() + "\n";
      desc += "}\n";
   }
   else
   {
      desc = "";
   }
   return desc;
}

string Carre::toString() 
{
   ostringstream oss;
   oss << largeur;
   return Figure::toString() + " " + oss.str();
}
