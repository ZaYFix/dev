#ifndef HUMAIN_H
#define HUMAIN_H

#include <iostream>
#include <string>

using namespace std;

class Humain
{
   public:
      // Constructeurs et Destructeur
      Humain(const string nom="", const string boissonFavorite="eau");
      ~Humain();

      // Accesseurs
      string getNom() const;
      string getBoissonFavorite() const;
      void setBoissonFavorite(const string nouvelleBoissonFavorite);

      // Services
      void parle(const string texte) const;
      void sePresente() const;
      void boit() const;

   protected:
      string nom;
      string boissonFavorite;
};

#endif // HUMAIN_H
