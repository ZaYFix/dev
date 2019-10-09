#include <iostream>

#define NB_EMPLACEMENTS_MAX 1000

using namespace std;

int main()
{
    int nbEmplacements = 0;
    cin >> nbEmplacements;
    
    while( nbEmplacements > NB_EMPLACEMENTS_MAX)
    {
        cout << "Valeur incorrecte" << endl;
        cin >> nbEmplacements;
    }
    
 return 0;   
}
