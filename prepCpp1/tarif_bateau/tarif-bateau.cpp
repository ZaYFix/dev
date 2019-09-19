#include <iostream>

#define AGE_MIN_REDUCTION       12
#define AGE_MAX_REDUCTION       25
#define AGE_MIN_GRATUIT         60
#define NB_TRAVERSEES_REDUCTION 50

using namespace std;

int main() 
{
    int agePersonne = 0;
    int nbTraversees = 0;

    cin >> agePersonne;
    cin >> nbTraversees;

    bool tarifReduit = (agePersonne >= AGE_MIN_REDUCTION && agePersonne <= AGE_MAX_REDUCTION) || (agePersonne > AGE_MIN_GRATUIT);
    bool tarifGratuit = (!tarifReduit && nbTraversees > NB_TRAVERSEES_REDUCTION);

    if (tarifReduit)
        {
            cout << "Tarif Reduit" << endl;
        }
    else if (tarifGratuit)
        {
            cout << "Tarif Gratuit" << endl;
        }
    else
        {
            cout << "Tarif Plein" << endl;
        }
    return 0;
}
