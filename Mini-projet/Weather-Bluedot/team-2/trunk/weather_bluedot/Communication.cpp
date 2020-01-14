#include "Communication.h"

#include <QDebug>
#include <QObject>

/**
 * @brief Constructeur de la classe Communication
 *
 * @param parent
 */
Communication::Communication(QObject *parent) : QObject(parent), port(new QSerialPort), trameBrut("\0"), port_serie("\0")
{

}

/**
 * @brief Destructeur de la classe Communication
 *
 */
Communication::~Communication()
{
    port->close();
}

/**
 * @brief Méthode qui démarre la configuration du port serie et ouvre le port serie
 *
 */
void Communication::demarrerCommunicationPort()
{
    configurerPort();
    ouvrirPort();
}

void Communication::arreterCommunicationPort()
{
    port->close();
}

/**
 * @brief Méthode qui configure le port serie
 *
 */
void Communication::configurerPort()
{
    port->setPortName(port_serie);
    port->setBaudRate(QSerialPort::Baud115200);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);
}

/**
 * @brief Méthode qui ouvre le port serie en lecture et écriture
 *
 */
void Communication::ouvrirPort()
{
    if (port->open(QIODevice::ReadWrite))
        {
            qDebug() << Q_FUNC_INFO << "Connecté au port";
            connect(port, SIGNAL(readyRead()), this, SLOT(recevoirTrame()));
        }
    else
        {
            qDebug() << Q_FUNC_INFO << "Erreur ouverture du port";
        }
}

/**
 * @brief Méthode qui permet de recevoir une trame via le port série
 *
 */
void Communication::recevoirTrame()
{
    trameBrut = "\0";

    while (port->waitForReadyRead(500))
    {
        trameBrut.append(port->readAll());
    }
    qDebug() << Q_FUNC_INFO << trameBrut;

    if(trameBrut == "OK\n")
        qDebug() << Q_FUNC_INFO << "Nouvelle couleur reçu";
    else
        emit tramePrete(trameBrut);
}

/**
 * @brief Méthode qui permet d'envoyer la nouvelle couleur de la LED via le port série
 *
 */
void Communication::envoyerCouleurLED(QString couleur)
{
    QString message = "SET LED " + couleur + "\n";
    QByteArray led = message.toUtf8();
    qDebug() << Q_FUNC_INFO << led;
    port->write(led);
}

void Communication::setPortSerie(QString nouveauPortSerie)
{
    port_serie = nouveauPortSerie;
     qDebug() << Q_FUNC_INFO << port_serie;
}
