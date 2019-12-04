#include "de.h"

De::De(): de1(0), de2(0)
{
}

De::~De()
{
}

void De::jouer()
{
    lancerDes();
    afficherDes();
    calculerDes();
}

void De::lancerDes()
{
    srand (time(NULL));
    de1 = rand() % 6;
    de2 = rand() % 6;
}

void De::afficherDes()
{
    cout << de1 << endl;
    cout << de2 << endl;
}

void De::calculerDes()
{
    if(de1 == de2)
    {
        cout << "C'est un double !" << endl;
    }
}