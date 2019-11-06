#ifndef LIGNE_H
#define LIGNE_H

class Article;

class Ligne
{
    private:
    
        Article *article; // l’agrégation
        long quantite;
        
    public:
    
        Ligne(Article *article=NULL, long quantite=0);
        
        long getQuantite() const;
        void setQuantite(long quantite);
        
        Article * getArticle() const;
        
        void setArticle(Article *article);
        double getMontant() const;
        
        void afficher() const;
};

#endif //LIGNE_H
