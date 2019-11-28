#include "Rectangle.h"

#include <sstream>
#include <string>

using namespace std;

string Rectangle::toString() 
{
   ostringstream oss;
   oss << largeur;
   return Figure::toString() + " " + oss.str();
}
