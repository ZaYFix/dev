#include <iostream>
#include "exemple.h"

using namespace std;

int main()
{
    char c = 0;
    
    c = '3';
    cout << c << " est-il un chiffre ? " << estChiffre(c) << endl;

    c = 'A';
    cout << c << " est-il un chiffre ? " << estChiffre(c) << endl;

    return 0;
}

