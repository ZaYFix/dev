#ifndef LED_H
#define LED_H

#include <QString>

class Led
{
public:
    Led();
    void extraireEtatLed(QString const trame);

private:
    unsigned int ledRouge;
    unsigned int ledVerte;
    unsigned int etat;
    unsigned int couleur;
};

#endif // LED_H
