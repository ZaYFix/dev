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
    cout << "Un tonneau de 9L qui contient 6L ?" << endl;
    
    Tonneau tonneau9(9);
    Tonneau tonneau4(4);
    
    cout << "On rempli le tonneau 9." << endl;
    tonneau9.remplir();
    
    cout << "Tonneau " << tonneau9.contenance() << "L : " << tonneau9.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau4.contenance() << "L : " << tonneau4.quantite() << " l" << endl;
    
    cout << "On transvase le tonneau 9 vers le tonneau 4." << endl;
    
    tonneau4.remplir(tonneau9);
    
    cout << "Tonneau " << tonneau9.contenance() << "L : " << tonneau9.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau4.contenance() << "L : " << tonneau4.quantite() << " l" << endl;
    
    cout << "On vide le tonneau 4." << endl;
    tonneau4.vider();
    
    cout << "Tonneau " << tonneau9.contenance() << "L : " << tonneau9.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau4.contenance() << "L : " << tonneau4.quantite() << " l" << endl;

    cout << "On transvase le tonneau 9 vers le tonneau 4." << endl;

    tonneau4.remplir(tonneau9);

    cout << "Tonneau " << tonneau9.contenance() << "L : " << tonneau9.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau4.contenance() << "L : " << tonneau4.quantite() << " l" << endl;
    
    cout << "On vide le tonneau 4." << endl;
    
    tonneau4.vider();
    
    cout << "Tonneau " << tonneau9.contenance() << "L : " << tonneau9.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau4.contenance() << "L : " << tonneau4.quantite() << " l" << endl;
    
    cout << "On transvase le tonneau 9 vers le tonneau 4." << endl;

    tonneau4.remplir(tonneau9);
    
    cout << "Tonneau " << tonneau9.contenance() << "L : " << tonneau9.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau4.contenance() << "L : " << tonneau4.quantite() << " l" << endl;
    
    cout << "On rempli le tonneau 9." << endl;
    tonneau9.remplir();
    
    cout << "Tonneau " << tonneau9.contenance() << "L : " << tonneau9.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau4.contenance() << "L : " << tonneau4.quantite() << " l" << endl;
    
    cout << "On transvase le tonneau 9 vers le tonneau 4." << endl;
    
    tonneau4.remplir(tonneau9);

    cout << "Tonneau " << tonneau9.contenance() << "L : " << tonneau9.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau4.contenance() << "L : " << tonneau4.quantite() << " l" << endl;
    
    cout << "On vide le tonneau 4 " << endl;
    
    tonneau4.vider();
    
    cout << "Tonneau " << tonneau9.contenance() << "L : " << tonneau9.quantite() << " l" << endl;
    cout << "Tonneau " << tonneau4.contenance() << "L : " << tonneau4.quantite() << " l" << endl;

    return 0;
}
