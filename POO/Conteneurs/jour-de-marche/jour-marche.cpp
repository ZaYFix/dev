#include <iostream>
#include <map>
#include <string>

#define NB_EMPLACEMENTS_MAX 1000

using namespace std;

int main()
{
    int nbEmplacements = 0;
    string nom = "\0";
    map<string,unsigned int> emplacementsMarchands;
    cin >> nbEmplacements;
    
    while (nbEmplacements > NB_EMPLACEMENTS_MAX)
    {
        cout << "Valeur incorrecte" << endl;
        cin >> nbEmplacements;
    }
    
    for (int i=0;i<nbEmplacements;i++)
    {
        cin >> nom;
        emplacementsMarchands[nom]=i;
    }
    
    for(map<string,unsigned int>::const_iterator it = emplacementsMarchands.begin(); it != emplacementsMarchands.end(); it++)
    {
        cout << (*it).first << " " << (*it).second+1 << endl;
    }
    
 return 0;   
}
