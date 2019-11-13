#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

using namespace std;

class Commande;

class Client
{
   private:
      string nom;
      int numero;

      Commande *commande;

   public:
      Client(string nom="", int numero=0);

      void setNom(string nom);
      void setNumero(int numero);

      string getNom() const;
      int getNumero() const;

      void setCommande(Commande *commande);

      void saisir();
};

#endif //CLIENT_H
