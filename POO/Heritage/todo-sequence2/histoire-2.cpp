#include <iostream>

using namespace std;

#include "cowboy.h"
#include "dame.h"

/* TP Western C++ n°2 : des cowboys et des dames */

int main()
{
   Cowboy lucky("Lucky Luke","whisky");
   Dame jenny("Jenny");
   
   // 1. La rencontre ...
   lucky.sePresente();
   jenny.sePresente();
   
   // 2. Allons boire un coup ...
   jenny.changeDeRobe("verte");
   lucky.boit();
   jenny.boit();
      
   return 0;
}
