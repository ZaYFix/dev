#include <iostream>
#include "echange.h"

using namespace std;

int main()
{
    float a = 11.5;
    float b = -2.1;
    float c = 0.0;
    
    //echange2ParAdresse(&a,&b);
    ordonne3(a, b, c);
    cout << a << " < " << b << " < " << c << endl;
    ordonne3(&a,&b,&c);
    cout << a << " < " << b << " < " << c << endl;
    
    return 0;
}

