#include "Parallelepipede.h"

#include <sstream>
#include <string>

using namespace std;

string Parallelepipede::toString() 
{
   ostringstream oss;
   oss << largeur;
   return Figure::toString() + " " + oss.str();
}
