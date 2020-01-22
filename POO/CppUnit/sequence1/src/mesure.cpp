#include "mesure.h"

Mesure::Mesure()
{
   reinitialiser();
}

Mesure::~Mesure()
{
}

void Mesure::reinitialiser()
{   
   echantillons.clear();
   mesure = 0.;
   mesureMax = 0.;
   mesureMin = 0.;
}

double Mesure::getMesure()
{    
   extraireMediane();  
   return mesure;
}

double Mesure::getMesureMax()
{
   extraireMax();
   return mesureMax;
}

double Mesure::getMesureMin()
{
   extraireMin();
   return mesureMin;
}

double Mesure::getEchantillon(int pos)
{
    if(pos >= 0 && pos < nbEchantillons())
        return echantillons.at(pos);
        
    return 0.;
}

void Mesure::ajouterEchantillon(double echantillon)
{
    echantillons.push_back(echantillon);
}

void Mesure::ajouterEchantillons(vector<double> &t)
{
   for(vector<double>::iterator it = t.begin(); it != t.end(); ++it)
   {
       ajouterEchantillon(*it);
   }
}

void Mesure::ajouterEchantillons(double *t, int n)
{
   for(int i=0;i<n;i++)
   {
       ajouterEchantillon(t[i]);
   }
}

int Mesure::nbEchantillons() const
{
   return echantillons.size();
}

void Mesure::trier()
{
   if(!estTrie())
      sort(echantillons.begin(), echantillons.end());
}

bool Mesure::estTrie() const
{
   for(int i=1;i<nbEchantillons();i++)
   {
      if(echantillons[i-1] > echantillons[i])
      {
         return false;
      }
   }
   return true;
}

void Mesure::extraireMediane()
{
   int n = nbEchantillons();

   if(n == 0)
        return;
        
   trier();
   
   if(n%2)
   {
      /* n est impair */
      mesure = echantillons[((n+1)/2)-1];
   }
   else
   {
      /* n est pair */
      mesure = (echantillons[(n/2)-1] + echantillons[((n/2))])/2;
   }
}

void Mesure::extraireMax()
{
   if(nbEchantillons() == 0)
      return;
   mesureMax = echantillons[0];
   for(int i = 1;i < echantillons.size();i++)
   {
      mesureMax = max(mesureMax, echantillons[i]);
   }
}

void Mesure::extraireMin()
{
   if(nbEchantillons() == 0)
      return;
   mesureMin = echantillons[0];
   for(int i = 1;i < echantillons.size();i++)
   {
      mesureMin = min(mesureMin, echantillons[i]);
   }
}

ostream& operator<<(ostream &sortie, Mesure &m)
{
   sortie << "nb echantillons :\t" << m.nbEchantillons() << "\n";
   sortie << "echantillons :\t\t";
   if(m.nbEchantillons() == 0)
        sortie << "aucun";
   for (int i=0; i<m.nbEchantillons(); i++)
   {
      sortie << m.echantillons[i] << " ";
   }
   sortie << "\n";
   
   sortie << "mesure :\t\t" << m.getMesure() << "\n";
   sortie << "mesure min :\t\t" << m.getMesureMin() << "\n";
   sortie << "mesure max :\t\t" << m.getMesureMax() << "\n";
      
   return sortie ;
}
