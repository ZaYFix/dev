#include <iostream>
#include <iomanip>
#include <limits>

#include "Ligne.h"
#include "Article.h"

using namespace std;

Ligne::Ligne(Article *article/*=NULL*/, long quantite/*=0*/) : article(article), quantite(quantite)
{   
}

long Ligne::getQuantite() const
{
    return quantite;
}

void Ligne::setQuantite(long quantite)
{
   this->quantite = quantite;
}

void Ligne::setArticle(Article *article)
{
    this->article = article;
}

Article * Ligne::getArticle() const
{
    return this->article;
}

double Ligne::getMontant() const
{
    return ( article->getPrix() * quantite );
}

void Ligne::afficher() const
{
   cout << setfill(' ') << setw(3) << quantite;
   cout << "|" << setfill('.') << setw(50) << article->getTitre(); 
   cout << "|" << setfill(' ') << setw(8) << article->getPrix(); 
   cout << "|" << setfill(' ') << setw(9) << quantite*article->getPrix() << " euros";
}

#ifdef SAISIE_LIGNE
void Ligne::saisir()
{
    Article *_article = new Article;        
    long _quantite = -1;
    
    if(_article == NULL)
        return;
   
    do
    {
        _article->saisir();        
        cout << "Quantité article ? ";
        cin >> _quantite;
        if(!cin.good())
        {
            cerr << "Quantité invalide !\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            _quantite = -1;
        }
        else if(_quantite < 1)
        {
            cout << "Quantité incorrecte !\n";
            _quantite = -1;
        }
    }
    while(_quantite < 1);
    
    setArticle(_article);
    quantite = _quantite;
}
#endif
