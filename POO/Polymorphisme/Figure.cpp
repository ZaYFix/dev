#include "Figure.h"

#include <sstream>
#include <string>

using namespace std;

string Figure::toString() 
{
   ostringstream oss;
   oss << x << " " << y << " " << z;
   return oss.str();
}
