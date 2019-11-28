#include "Triangle.h"

#include <sstream>
#include <string>

using namespace std;

string Triangle::description(t_desc type)
{
   string desc;
   if(type == courte)
   {
      desc = "Triangle";
   }
   else if(type == longue)
   {
      ostringstream oss;
      desc = Figure::description(type) + " <|- Triangle\n";
      desc += "{\n";
      desc += "\tx = "; oss << x; desc += oss.str() + "\n";
      desc += "\ty = "; oss.str(""); oss << y; desc += oss.str() + "\n";
      desc += "\tz = "; oss.str(""); oss << z; desc += oss.str() + "\n";
      desc += "\tbase = "; oss.str(""); oss << base; desc += oss.str() + "\n";
      desc += "\thauteur = "; oss.str(""); oss << hauteur; desc += oss.str() + "\n";
      desc += "}\n";
   }
   else
   {
      desc = "";
   }
   return desc;
}

string Triangle::toString() 
{
   ostringstream oss;
   oss << base << " " << hauteur;
   return Figure::toString() + " " + oss.str();
}

