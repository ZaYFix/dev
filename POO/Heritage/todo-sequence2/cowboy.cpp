#include "cowboy.h"

// Constructeurs et Destructeur
Cowboy::Cowboy(const string nom/*=""*/, const string boissonFavorite/*="whisky"*/, int popularite/*=0*/, string adjectif/*="vaillant"*/)\
: Humain(nom, boissonFavorite), popularite(popularite), adjectif(adjectif)
{

}

Cowboy::~Cowboy()
{

}

string Cowboy::getAdjectif() const
{
    return adjectif;
}

void Cowboy::sePresente() const
{
    cout << "(" << nom << ") -- " << "Bonjour, je suis le " << this->getAdjectif()<< " " << this->getNom() << " et j’aime le " << this->getBoissonFavorite() << endl;
}   