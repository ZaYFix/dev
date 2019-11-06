#include "Commande.h"

#include <iomanip>
#include <limits>
#include <ctype.h>

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
