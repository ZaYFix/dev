#include "Supervision.h"
#include "Ihm.h"
#include "Communication.h"
#include "Sonde.h"
#include "Led.h"
#include <QSerialPortInfo>

/**
 * @file    Supervision.cpp
 * @brief   Déclaration de la classe Supervision
 * @author  ACKERMANN Théo
 * @author  LEGGER Pierre-Antoine
 * @version 1.0
 */

/**
 * @brief Constructeur de la classe Supervision
 * @fn Supervision::Supervision
 * @param parent
 */
Supervision::Supervision(IHM *parent) : QObject(parent), ihm(parent), communication(new Communication()), sonde(new Sonde()), led(new Led()), listePortSerie("\0")
{
    connect(communication, SIGNAL(tramePrete(QString)), ihm, SLOT(afficherTrame(QString)));

    connect(communication, SIGNAL(tramePrete(QString)), sonde, SLOT(extraireMesures(QString)));

    connect(sonde, SIGNAL(nouvelleTemperature(double, QString)), ihm, SLOT(afficherTemperature(double, QString)));

    connect(sonde, SIGNAL(nouvelleTemperatureRessentie(double, QString)), ihm, SLOT(afficherTemperatureRessentie(double, QString)));

    connect(sonde, SIGNAL(nouvelleHumidite(double, QString)), ihm, SLOT(afficherHumidite(double, QString)));

    connect(sonde, SIGNAL(nouvelleLuminosite(double, QString)), ihm, SLOT(afficherLuminosite(double, QString)));

    connect(sonde, SIGNAL(nouvellePression(double, QString)), ihm, SLOT(afficherPression(double, QString)));

    connect(sonde, SIGNAL(nouvelleAltitude(double, QString)), ihm, SLOT(afficherAltitude(double, QString)));

    connect(sonde, SIGNAL(nouvelleEtatLED(QString)), led, SLOT(extraireEtatLed(QString)));

    connect(led, SIGNAL(ledAllumee()), ihm, SLOT(ledAllumee()));

    connect(led, SIGNAL(ledEteinte()), ihm, SLOT(ledEteinte()));

    connect(led, SIGNAL(ledCouleurRouge()), ihm, SLOT(ledCouleurRouge()));

    connect(led, SIGNAL(ledCouleurVerte()), ihm, SLOT(ledCouleurVerte()));

    connect(led, SIGNAL(ledCouleurOrange()), ihm, SLOT(ledCouleurOrange()));

    connect(ihm, SIGNAL(changerCouleurLED(QString)), communication, SLOT(envoyerCouleurLED(QString)));
}

/**
 * @brief Destructeur de la classe Supervision
 * @fn Supervision::~Supervision
 */
Supervision::~Supervision()
{
    delete communication;
    delete sonde;
    delete led;
}

/**
 * @brief Méthode pour demarer le port série
 * @fn Supervision::demarrerCommunicationPort
 */
void Supervision::demarrerCommunicationPort()
{
    communication->demarrerCommunicationPort();
}

/**
 * @brief Méthode pour arreter le port série
 * @fn Supervision::arreterCommunicationPort
 */
void Supervision::arreterCommunicationPort()
{
    communication->arreterCommunicationPort();
}

/**
 * @brief Méthode pour définir le nom du nouveau port série
 * @fn Supervision::setNouveauPortSerie
 * @param nouveauPortSerie
 */
void Supervision::setNouveauPortSerie(QString nouveauPortSerie)
{
    communication->setPortSerie(nouveauPortSerie);
}

/**
 * @brief Méthode pour rafraichir la liste de port série
 * @fn Supervision::rafraichirListePortSerie
 * @return Un QString contenant les informations d'un port
 */
QString Supervision::rafraichirListePortSerie()
{
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        listePortSerie = QObject::tr("Port: ") + info.portName() + "\n"
                    + QObject::tr("Location: ") + info.systemLocation() + "\n"
                    + QObject::tr("Description: ") + info.description() + "\n"
                    + QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
                    + QObject::tr("Serial number: ") + info.serialNumber() + "\n"
                    + QObject::tr("Vendor Identifier: ") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
                    + QObject::tr("Product Identifier: ") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n";
    }
    return listePortSerie;
}
