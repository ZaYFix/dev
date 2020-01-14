#include "Sonde.h"

/**
 * @brief Constructeur de la classe Ihm
 *
 * @param parent
 */
Sonde::Sonde(QObject *parent) : QObject(parent), temperature(0), uniteTemperature("\0"), temperatureRessentie(0), uniteTemperatureRessentie("\0"),  luminosite(0), uniteLuminosite("\0"), humidite(0), \
                 uniteHumidite("\0"), pression(0), unitePression("\0"), altitude(0), uniteAltitude("\0")
{

}

/**
 * @brief Méthode découpant la trame et plaçant les valeurs des capteurs dans des variables
 *
 * @param trameBrut
 */
void Sonde::extraireMesures(QString trameBrut)
{
    temperature = (trameBrut.section(';',1,1)).toDouble();
    uniteTemperature = (trameBrut.section(';',2,2));
    qDebug() << Q_FUNC_INFO << "Température" << temperature << uniteTemperature;
    temperatureRessentie = (trameBrut.section(';',3,3)).toDouble();
    uniteTemperatureRessentie = trameBrut.section(';',4,4);
    qDebug() << Q_FUNC_INFO << "Température Ressentie" << temperatureRessentie << uniteTemperatureRessentie;
    humidite = (trameBrut.section(';',5,5)).toDouble();
    uniteHumidite = trameBrut.section(';',6,6);
    qDebug() << Q_FUNC_INFO << "Humidité" << humidite << uniteHumidite;
    luminosite = (trameBrut.section(';',7,7)).toDouble();
    uniteLuminosite = trameBrut.section(';',8,8);
    qDebug() << Q_FUNC_INFO << "Luminosité" << luminosite << uniteLuminosite;
    pression = (trameBrut.section(';',9,9)).toDouble();
    unitePression = trameBrut.section(';',10,10);
    qDebug() << Q_FUNC_INFO << "Pression" << pression << unitePression;
    altitude = (trameBrut.section(';',11,11)).toDouble();
    uniteAltitude = trameBrut.section(';',12,12);
    qDebug() << Q_FUNC_INFO << "Altitude" << altitude << uniteAltitude;

    envoyerMesuresIHM();
}

/**
 * @brief Méthode qui envoie un signal avec les valeurs des capteurs reçut
 *
 */
void Sonde::envoyerMesuresIHM()
{
    emit nouvelleTemperature(temperature, uniteTemperature);
    emit nouvelleTemperatureRessentie(temperatureRessentie, uniteTemperatureRessentie);
    emit nouvelleHumidite(humidite, uniteHumidite);
    emit nouvelleLuminosite(luminosite, uniteLuminosite);
    emit nouvellePression(pression, unitePression);
    emit nouvelleAltitude(altitude, uniteAltitude);
}
