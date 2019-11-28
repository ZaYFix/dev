#include "dame.h"

// Constructeur
Dame::Dame(const string nom/*=""*/, const string boissonFavorite/*="lait"*/, const string couleurRobe/*="blanche"*/) : Humain(nom, boissonFavorite), couleurRobe(couleurRobe), etat("libre")
{
}

// Accesseurs
string Dame::getNom() const
{
   return "Miss " + nom;
}

string Dame::getEtat() const
{
   return etat;
}

// Services
void Dame::sePresente() const
{
   cout << "(" << nom << ") -- " << "Bonjour, je suis " << this->getNom() << " et j'ai une jolie robe " << couleurRobe << endl;
}

void Dame::changeDeRobe(const string couleurRobe)
{
   this->couleurRobe = couleurRobe;
   cout << "(" << nom << ") -- " << "Regardez ma nouvelle robe " << couleurRobe << " !" << endl;
}
