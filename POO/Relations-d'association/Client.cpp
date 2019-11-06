#include "Client.h"
#include "Commande.h"
#include <iomanip>
#include <limits>

Client::Client(string nom/*=""*/, int numero/*=0*/)
{   
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
