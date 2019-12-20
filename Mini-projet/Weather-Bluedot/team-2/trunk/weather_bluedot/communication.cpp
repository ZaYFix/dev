#include "Communication.h"

#include <QDebug>
#include <QObject>

Communication::Communication(QObject *parent) : QObject(parent), port(new QSerialPort), trameBrut("\0")
{

}

Communication::~Communication()
{
    port->close();
}

void Communication::demarrerCommunicationPort()
{
    configurerPort();
    ouvrirPort();
}

void Communication::configurerPort()
{
    port->setPortName(SERIALPORT);
    port->setBaudRate(QSerialPort::Baud115200);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);
}

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

void Communication::recevoirTrame()
{
    while (port->waitForReadyRead(500))
    {
        trameBrut.append(port->readAll());
    }
    qDebug() << Q_FUNC_INFO << trameBrut;
}
