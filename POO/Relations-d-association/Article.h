#ifndef ARTICLE_H
#define ARTICLE_H

#include <iostream>
#include <string>

using namespace std;

class Article
{
   private:
      string titre;
      double prix;

   public:
      Article(string titre="", double prix=0.);

      string getTitre() const;
      double getPrix() const;
      void setTitre(string titre);
      void setPrix(double prix);
      void saisir();
};

#endif //ARTICLE_H
