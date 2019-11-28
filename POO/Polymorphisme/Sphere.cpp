#include "Sphere.h"

#include <sstream>
#include <string>

using namespace std;

string Sphere::toString() 
{
   ostringstream oss;
   oss << rayon;
   return Figure::toString() + " " + oss.str();
}
