#ifndef LIGNE_H
#define LIGNE_H

class Article;
class Commande;

class Ligne
{
    private:
    
        Article *article; // l’agrégation
        Commande *commande;
        long quantite;
        
    public:
    
        Ligne(Article *article=NULL, long quantite=0);
        
        long getQuantite() const;
        void setQuantite(long quantite);
        
        Article * getArticle() const;
        
        void setArticle(Article *article);
        double getMontant() const;
        
        void afficher() const;

        void saisir();
};

#endif //LIGNE_H
