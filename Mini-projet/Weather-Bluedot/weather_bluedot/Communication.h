#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <QSerialPort>

/**
 * @file    Communication.h
 * @brief   Définition de la classe Communication
 * @details La classe Communication permet de communiquer avec le port série
 * @author  ACKERMANN Théo
 * @author  LEGGER Pierre-Antoine
 * @version 1.0
 */
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

private:
     QSerialPort *port; /**< Variable pointeur sur le port */
     QString trameBrut; /**< Variable qui contient la trame brut */
     QString port_serie; /**< Variable qui contient le nom du port serie */

signals:
    /**
     * @brief Envoie un signal quand une trame est prête
     * @param trame
     */
    void tramePrete(QString trame);
};

#endif // COMMUNICATION_H
