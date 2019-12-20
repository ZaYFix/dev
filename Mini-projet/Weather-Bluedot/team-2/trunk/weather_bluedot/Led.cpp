#include "Led.h"

Led::Led() : ledRouge(0), ledVerte(0), etat(0), couleur(0)
{

}

void Led::extraireEtatLed(QString const trame)
{
    ledRouge = (trame.section(';',1,1)).toUInt();
    ledVerte = (trame.section(';',2,2)).toUInt();
    etat = (trame.section(';',3,3)).toUInt();
    couleur = (trame.section(';',4,4)).toUInt();
}
