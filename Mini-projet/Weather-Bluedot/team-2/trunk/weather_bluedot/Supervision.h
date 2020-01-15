#ifndef SUPERVISION_H
#define SUPERVISION_H

#include <QObject>

class IHM;
class Communication;
class Sonde;
class Led;

/**
 * @file    Supervision.h
 * @brief   Classe gérant la communication entre les classes du projet
 * @author  ACKERMANN Théo
 * @author  LEGGER Pierre-Antoine
 * @version 1.0
 */
class Supervision : public QObject
{
    Q_OBJECT
public:

    Supervision(IHM *parent = nullptr);
    ~Supervision();

    void demarrerCommunicationPort();
    void arreterCommunicationPort();
    void setNouveauPortSerie(QString nouveauPortSerie);
    QString rafraichirListePortSerie();

private:
    IHM *ihm; /**< Variable pointeur sur la classe Ihm */
    Communication *communication; /**< Variable pointeur sur la classe Communication */
    Sonde *sonde; /**< Variable pointeur sur la classe Sonde */
    Led *led; /**< Variable pointeur sur la classe Led */

    QString listePortSerie; /**< Variable contenant les informations d'un port */
};

#endif // SUPERVISION_H
