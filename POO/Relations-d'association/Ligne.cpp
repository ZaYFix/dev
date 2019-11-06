#include <iostream>
#include <iomanip>
#include <limits>

#include "Ligne.h"

using namespace std;

Ligne::Ligne() : quantite(0)
{   
}

long Ligne::getQuantite() const
{
    return 0;
}

void Ligne::setQuantite(long quantite)
{
   
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
