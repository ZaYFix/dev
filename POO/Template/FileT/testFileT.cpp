#include <iostream>
#include <exception>
#include "FileT.h"

using namespace std;

int main()
{
   FileT<int> file1;

   try
   {
      file1 + 8;
      file1.affiche();

      file1 + 9;
      file1.affiche();

      file1 + 2;
      -file1;
      file1.affiche();

      file1 + 5;
      file1 + 6;
      file1.affiche();

      -file1;
      file1 + 1;
      file1.affiche();
   }
   catch (exception &e)
   {
      cerr << "Erreur : " << e.what() << endl;
   }

   FileT<char> file2;

   try
   {
      file2 + '8';
      file2.affiche();

      file2 + '9';
      file2.affiche();

      file2 + '2';
      -file2;
      file2.affiche();

      file2 + '5';
      file2 + '6';
      file2.affiche();

      -file2;
      file2 + '1';
      file2.affiche();
   }
   catch (exception &e)
   {
      cerr << "Erreur : " << e.what() << endl;
   }

   return 0;
}
