#ifndef _JOUEUR_H
#define _JOUEUR_H


#include <string>
using namespace std;
#include <vector>
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
