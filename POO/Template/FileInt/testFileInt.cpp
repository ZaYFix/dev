#include <iostream>
#include <exception>
#include "FileInt.h"

using namespace std;

int main() 
{
   FileInt fi;

   try
   {
      fi + 8;
      fi.affiche();

      fi + 9;
      fi.affiche();

      fi + 2;
      -fi;
      fi.affiche();
      
      fi + 5;
      fi + 6;
      fi.affiche();
      
      -fi;
      fi + 1;
      fi.affiche();
   }
   catch (exception & e) 
   {
      cout << "Erreur : " << e.what() << endl;
   }
   
   return 0;
}
