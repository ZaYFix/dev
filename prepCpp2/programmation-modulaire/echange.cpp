#include "echange.h"

using namespace std;

// Echange par Adresse
void echange2ParAdresse(float *pa, float *pb)
{
    float variableEchange = 0.0;
    if( *pa > *pb)
    {
        variableEchange = *pa;
        *pa = *pb;
        *pb = variableEchange;
    }
}

void ordonne3(float *pa, float *pb, float *pc)
{
    echange2ParAdresse(pa,pb);
    echange2ParAdresse(pb,pc);
    echange2ParAdresse(pa,pb);
}

// Echange par Reference
void echange2ParReference(float &a, float &b)
{
    float variableEchange = 0.0;
    if( &a > &b)
    {
        variableEchange = a;
        a = b;
        b = variableEchange;
    }
}

void ordonne3(float &a, float &b, float &c)
{
    echange2ParAdresse(&a,&b);
    echange2ParAdresse(&b,&c);
    echange2ParAdresse(&a,&b);
}
