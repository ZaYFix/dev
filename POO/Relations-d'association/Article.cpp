#include "Article.h"

#include <limits>

Article::Article(string titre/*=""*/, double prix/*=0.*/)
{
}

string Article::getTitre() const
{
   
}

double Article::getPrix() const
{
   
}

void Article::setTitre(string titre)
{
   
}

void Article::setPrix(double prix)
{
   
}

#ifdef SAISIE_ARTICLE
void Article::saisir()
{
    string _titre = "";
    double _prix;
    
    do
    {
        cout << "Titre article ? ";
        cin >> ws;
        getline(cin, _titre);
        if(!cin.good())
        {
            cerr << "Saisie invalide !\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            _titre = "";
        }        
    }
    while(_titre.length() == 0);
    
    do
    {
        cout << "Prix article ? ";
        cin >> _prix;
        if(!cin.good())
        {
            cerr << "Prix invalide !\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            _prix = -1;
        }
        else if(_prix < 0.)
        {
            cout << "Prix incorrect !\n";
            _prix = -1;
        }
    }
    while(_prix < 0); 
    
    titre = _titre;
    prix = _prix;
}
#endif
