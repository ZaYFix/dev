#include "Supervision.h"
#include "Ihm.h"
#include "Communication.h"
#include "Sonde.h"
#include "Led.h"

Supervision::Supervision(IHM *parent) : QObject(parent), ihm(parent), communication(new Communication()), sonde(new Sonde()), led(new Led())
{
    connect(communication, SIGNAL(tramePrete(QString)), sonde, SLOT(extraireMesures(QString)));

    connect(sonde, SIGNAL(nouvelleTemperature(double, QString)), ihm, SLOT(afficherTemperature(double, QString)));

    connect(sonde, SIGNAL(nouvelleTemperatureRessentie(double, QString)), ihm, SLOT(afficherTemperatureRessentie(double, QString)));

    connect(sonde, SIGNAL(nouvelleHumidite(unsigned int, QString)), ihm, SLOT(afficherHumidite(unsigned int, QString)));

    connect(sonde, SIGNAL(nouvelleLuminosite(unsigned int, QString)), ihm, SLOT(afficherLuminosite(unsigned int, QString)));

    connect(sonde, SIGNAL(nouvellePression(unsigned int, QString)), ihm, SLOT(afficherPression(unsigned int, QString)));

    connect(sonde, SIGNAL(nouvelleAltitude(int, QString)), ihm, SLOT(afficherAltitude(int, QString)));

    demarrer();
}

Supervision::~Supervision()
{
    delete communication;
    delete sonde;
    delete led;
}

void Supervision::demarrer()
{
    communication->demarrerCommunicationPort();
}
