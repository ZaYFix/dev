#include "Commande.h"
#include "Ligne.h"
#include "Article.h"

#include <iomanip>
#include <limits>
#include <ctype.h>
#include <vector>

Commande::Commande(string reference/*=""*/, string date/*=*/) : reference(reference), date(date)
{
}

string Commande::getReference() const
{
   return reference;
}

void Commande::setReference(string reference)
{
   this->reference = reference;
}

string Commande::getDate() const
{
   return date;
}

void Commande::setDate(string date)
{
   this->date = date;
}

int Commande::getNbLignes() const
{
    return lignes.size();
}

double Commande::getTotal() const
{
    double total = 0;
    
    for(unsigned int i=0;i < lignes.size() ; i++)
    {
        total += lignes[i].getMontant();
    }
    return total;
}

void Commande::ajouterLigneArticle(Article *article, long quantite)
{
    Ligne ligne1(article, quantite);
    lignes.push_back(ligne1);
}

long Commande::getNbArticles() const
{
    unsigned int nbArticles = 0;
    
    for(unsigned int i=0;i < lignes.size() ; i++)
    {
        nbArticles += lignes[i].getQuantite();
    }
    return nbArticles;
}

void Commande::afficher() const
{
   cout << setfill(' ') << setw(3) << quantite;
   cout << "|" << setfill('.') << setw(50) << article->getTitre(); 
   cout << "|" << setfill(' ') << setw(8) << article->getPrix(); 
   cout << "|" << setfill(' ') << setw(9) << quantite*article->getPrix() << " euros";
}

#ifdef SAISIE_COMMANDE
void Commande::saisir()
{
    string _date = "";
    char choix;
    
    if(leClient != NULL)
      leClient->saisir();
    
    do
    {
        Ligne l;        
        l.saisir();
        ajouterLigneArticle(l.getArticle(), l.getQuantite());
     
        do
        {    
            cout << "Un autre article à commander ? (o/n) ";
            cin >> choix;
            if(cin.good())
                choix = tolower(choix);
            if(!cin.good())
            {
                cerr << "Saisie invalide !\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }        
            else if(choix != 'o' && choix != 'n')
            {
                cout << "Choix incorrect !\n";
            }
        }
        while(choix != 'n' && choix != 'o');
    }
    while(choix != 'n');
    
    // saisie très minimale d'une date !
    do
    {
        cout << "Date commande ? (jj/mm/aaaa) ";
        cin >> ws;
        getline(cin, _date);
        if(!cin.good())
        {
            cerr << "Saisie invalide !\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            _date = "";
        }
    }
    while(_date.length() == 0);
    
    setDate(_date);
}
#endif
