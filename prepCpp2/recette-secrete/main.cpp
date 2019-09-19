#include <iostream>
#include "tonneau.h"

using namespace std;

int main()
{  
    Tonneau tonneau1(5); // un tonneau de 2 L
    Tonneau tonneau2(3); // un tonneau de 2 L

    tonneau2.remplir(); // on remplit le tonneau 2
    cout << "Tonneau1 " << tonneau1.contenance() << "L : " << tonneau1.quantite() << " l" << endl;
    cout << "Tonneau2 " << tonneau2.contenance() << "L : " << tonneau2.quantite() << " l" << endl;
    
    tonneau1.remplir(tonneau2); // on transvase le tonneau1 dans le tonneau2
    cout << "Tonneau1 " << tonneau1.contenance() << "L : " << tonneau1.quantite() << " l" << endl;
    cout << "Tonneau2 " << tonneau2.contenance() << "L : " << tonneau2.quantite() << " l" << endl;
    
    tonneau2.remplir(); // on remplit le tonneau 2
    cout << "Tonneau1 " << tonneau1.contenance() << "L : " << tonneau1.quantite() << " l" << endl;
    cout << "Tonneau2 " << tonneau2.contenance() << "L : " << tonneau2.quantite() << " l" << endl;
    
    tonneau1.remplir(tonneau2); // on transvase le tonneau1 dans le tonneau2
    cout << "Tonneau1 " << tonneau1.contenance() << "L : " << tonneau1.quantite() << " l" << endl;
    cout << "Tonneau2 " << tonneau2.contenance() << "L : " << tonneau2.quantite() << " l" << endl;
    
    tonneau1.vider(); // on vide le tonneau 1
    cout << "Tonneau1 " << tonneau1.contenance() << "L : " << tonneau1.quantite() << " l" << endl;
    cout << "Tonneau2 " << tonneau2.contenance() << "L : " << tonneau2.quantite() << " l" << endl;
    
    tonneau1.remplir(tonneau2); // on transvase le tonneau1 dans le tonneau2
    cout << "Tonneau1 " << tonneau1.contenance() << "L : " << tonneau1.quantite() << " l" << endl;
    cout << "Tonneau2 " << tonneau2.contenance() << "L : " << tonneau2.quantite() << " l" << endl;
    
    tonneau2.remplir(); // on remplit le tonneau 2
    cout << "Tonneau1 " << tonneau1.contenance() << "L : " << tonneau1.quantite() << " l" << endl;
    cout << "Tonneau2 " << tonneau2.contenance() << "L : " << tonneau2.quantite() << " l" << endl;
    
    tonneau1.remplir(tonneau2); // on transvase le tonneau1 dans le tonneau2
    cout << "Tonneau1 " << tonneau1.contenance() << "L : " << tonneau1.quantite() << " l" << endl;
    cout << "Tonneau2 " << tonneau2.contenance() << "L : " << tonneau2.quantite() << " l" << endl;

    return 0;
}
