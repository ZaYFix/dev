#include "humain.h"

// Constructeurs et Destructeur
Humain::Humain(const string nom/*=""*/, const string boissonFavorite/*="eau"*/) : nom(nom), boissonFavorite(boissonFavorite)
{
}

Humain::~Humain()
{
}

// Accesseurs
string Humain::getNom() const
{
   return nom;
}

string Humain::getBoissonFavorite() const
{
   return boissonFavorite;
}

void Humain::setBoissonFavorite(const string nouvelleBoissonFavorite)
{
   this->boissonFavorite = nouvelleBoissonFavorite;
}


// Services
void Humain::parle(const string texte) const
{
   cout << "(" << nom << ") -- " << texte << endl;
}

void Humain::sePresente() const
{
   cout << "(" << nom << ") -- " << "Bonjour, je suis " << this->getNom() << " et j'aime le " << this->getBoissonFavorite() << endl;
}

void Humain::boit() const
{
   cout << "(" << nom << ") -- " << "Ah ! un bon verre de " << getBoissonFavorite() << " ! GLOUPS !" << endl;
}
