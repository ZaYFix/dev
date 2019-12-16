#ifndef _JOUEUR_H
#define _JOUEUR_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class De;

class Joueur 
{
  public:
    Joueur(string nom);

    ~Joueur();

    string getNom() const;

    void setNom(string nom);

    void jouerAuxDes();

  private:
    string nom;

    vector<De*> des;

};
#endif
