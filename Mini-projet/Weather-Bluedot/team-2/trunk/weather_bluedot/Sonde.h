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
    void nouvelleHumidite(double humidite, QString uniteHumidite);
    void nouvelleLuminosite(double luminosite, QString uniteLuminosite);
    void nouvellePression(double pression, QString unitePression);
    void nouvelleAltitude(double altitude, QString uniteAltitude);

public slots:
    void extraireMesures(QString trame);

private:
    double temperature; //!< valeur de la température
    QString uniteTemperature; //!< unité de la température

    double temperatureRessentie; //!< valeur de la température ressentie
    QString uniteTemperatureRessentie; //!< unité de la température ressentie

    double luminosite; //!< valeur de la luminosité
    QString uniteLuminosite; //!< unité de la luminosité

    double humidite; //!< valeur de l'humidité
    QString uniteHumidite; //!< unité de l'humidité

    double pression; //!< valeur de la pression
    QString unitePression; //!< unité de la pression

    double altitude; //!< valeur de l'altitude
    QString uniteAltitude; //!< unité de l'altitude
};

#endif // SONDE_H
