#ifndef PILECHAR_H
#define PILECHAR_H

/*
 * Le but est de réaliser une structure de pile pouvant traiter des char.
 * 
 * La classe PileChar contient trois données membres privées : 
 * - deux entiers strictement positifs, nommés max et sommet, et 
 * - un pointeur sur un caractère, nommé pile. 
 * 
 * La donnée membre max contient la taille de la pile créée pour cette instance de la classe, autrement dit le nombre maximum de caractères qu'il sera possible d'y mettre. 
 * La donnée membre sommet indique le numéro de la case dans laquelle on pourra empiler le prochain caractère. Ce n'est donc pas exactement le sommet de la pile, mais un cran au dessus. 
 * Le pointeur sur un caractère pile désigne le tableau de caractères, alloué dynamiquement (avec new) pour mémoriser le contenu de la pile.
 * 
 */

// Active les affichages de debuggage pour les constructeurs et destructeur
#define DEBUG

class PileChar
{
   private:
      static const int tailleDefaut = 50; // constante de classe
      // ou anciennement :
      //enum { tailleDefaut = 50 };
      unsigned int max; // pour l'instant, on laisse const
      unsigned int sommet;
      char *pile;
      
   public:
      PileChar(int taille=tailleDefaut);
      PileChar(const PileChar &p);
      ~PileChar();

      PileChar(const string &init); // pour les chaînes de caractères en C++
      PileChar(const char *init); // pour les chaînes de caractères en C

      unsigned int taille() const;
      unsigned int compter() const;
      void afficher() const;
      void empiler(char Char);
      char depiler();

      PileChar& operator = (const PileChar &p);
};

void affiche_inverse(PileChar &p);

#endif //PILECHAR_H
