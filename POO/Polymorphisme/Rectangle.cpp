#include "Rectangle.h"

#include <sstream>
#include <string>

using namespace std;

string Rectangle::description(t_desc type)
{
   string desc;
   if(type == courte)
   {
      desc = "Rectangle";
   }
   else if(type == longue)
   {
      ostringstream oss;
      desc = Figure::description(type) + " <|- Rectangle\n";
      desc += "{\n";
      desc += "\tx = "; oss << x; desc += oss.str() + "\n";
      desc += "\ty = "; oss.str(""); oss << y; desc += oss.str() + "\n";
      desc += "\tz = "; oss.str(""); oss << z; desc += oss.str() + "\n";
      desc += "\tlongueur = "; oss.str(""); oss << longueur; desc += oss.str() + "\n";
      desc += "\tlargeur = "; oss.str(""); oss << largeur; desc += oss.str() + "\n";
      desc += "}\n";
   }
   else
   {
      desc = "";
   }
   return desc;
}

string Rectangle::toString() 
{
   ostringstream oss;
   oss << longueur << " " << largeur;
   return Figure::toString() + " " + oss.str();
}
