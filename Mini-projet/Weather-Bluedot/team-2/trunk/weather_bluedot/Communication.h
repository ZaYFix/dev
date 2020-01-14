#ifndef COMMUNICATION_H
#define COMMUNICATION_H

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
    void arreterCommunicationPort();
    void configurerPort();
    void ouvrirPort();
    void setPortSerie(QString nouveauPortSerie);

public slots:
    void recevoirTrame();
    void envoyerCouleurLED(QString couleur);

signals:
    void tramePrete(QString trame);

private:
     QSerialPort *port;
     QString trameBrut;
     QString port_serie;
};

#endif // COMMUNICATION_H
