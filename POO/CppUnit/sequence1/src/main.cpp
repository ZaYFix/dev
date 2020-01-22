#include <iostream>
#include "mesure.h"

using namespace std;

int main()
{
    Mesure mesure;   
    
    cout << mesure << endl;
   
    const int NB_ELT = 5;
    vector<double> echantillons(NB_ELT);
	
	echantillons[0] = 35.53;
	echantillons[1] = 35.23;
	echantillons[2] = 35.10;
	echantillons[3] = 35.02;
	echantillons[4] = 34.45;
    
    mesure.ajouterEchantillons(echantillons);
    
    cout << mesure << endl;
    
    cout << "mesure selectionnée : " << mesure.getMesure() << endl;

    return 0;
}

