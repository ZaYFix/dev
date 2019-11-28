#ifndef COWBOY_H
#define COWBOY_H

#include <iostream>
#include <string>
#include "humain.h"

using namespace std;

class Cowboy : public Humain
{
    public:
        // Constructeurs et Destructeur
        Cowboy(const string nom="", const string boissonFavorite="whisky", int popularite=0, string adjectif="vaillant");
        ~Cowboy();

        void sePresente() const;
        string getAdjectif() const;

    private:
        int popularite;
        string adjectif;
};

#endif // COWBOY_H
