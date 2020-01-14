#ifndef SONDE_H
#define SONDE_H

#include <QString>
#include <QtDebug>

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
    double temperature; //!< valeur de la température
    QString uniteTemperature; //!< unité de la température

    double temperatureRessentie; //!< valeur de la température ressentie
    QString uniteTemperatureRessentie; //!< unité de la température ressentie

    unsigned int luminosite; //!< valeur de la luminosité
    QString uniteLuminosite; //!< unité de la luminosité

    unsigned int humidite; //!< valeur de l'humidité
    QString uniteHumidite; //!< unité de l'humidité

    unsigned int pression; //!< valeur de la pression
    QString unitePression; //!< unité de la pression

    int altitude; //!< valeur de l'altitude
    QString uniteAltitude; //!< unité de l'altitude
};

#endif // SONDE_H
