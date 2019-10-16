#ifndef TEMPS_H
#define TEMPS_H

#define PASSAGE_SECONDE_HEURE   3600
#define PASSAGE_SECONDE_MINUTE  60 

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
        Temps(const Temps &t);
        
        int  getSeconde() const;
        int  getMinute() const;
        int  getHeure() const;
        long getValeur() const;
       
        // Surcharge opérateur d'affectation
        Temps& operator =(const Temps &t);
       
        // Surcharges opérateurs arithmétiques
        Temps& operator ++(); 
        Temps& operator --(); 
        
        Temps& operator +=(const Temps &t);        
        Temps& operator +=(const long nombre);
        Temps& operator -=(const Temps &t);
        Temps& operator -=(const long nombre);
        
        friend Temps operator +(const Temps &t2, const Temps &t3); 
        friend Temps operator -(const Temps &t2 , const Temps &t3); 
        
        // Surcharges opérateurs de comparaison
        bool operator ==(const Temps &t);
        bool operator !=(const Temps &t);
        
        // Surcharge opérateurs de flux
        friend ostream & operator <<(ostream & sortie, const Temps &t);
        friend istream & operator >>(istream & entree, Temps &t);
};

#endif //TEMPS_H
