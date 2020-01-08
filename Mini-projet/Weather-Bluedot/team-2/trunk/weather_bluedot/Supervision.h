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

    void demarrer();

private:
    IHM *ihm;
    Communication *communication;
    Sonde *sonde;
    Led *led;
};

#endif // SUPERVISION_H
