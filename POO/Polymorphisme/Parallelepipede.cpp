#include "Parallelepipede.h"

#include <sstream>
#include <string>

using namespace std;

string Parallepepide::toString() 
{
   ostringstream oss;
   oss << largeur;
   return Figure::toString() + " " + oss.str();
}
