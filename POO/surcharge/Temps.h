#ifndef TEMPS_H
#define TEMPS_H

#include <iostream>
using namespace std;

class Temps
{
    private:
        long valeur;
   
    public:
        Temps();
        Temps(long secondes);
        Temps(int heure, int minute, int seconde);
        
        int  getSeconde() const;
        int  getMinute() const;
        int  getHeure() const;
        long getValeur() const;
        
        friend ostream & operator << (ostream & sortie, const Temps &t);
};

#endif //TEMPS_H
