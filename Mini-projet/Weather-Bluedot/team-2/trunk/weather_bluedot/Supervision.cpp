#include "Supervision.h"
#include "Ihm.h"
#include "Communication.h"
#include "Sonde.h"
#include "Led.h"

/**
 * @brief Constructeur de la classe Supervision
 *
 * @param parent
 */
Supervision::Supervision(IHM *parent) : QObject(parent), ihm(parent), communication(new Communication()), sonde(new Sonde()), led(new Led())
{
    connect(communication, SIGNAL(tramePrete(QString)), sonde, SLOT(extraireMesures(QString)));

    connect(sonde, SIGNAL(nouvelleTemperature(double, QString)), ihm, SLOT(afficherTemperature(double, QString)));

    connect(sonde, SIGNAL(nouvelleTemperatureRessentie(double, QString)), ihm, SLOT(afficherTemperatureRessentie(double, QString)));

    connect(sonde, SIGNAL(nouvelleHumidite(double, QString)), ihm, SLOT(afficherHumidite(double, QString)));

    connect(sonde, SIGNAL(nouvelleLuminosite(double, QString)), ihm, SLOT(afficherLuminosite(double, QString)));

    connect(sonde, SIGNAL(nouvellePression(double, QString)), ihm, SLOT(afficherPression(double, QString)));

    connect(sonde, SIGNAL(nouvelleAltitude(double, QString)), ihm, SLOT(afficherAltitude(double, QString)));

    connect(ihm, SIGNAL(changerCouleurLED(QString)), communication, SLOT(envoyerCouleurLED(QString)));
}

/**
 * @brief Destructeur de la classe Supervision
 *
 */
Supervision::~Supervision()
{
    delete communication;
    delete sonde;
    delete led;
}

/**
 * @brief Méthode pour demarer le port série
 *
 */
void Supervision::demarrerCommunicationPort()
{
    communication->demarrerCommunicationPort();
}

void Supervision::arreterCommunicationPort()
{
    communication->arreterCommunicationPort();
}

void Supervision::setNouveauPortSerie(QString nouveauPortSerie)
{
    communication->setPortSerie(nouveauPortSerie);
}
