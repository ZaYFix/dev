#include <iostream>
#include <exception>
using namespace std;

class CEMinus : public exception
{
    private:
        string message_erreur;

    public:
        CEMinus(string const& erreur="") throw():message_erreur(erreur){}

        virtual const char* what() const throw() { return message_erreur.c_str(); }
};

int main()
{
    char c = 'a';

    try
    {
        while (islower(c))
        {
            cin >> c;
            if (!islower(c))
            {
                throw CEMinus("Le caractère n'est pas en minuscule !");
            }
        }
    }

    catch(CEMinus &e)
    {
        cerr << "Exception : " << e.what() << endl;
    }

    return 0;
}