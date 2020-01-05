#include <iostream>
#include <stdexcept> // pour std::range_error
using namespace std;

void Exo_1()
{
    int numerateur, denominateur;
    
    numerateur = 10;
    cin >> denominateur;

    try
    {
        if(denominateur == 0)
        { 
            throw string("Division par zéro !");
        }
        else 
        {
            cout << numerateur / denominateur << endl;
        }
    }
    catch(string &e)
    {
        cerr << "Exception : " << e << endl;
        throw;
    }
}

int main()
{
    try
    {
        Exo_1();
    }

    catch ( ... )
    {
        cerr << "Exception interceptée !" << endl;
    }      
   
   cout << "Fin du programme" << endl;

   return 0;
}
