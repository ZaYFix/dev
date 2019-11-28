#include "Cercle.h"

#include <sstream>
#include <string>

using namespace std;

string Cercle::toString() 
{
   ostringstream oss;
   oss << rayon;
   return Figure::toString() + " " + oss.str();
}
