#ifndef SONDE_H
#define SONDE_H

#include <QString>
#include <QtDebug>

//#define SIMULATION_SONDE

class Sonde : public QObject
{
    Q_OBJECT
public:

    Sonde(QObject *parent = nullptr);
    void envoyerMesuresIHM();

signals:
    void nouvelleTemperature(double temperature, QString uniteTemperature);
    void nouvelleTemperatureRessentie(double temperatureRessentie, QString uniteTemperatureRessentie);
    void nouvelleHumidite(unsigned int humidite, QString uniteHumidite);
    void nouvelleLuminosite(unsigned int luminosite, QString uniteLuminosite);
    void nouvellePression(unsigned int pression, QString unitePression);
    void nouvelleAltitude(int altitude, QString uniteAltitude);

public slots:
    void extraireMesures(QString trame);

private:
    double temperature;
    QString uniteTemperature;

    double temperatureRessentie;
    QString uniteTemperatureRessentie;

    unsigned int luminosite;
    QString uniteLuminosite;

    unsigned int humidite;
    QString uniteHumidite;

    unsigned int pression;
    QString unitePression;

    int altitude;
    QString uniteAltitude;
};

#endif // SONDE_H
