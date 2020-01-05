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
    }
}

int main()
{
    Exo_1();      
   
   cout << "Fin du programme" << endl;

   return 0;
}
