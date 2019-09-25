#include "tonneau.h"

#define TONNEAU_VIDE 0

Tonneau::Tonneau(int contenance):_contenance(contenance),_quantite(TONNEAU_VIDE)
{
    
}

int Tonneau::quantite() const
{
    return _quantite;
}

int Tonneau::contenance() const
{
    return _contenance;
}

void Tonneau::remplir()
{
    _quantite = _contenance;
}

void Tonneau::vider()
{
    _quantite = TONNEAU_VIDE;
}

void Tonneau::remplir(Tonneau &t)
{
    while(_quantite < _contenance && t._quantite > 0)
    {
        _quantite++;
        t._quantite--;
    }
}
