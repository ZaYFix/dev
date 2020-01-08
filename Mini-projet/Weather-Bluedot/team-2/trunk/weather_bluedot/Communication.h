#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#define SERIALPORT "/dev/ttyUSB0"

#include <QObject>
#include <QSerialPort>
#include <QString>

class Communication : public QObject
{
    Q_OBJECT
public:
    Communication(QObject *parent = nullptr);
    ~Communication();

    void demarrerCommunicationPort();
    void configurerPort();
    void ouvrirPort();

public slots:
    void recevoirTrame();
    void envoyerCouleurLED(QString couleur);

signals:
    void tramePrete(QString trame);

private:
     QSerialPort *port;
     QString trameBrut;
};

#endif // COMMUNICATION_H
