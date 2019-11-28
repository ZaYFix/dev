#ifndef COMMANDE_H
#define COMMANDE_H

#include <iostream>
#include <vector>
#include "Ligne.h" // ici il faut un accès à la déclaration complète de la classe Ligne (3)
#include "Client.h"
using namespace std;

class Ligne;
class Article;
class Client;

class Commande
{
    private:
        Ligne *quantite;
        Article *article;
        Client *client;
    
        string reference;
        string date;
        vector<Ligne> lignes; // composition
    public:
        Commande(string reference="", string date="");
        
        string getReference() const;
        void setReference(string reference);
        
        string getDate() const;
        void setDate(string date);
        void ajouterLigneArticle(Article *article, long quantite=1);
        
        double getTotal() const;
        int getNbLignes() const;
        long getNbArticles() const;
        
        void afficher() const;

        void setClient(Client *unClient);

        void saisir();
};

#endif //COMMANDE_H
