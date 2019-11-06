#ifndef LIGNE_H
#define LIGNE_H

class Ligne
{
   private:
      long quantite;      

   public:
      Ligne();

      long getQuantite() const;
      void setQuantite(long quantite);
      
      void saisir();
};

#endif //LIGNE_H
