#include <iostream>
#include "tonneau.h"

using namespace std;

int main()
{  
    /* Question 1 */
    cout << "Créer les tonneaux" << endl;
    Tonneau tonneau5(5);
    Tonneau tonneau3(3);
    
    cout << "Tonneau " << tonneau5.contenance() << "L : " << tonneau5.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau3.contenance() << "L : " << tonneau3.quantite() << " l" << endl;
    
    /* Question 2 */
    cout << "Remplir les tonneaux" << endl;
    tonneau5.remplir();
    tonneau3.remplir();
    
    cout << "Tonneau " << tonneau5.contenance() << "L : " << tonneau5.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau3.contenance() << "L : " << tonneau3.quantite() << " l" << endl;
    
    cout << "Vider les tonneaux" << endl;
    tonneau5.vider();
    tonneau3.vider();
    
    cout << "Tonneau " << tonneau5.contenance() << "L : " << tonneau5.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau3.contenance() << "L : " << tonneau3.quantite() << " l" << endl;

    /* Question 3 */
    cout << "Transvaser les tonneaux" << endl;

    tonneau5.remplir();
    tonneau3.remplir(tonneau5);
    tonneau3.vider();

    cout << "Tonneau " << tonneau3.contenance() << "L : " << tonneau3.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau5.contenance() << "L : " << tonneau5.quantite() << " l" << endl;
    
    /* Question 4 */
    // TODO : Au moyen de deux tonneaux dont les capacités respectives sont neuf litres et quatre litres, nous souhaitons disposer d'une quantité d'eau de six litres. 
    cout << "Un tonneau de 9L qui contient 6L ?" << endl;

    return 0;
}
