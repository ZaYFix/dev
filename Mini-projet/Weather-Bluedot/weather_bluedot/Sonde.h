#ifndef SONDE_H
#define SONDE_H

#include <QtDebug>

/**
 * @file    Sonde.h
 * @brief   Définition de la classe Sonde
 * @details La classe Sonde permet d'extraire et d'envoyer les données reçu à l'IHM
 * @author  ACKERMANN Théo
 * @author  LEGGER Pierre-Antoine
 * @version 1.0
 */
class Sonde : public QObject
{
    Q_OBJECT
public:

    Sonde(QObject *parent = nullptr);
    ~Sonde();

    void envoyerMesuresIHM();
    void envoyerEtatLED(QString trameBrut);

public slots:

    void extraireMesures(QString trame);

private:
    double temperature; /**< valeur de la température */
    QString uniteTemperature; /**< unité de la température */

    double temperatureRessentie; /**< valeur de la température ressentie */
    QString uniteTemperatureRessentie; /**< unité de la température ressentie */

    double luminosite; /**< valeur de la luminosité */
    QString uniteLuminosite; /**< unité de la luminosité  */

    double humidite; /**< valeur de l'humidité  */
    QString uniteHumidite; /**< unité de l'humidité */

    double pression; /**< valeur de la pression */
    QString unitePression; /**< unité de la pression */

    double altitude; /**< valeur de l'altitude */
    QString uniteAltitude; /**< unité de l'altitude */

signals:
    /**
     * @brief Signal envoyant les nouvelles données de temperature et son unité
     *
     * @param temperature
     * @param uniteTemperature
     */
    void nouvelleTemperature(double temperature, QString uniteTemperature);
    /**
     * @brief Signal envoyant les nouvelles données de temperature ressentie et son unité
     *
     * @param temperatureRessentie
     * @param uniteTemperatureRessentie
     */
    void nouvelleTemperatureRessentie(double temperatureRessentie, QString uniteTemperatureRessentie);
    /**
     * @brief Signal envoyant les nouvelles données d'humidité et son unité
     *
     * @param humidite
     * @param uniteHumidite
     */
    void nouvelleHumidite(double humidite, QString uniteHumidite);
    /**
     * @brief Signal envoyant les nouvelles données de luminosité et son unité
     *
     * @param luminosite
     * @param uniteLuminosite
     */
    void nouvelleLuminosite(double luminosite, QString uniteLuminosite);
    /**
     * @brief Signal envoyant les nouvelles données de pression et son unité
     *
     * @param pression
     * @param unitePression
     */
    void nouvellePression(double pression, QString unitePression);
    /**
     * @brief Signal envoyant les nouvelles données d'altitude et son unité
     *
     * @param altitude
     * @param uniteAltitude
     */
    void nouvelleAltitude(double altitude, QString uniteAltitude);
    /**
     * @brief Signal envoyant les nouveaux états des leds
     *
     * @param trameBrut
     */
    void nouvelleEtatLED(QString trameBrut);
};

#endif // SONDE_H
