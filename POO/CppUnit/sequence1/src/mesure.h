#ifndef MESURE_H
#define MESURE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Mesure
{
   public:
      Mesure();
      ~Mesure();
      
      void   reinitialiser();
      
      double getMesure();
      double getMesureMax();
      double getMesureMin();
      
      double getEchantillon(int pos);
      void   ajouterEchantillon(double echantillon); // non utilisé
      void   ajouterEchantillons(vector<double> &t);
      void   ajouterEchantillons(double *t, int n); // non utilisé
      
      int    nbEchantillons() const ;    
      void   trier();
      bool   estTrie() const;
      
      void   extraireMediane();
      void   extraireMax();
      void   extraireMin();
      
      friend ostream& operator<<(ostream &sortie, Mesure &m);
 
   private:
      vector<double> echantillons;
      double mesure;
      double mesureMax;
      double mesureMin;
};

#endif
