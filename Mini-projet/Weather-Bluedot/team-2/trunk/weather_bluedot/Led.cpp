#include "Led.h"
#include <QDebug>
#include <QObject>

/**
 * @file    Led.cpp
 * @brief   Déclaration de la classe Led
 * @author  ACKERMANN Théo
 * @author  LEGGER Pierre-Antoine
 * @version 1.0
 */

/**
 * @brief Constructeur de la classe Led
 * @fn Led::Led
 */
Led::Led(QObject *parent) : QObject(parent), ledRouge(0), ledVerte(0), etat(0), couleur(0)
{

}

/**
 * @brief Destructeur de la classe Led
 * @fn Led::Led
 */
Led::~Led()
{

}

/**
 * @brief Méthode pour découper la trame et extraire l'état de la LED
 * @fn Led::extraireEtatLed
 * @param trameBrut
 */
void Led::extraireEtatLed(QString const trameBrut)
{
    ledRouge = (trameBrut.section(';',14,14)).toUInt();
    ledVerte = (trameBrut.section(';',15,15)).toUInt();
    etat = (trameBrut.section(';',16,16)).toUInt();
    couleur = (trameBrut.section(';',17,17)).toUInt();

    deduireEtatLed(etat, couleur);

    qDebug() << Q_FUNC_INFO << "ledRouge" << ledRouge;
    qDebug() << Q_FUNC_INFO << "ledVerte" << ledVerte;
    qDebug() << Q_FUNC_INFO << "etat" << etat;
    qDebug() << Q_FUNC_INFO << "couleur" << couleur;
}

/**
 * @brief Méthode pour déduire l'état et la couleur de la led
 * @fn Led::deduireEtatLed
 * @param etat
 * @param couleur
 */
void Led::deduireEtatLed(int etat, int couleur)
{
    switch(couleur)
    {
        case 1:
            emit ledCouleurRouge();
            break;
        case 2:
            emit ledCouleurVerte();
            break;
        case 3:
            emit ledCouleurOrange();
            break;
    }
    if(etat==1)
        emit ledAllumee();
    else
        emit ledEteinte();
}
