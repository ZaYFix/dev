#include "Sphere.h"

#include <sstream>
#include <string>

using namespace std;

string Sphere::description(t_desc type)
{
   string desc;
   if(type == courte)
   {
      desc = "Sphère";
   }
   else if(type == longue)
   {
      ostringstream oss;
      desc = Figure::description(type) + " <|- Sphère\n";
      desc += "{\n";
      desc += "\tx = "; oss << x; desc += oss.str() + "\n";
      desc += "\ty = "; oss.str(""); oss << y; desc += oss.str() + "\n";
      desc += "\tz = "; oss.str(""); oss << z; desc += oss.str() + "\n";
      desc += "\trayon = "; oss.str(""); oss << rayon; desc += oss.str() + "\n";
      desc += "}\n";
   }
   else
   {
      desc = "";
   }
   return desc;
}

string Sphere::toString() 
{
   ostringstream oss;
   oss << rayon;
   return Figure::toString() + " " + oss.str();
}
