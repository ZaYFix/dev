#include "Communication.h"

#include <QDebug>
#include <QObject>

/**
 * @brief
 *
 * @param parent
 */
Communication::Communication(QObject *parent) : QObject(parent), port(new QSerialPort), trameBrut("\0")
{

}

/**
 * @brief
 *
 */
Communication::~Communication()
{
    port->close();
}

/**
 * @brief
 *
 */
void Communication::demarrerCommunicationPort()
{
    configurerPort();
    ouvrirPort();
}

/**
 * @brief
 *
 */
void Communication::configurerPort()
{
    port->setPortName(SERIALPORT);
    port->setBaudRate(QSerialPort::Baud115200);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);
}

/**
 * @brief
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
 * @brief
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

void Communication::envoyerCouleurLED(QString couleur)
{
    QString message = "SET LED " + couleur + "\n";
    QByteArray led = message.toUtf8();
    qDebug() << Q_FUNC_INFO << led;
    port->write(led);
}
