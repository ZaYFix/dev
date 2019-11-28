#include "Cube.h"

#include <sstream>
#include <string>

using namespace std;

string Cube::toString() 
{
   ostringstream oss;
   oss << largeur;
   return Figure::toString() + " " + oss.str();
}
