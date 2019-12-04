#include "Parallelepipede.h"

#include <sstream>
#include <string>

using namespace std;

string Parallelepipede::description(t_desc type)
{
   string desc;
   if(type == courte)
   {
      desc = "Parallélépipède";
   }
   else if(type == longue)
   {
      ostringstream oss;
      desc = Figure::description(type) + " <|- Parallélépipède\n";
      desc += "{\n";
      desc += "\tx = "; oss << x; desc += oss.str() + "\n";
      desc += "\ty = "; oss.str(""); oss << y; desc += oss.str() + "\n";
      desc += "\tz = "; oss.str(""); oss << z; desc += oss.str() + "\n";
      desc += "\tdx = "; oss.str(""); oss << dx; desc += oss.str() + "\n";
      desc += "\tdy = "; oss.str(""); oss << dy; desc += oss.str() + "\n";
      desc += "\tlongueur = "; oss.str(""); oss << longueur; desc += oss.str() + "\n";
      desc += "\tlargeur = "; oss.str(""); oss << largeur; desc += oss.str() + "\n";
      desc += "\thauteur = "; oss.str(""); oss << hauteur; desc += oss.str() + "\n";
      desc += "}\n";
   }
   else
   {
      desc = "";
   }
   return desc;
}

string Parallelepipede::toString() 
{
   ostringstream oss;
   oss << longueur << " " << largeur << " " << hauteur << " " << dx << " " << dy;
   return Figure::toString() + " " + oss.str();
}
