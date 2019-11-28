#ifndef HUMAIN_H
#define HUMAIN_H

#include <iostream>
#include <string>

using namespace std;

class Humain
{
   public:
      // Constructeur
      Humain(const string nom="", const string boissonFavorite="eau");
      ~Humain();
      
      void sePresente() const;
      void boit() const;

      // Accesseurs
      string getNom() const;
      string getBoissonFavorite() const; // cf. remarque
      void setBoissonFavorite(const string nouvelleBoissonFavorite);

      // Services
      void parle(const string texte) const;
      // Remarque : une méthode qui ne modifie pas l'objet doit être déclarée const

   private:
      string nom;
      string boissonFavorite;
};

#endif // HUMAIN_H
