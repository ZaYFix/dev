#include "Cube.h"

#include <sstream>
#include <string>

using namespace std;

string Cube::description(t_desc type)
{
   string desc;
   if(type == courte)
   {
      desc = "Cube";
   }
   else if(type == longue)
   {
      ostringstream oss;
      desc = Figure::description(type) + " <|- Cube\n";
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

string Cube::toString() 
{
   ostringstream oss;
   oss << largeur;
   return Figure::toString() + " " + oss.str();
}
