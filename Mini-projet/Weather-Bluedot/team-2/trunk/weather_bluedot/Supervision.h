#ifndef SUPERVISION_H
#define SUPERVISION_H

#include <QObject>

class IHM;
class Communication;
class Sonde;
class Led;

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
    IHM *ihm;
    Communication *communication;
    Sonde *sonde;
    Led *led;

    QString listePortSerie;
};

#endif // SUPERVISION_H
