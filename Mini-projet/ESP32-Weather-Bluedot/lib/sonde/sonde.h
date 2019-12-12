/**
*
* @file lib/sonde/sonde.h
*
* @brief Déclaration de la classe Sonde
*
* @author Thierry Vaira
*
* @version 0.1
*
*/
#ifndef SONDE_H
#define SONDE_H

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"
#include <Adafruit_BME280.h>
#include <DHT.h>

#define PERIODE_ACQUISITION_DEFAUT      500 //!< période d'acquisition par défaut en millisecondes
#define TYPE_DHT_DEFAUT                 DHT22 //!< type du capteur DHT ici DHT 22
#define GPIO_DHT_DEFAUT                 0 //!< pas de DHT
#define SEALEVELPRESSURE_HPA            (1013.25) //!< (pour le calcul de l'altitude)

/**
* @class Sonde
*
* @brief Déclaration de la classe Sonde qui regroupe les capteurs TSL 2591 et DHT22
*
* @author Thierry Vaira
*
* @version 0.1
*
*/
class Sonde
{
private:
  Adafruit_TSL2591 tsl; //!< capteur d'éclairement lumineux
  Adafruit_BME280 bme;
  DHT dht; //!< capteur de température et d'humidité
  uint16_t luminosite; //!< valeur de l'éclairement lumineux en lux
  float humidite; //!< valeur de l'humidité en %
  float temperature; //!< valeur de la température en degré Celcius
  float ressentie; //!< valeur de la température ressentie (calculée à partir de la température et de l'humidité)
  float pression; //!< valeur de la pression atmosphérique en hPa
  float altitude; //!< valeur approchée de l'altitude en m'
  unsigned long periode; //!< période d'acquisition des valeurs en millisecondes
  unsigned long tempsPrecedent; //!< temps de la dernère acquisition en millisecondes
  bool dhtDetection;
  bool bmeDetection;

  void initialiserCapteurs();
  bool estEcheance(unsigned long intervalle);
  float computeHeatIndex(float temperature, float percentHumidity);
  float convertCtoF(float c);
  float convertFtoC(float f);

public:
  Sonde(int brocheGPIODHT=GPIO_DHT_DEFAUT);
  void demarrer();
  void setPeriode(unsigned long periode);
  unsigned long getPeriode() const;
  String getLuminosite() const;
  String getTemperature() const;
  String getRessentie() const;
  String getHumidite() const;
  String getPression() const;
  String getAltitude() const;
  String getDonnees() const;
  bool acquerir();
};

#endif
