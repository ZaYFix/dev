#include <iostream>
#include <iomanip>
#include "Temps.h"

using namespace std;

// Constructeurs

Temps::Temps():valeur(0)
{
    
}
Temps::Temps(long secondes): valeur(secondes)
{
    
}

Temps::Temps(int heure, int minute, int seconde): valeur((heure * PASSAGE_SECONDE_HEURE) + (minute * PASSAGE_SECONDE_MINUTE) +seconde)
{
    
}

Temps::Temps(const Temps &t): valeur(t.valeur)
{
    
} 

// Accesseurs

int  Temps::getSeconde() const
{
    int secondes = valeur % 60 ;
    return secondes;
}

int  Temps::getMinute() const
{
    int minutes = (valeur/PASSAGE_SECONDE_MINUTE) % 60 ;
    return minutes;
}

int  Temps::getHeure() const
{
    int heures = (valeur/PASSAGE_SECONDE_HEURE) % 60 ;
    return heures;
}

long Temps::getValeur() const
{
    return valeur;
}


// Surcharge opérateur d'affectation

Temps& Temps::operator =(const Temps &t)
{
    valeur = t.valeur;
    return *this;
}

// Surcharges opérateurs arithmétiques

Temps& Temps::operator ++()
{
    ++valeur ;
    return *this;
}
Temps& Temps::operator --()
{
    --valeur;
    return *this;
}

Temps& Temps::operator += (const Temps &t)
{
    valeur += t.valeur;
    return *this;   
}

Temps& Temps::operator += (const long nombre )
{
    valeur += nombre ;
    return *this;
}

Temps& Temps::operator -= (const long nombre )
{
    valeur -= nombre ;
    return *this;
}

Temps& Temps::operator -=(const Temps &t)
{
    valeur -= t.valeur;   
    return *this;
}

Temps  operator +(const Temps &t2, const Temps &t3)
{
    return t2.valeur + t3.valeur;
}

Temps operator -(const Temps &t2 , const Temps &t3)
{
    return t2.valeur - t3.valeur;
}

// Surcharges opérateurs de comparaison

bool Temps::operator ==(const Temps &t)
{
    if (valeur == t.valeur)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

bool Temps::operator !=(const Temps &t)
{
    if (valeur != t.valeur)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

// Surcharge opérateurs de flux
ostream & operator << ( ostream & sortie, const Temps &t)
{
     sortie << setfill('0') << setw(2) << t.getHeure() << ":" << setfill('0') << setw(2) << t.getMinute() << ":" << setfill('0') << setw(2) << t.getSeconde();
    
    return sortie;
}

istream & operator >> ( istream & entree, Temps &t)
{
    char c;
    long valeur = 0;
    long minutes = 0;
    long secondes = 0;
    
    entree >> valeur;

    if ((c = entree.get()) != ':') 
    {
        t.valeur = valeur;
        entree.putback(c);
        return entree;
    }
    else
    {
        entree >> minutes;
        t.valeur = (valeur * PASSAGE_SECONDE_HEURE) + (minutes * PASSAGE_SECONDE_MINUTE);
        if((c = entree.get()) != ':')
        {
            entree.putback(c);
            return entree;
        }
        else
        {               
             entree >> secondes;
             t.valeur = ((valeur * PASSAGE_SECONDE_HEURE) + (minutes * PASSAGE_SECONDE_MINUTE) + secondes);
             return entree; 
            
        }
    }
}
