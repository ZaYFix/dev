#include "Client.h"
#include "Commande.h"
#include <iomanip>
#include <limits>

#define SAISIE_CLIENT

Client::Client(string nom/*=""*/, int numero/*=0*/): nom(nom), numero(numero)
{   
}

void Client::setNom(string nom)
{
    this->nom = nom;
}

void Client::setNumero(int numero)
{
    this->numero = numero;
}

string Client::getNom() const
{
    return this->nom;
}

int Client::getNumero() const
{
    return this->numero;
}

void Client::setCommande(Commande *commande)
{
    this->commande=commande;
}

#ifdef SAISIE_CLIENT
void Client::saisir()
{
    string _nom = "";
    int _numero = -1;
   
    do
    {
        cout << "Nom client ? ";
        cin >> ws;
        getline(cin, _nom);
        if(!cin.good())
        {
            cerr << "Saisie invalide !\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            _nom = "";
        }
    }
    while(_nom.length() == 0);
    
    do
    {
        cout << "Numéro client ? ";
        cin >> _numero;
        if(!cin.good())
        {
            cerr << "Numéro de client invalide !\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            _numero = -1;
        }
        else if(_numero < 1)
        {
            cout << "Numéro de client incorrecte !\n";
            _numero = -1;
        }
    }
    while(_numero < 1);    
            
    nom = _nom;
    numero = _numero;
}
#endif
