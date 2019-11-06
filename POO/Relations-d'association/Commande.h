#ifndef COMMANDE_H
#define COMMANDE_H

#include <iostream>

using namespace std;

class Commande
{
   private:
      string reference;
      string date;

   public:
      Commande(string reference="", string date="");

      string getReference() const;
      void setReference(string reference);
      string getDate() const;
      void setDate(string date);

      void saisir();
};

#endif //COMMANDE_H
