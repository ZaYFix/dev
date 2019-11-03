#include <iostream>
#include <cstring>

using namespace std;

#include "PileChar.h"

PileChar::PileChar(int taille) : max(taille), sommet(0), pile(0)
{   
   pile = new char[taille];
    
   #ifdef DEBUG
   cout << "PileChar(" << taille << ") : " << this << "\n";
   #endif
}

PileChar::~PileChar()
{
   delete pile;
   
   #ifdef DEBUG
   cout << "~PileChar() : " << this << "\n";
   #endif
}

PileChar::PileChar(const PileChar &p) : max(p.max), sommet(p.sommet), pile(0)
{
   pile = new char[max];

   for(unsigned int i=0 ; i < sommet ; i++)
   {
      pile[i] = p.pile[i];
   }

   #ifdef DEBUG
   cout << "PileChar(const PileChar &p) : " << this << "\n";
   #endif
}

PileChar::PileChar(const string &init)
{
   max = init.size();
   sommet = max;

   pile = new char[max];

   for(unsigned int i=0 ; i < sommet ; i++)
   {
      pile[i] = init[i];
   }

   #ifdef DEBUG
   cout << "PileChar(\""<< init <<"\") : " << this << "\n";
   #endif
}

PileChar::PileChar(const char *init)
{
   max=0;
   while(init[max] != '\0')
   {
      ++max;
   }

   sommet=max;
   pile = new char[max];

   for(unsigned int i=0;i<sommet;i++)
   {
      pile[i] = init[i];
   }

   #ifdef DEBUG
   cout << "PileChar(\""<< init <<"\") : " << this << "\n";
   #endif
}

PileChar& PileChar::operator = (const PileChar &p)
{
   // vérifions si on ne s’auto-copie pas !
   if (this != &p)
   {
      delete pile;

      // 2. on réinitialise les attributs
      max=p.max;
      sommet=p.sommet;

      // 3. on alloue une nouvelle pile
      pile = new char[max];

      // 4. on recopie les éléments de la pile
      for(unsigned int i=0 ; i < sommet ; i++)
      {
         pile[i] = p.pile[i];
      }
   }
   #ifdef DEBUG
      cout << "operator= (const PileChar &p) : " << this << "\n";
   #endif
   return *this;
}

unsigned int PileChar::taille() const
{
   return max;
}

unsigned int PileChar::compter() const
{
   return sommet;
}

void PileChar::afficher() const
{
   int nbChar = 0;
   cout << "[";
   while(pile[nbChar] != '\0')
   {
      cout << pile[nbChar];
      nbChar++;
   }
   cout << "]" << endl;
}

void PileChar::empiler(char caractere)
{
   if ( sommet < max )
   {
      pile[sommet] = caractere;
      sommet++;
      pile[sommet] = '\0';
   }
   else
   {
      cerr << "Pile pleine" << endl;
   }
   
}

char PileChar::depiler()
{
   char caractere = '\0';

   if (sommet != 0)
   {
      --sommet;
      caractere = pile[sommet];
      pile[sommet]= '\0';
   }
   else
   {
      cerr << "Pile vide" << endl;
   }
   return caractere;
}

void affiche_inverse(PileChar &p)
{
   cout << "TODO" << endl;
}

