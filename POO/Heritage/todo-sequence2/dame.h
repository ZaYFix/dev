#ifndef DAME_H
#define DAME_H

#include <iostream>
#include <string>
#include "humain.h"

using namespace std;

class Dame : public Humain
{
   public:
      // Constructeur
      Dame(const string nom="", const string boissonFavorite="lait", const string couleurRobe="blanche");

      // Accesseurs
      string getNom() const;
      string getEtat() const;

      // Services
      void sePresente() const;
      void changeDeRobe(const string couleurRobe);

   private:
      string couleurRobe;
      string etat;
};

#endif // DAME_H
