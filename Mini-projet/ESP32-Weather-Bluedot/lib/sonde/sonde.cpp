/**
*
* @file lib/sonde/sonde.cpp
*
* @brief Définition de la classe Sonde
*
* @author Thierry Vaira
*
* @version 0.1
*
*/
#include <sonde.h>

/**
* @brief Constructeur de la classe Sonde
*
* @fn Sonde::Sonde
*
* @param brocheGPIODHT int numéro de broche 1Wire
*/
Sonde::Sonde(int brocheGPIODHT) : tsl(1234), dht(brocheGPIODHT, TYPE_DHT_DEFAUT), luminosite(0), humidite(-1.0), temperature(-273.0), ressentie(-273.), pression(0.), altitude(0.), periode(PERIODE_ACQUISITION_DEFAUT), tempsPrecedent(0), dhtDetection(false), bmeDetection(false)
{
  if(brocheGPIODHT != 0)
    dhtDetection = true;
}

/**
* @brief Assure le démarrage du fonctionnement de la Sonde
*
* @fn Sonde::demarrer
*
*/
void Sonde::demarrer()
{
  initialiserCapteurs();
}

/**
* @brief Mutateur set pour le membre periode
*
* @fn Sonde::setPeriode
*
* @param periode unsigned long nouvelle période d'acquisition des mesures 
*/
void Sonde::setPeriode(unsigned long periode)
{
  this->periode = periode;
}

/**
* @brief Accesseur get pour le mebre periode
*
* @fn Sonde::getPeriode
*
* @return unsigned long la période d'acquisition des mesures
*/
unsigned long Sonde::getPeriode() const
{
  return periode;
}

/**
* @brief Retourne la luminosité pour son affichage
*
* @fn Sonde::getLuminosite
*
* @return String la luminosité sous la forme "LUMINOSITE : xxx lux"
*/
String Sonde::getLuminosite() const
{
  char strMessageDisplay[24];
  sprintf(strMessageDisplay, "LUMINOSITE : %u lux", luminosite);
  return String(strMessageDisplay);
}

/**
* @brief Retourne la température pour son affichage
*
* @fn Sonde::getTemperature
*
* @return String la température sous la forme "TEMPERATURE : xx. °C"
*/
String Sonde::getTemperature() const
{
  char strMessageDisplay[24];
  sprintf(strMessageDisplay, "TEMPERATURE : %.1f °C", temperature);
  return String(strMessageDisplay);
}

/**
* @brief Retourne la température ressentie pour son affichage
*
* @fn Sonde::getRessentie
*
* @return String la température ressentie sous la forme "RESSENTIE : xx.x °C"
*/
String Sonde::getRessentie() const
{
  char strMessageDisplay[24];
  sprintf(strMessageDisplay, "RESSENTIE : %.1f °C", ressentie);
  return String(strMessageDisplay);
}

/**
* @brief Retourne l'humidité pour son affichage
*
* @fn Sonde::getHumidite
*
* @return String l'humidité sous la forme "HUMIDITE : xx %"
*/
String Sonde::getHumidite() const
{
  char strMessageDisplay[24];
  sprintf(strMessageDisplay, "HUMIDITE : %u %%", (uint16_t)humidite);
  return String(strMessageDisplay);
}

/**
* @brief Retourne la pression atmosphérique pour son affichage
*
* @fn Sonde::getPression
*
* @return String la pression atmosphérique pour son affichage sous la forme "PRESSION : xx hPa"
*/
String Sonde::getPression() const
{
  char strMessageDisplay[24];
  if(bmeDetection)
    sprintf(strMessageDisplay, "PRESSION : %u hPa", (uint16_t)pression);
  else
    sprintf(strMessageDisplay, "PRESSION : NaN hPa");  
  return String(strMessageDisplay);
}

/**
* @brief Retourne l'altitude pour son affichage
*
* @fn Sonde::getAltitude
*
* @return String l'altitude sous la forme "ALTITUDE : xx m"
*/
String Sonde::getAltitude() const
{
  char strMessageDisplay[24];
  if(bmeDetection)
    sprintf(strMessageDisplay, "ALTITUDE : %u m", (uint16_t)altitude);
  else
    sprintf(strMessageDisplay, "ALTITUDE : NaN m");  
  return String(strMessageDisplay);
}

/**
* @brief Retourne les données de la Sonde suivant le protocole
*
* @fn Sonde::getDonnees
*
* @return String les données formatées par le protocole
*/
String Sonde::getDonnees() const
{
  String donnees;
  //TEMPERATURE;C;RESSENTIE;C;HUMIDITE;%;LUMINOSITE;lux;\r\n
  if(!bmeDetection)
    donnees = "SONDE;" + String(temperature, 1) + ";" + "C" + ";" + String(ressentie, 1) + ";" + "C" + ";" + String(humidite, 0) + ";" + "%" + ";" + String(luminosite) + ";" + "lux" + ";" + "\r\n";
  else
    donnees = "SONDE;" + String(temperature, 1) + ";" + "C" + ";" + String(ressentie, 1) + ";" + "C" + ";" + String(humidite, 0) + ";" + "%" + ";" + String(luminosite) + ";" + "lux" + ";" + String(pression, 0) + ";" + "hPa" + ";" + String(altitude, 0) + ";" + "m" + ";" + "\r\n";
  return donnees;
}

/**
* @brief Réalise l'acquisition des mesures de la Sonde à l'échéance de la période
*
* @fn Sonde::acquerir
*
* @return bool true si l'acquisition a été réalisée sino false
*/
bool Sonde::acquerir()
{
  if(estEcheance(periode))
  {
    luminosite = tsl.getLuminosity(TSL2591_VISIBLE);
    //Serial.print(F("Luminosité : "));
    //Serial.println(luminosite, DEC);
    if(dhtDetection)
    {
      humidite = dht.readHumidity(false);
      temperature = dht.readTemperature(false);
      //Serial.print(F("Temperature : "));
      //Serial.println(temperature);
      //Serial.print(F("Humidité : "));
      //Serial.println(humidite);
      if (!isnan(temperature) && !isnan(humidite))
      {
        ressentie = dht.computeHeatIndex(temperature, humidite, false);
        //Serial.print(F("Temperature ressentie : "));
        //Serial.println(ressentie);
      }
    }
    else if(bmeDetection)
    {
      temperature = bme.readTemperature();
      //Serial.print(F("Temperature : "));
      //Serial.println(temperature);
      humidite = bme.readHumidity();
      //Serial.print(F("Humidité : "));
      //Serial.println(humidite);
      if (!isnan(temperature) && !isnan(humidite))
      {
        ressentie = computeHeatIndex(temperature, humidite);
        //Serial.print(F("Temperature ressentie : "));
        //Serial.println(ressentie);
      }
      pression = bme.readPressure() / 100.0F;// hPa
      //Serial.print(F("Pression : "));
      //Serial.println(pression); // hPa
      altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
      //Serial.print(F("Altitude : "));
      //Serial.println(altitude); // en m
    }    
    return true;
  }
  return false;
}

/**
* @brief Initialise les capteurs TSL 2591 et DHT22
*
* @fn Sonde::initialiserCapteurs
*
*/
void Sonde::initialiserCapteurs()
{
  //Serial.println("Initialiser capteurs");
  if (tsl.begin())
  {
    tsl.setGain(TSL2591_GAIN_LOW);    // 1x gain (bright light)
    //tsl.setGain(TSL2591_GAIN_MED);      // 25x gain
    //tsl.setGain(TSL2591_GAIN_HIGH);   // 428x gain    
    //tsl.setTiming(TSL2591_INTEGRATIONTIME_300MS);
    //tsl.setTiming(TSL2591_INTEGRATIONTIME_500MS);
    tsl.setTiming(TSL2591_INTEGRATIONTIME_600MS);
  }
  /*else
  {
    Serial.println(F("Aucun TSL2591 trouvé !"));
  }*/
  if(dhtDetection)
    dht.begin();  
  /*else
  {
    Serial.println(F("Aucun DHT présent !"));
  }*/  
  bmeDetection = bme.begin();  
  /*if (!bmeDetection) 
  {
    Serial.println(F("Aucun BME280 trouvé !"));
  }*/
}

/**
* @brief Retourne true si l'échéance de la période fixée a été atteinte
*
* @fn Sonde::estEcheance
*
* @param intervalle unsigned long
* @return bool true si l'intervalle entre deux périodes est arrivé à échéance
*/
bool Sonde::estEcheance(unsigned long intervalle)
{
    unsigned long temps = millis();
    if (temps - tempsPrecedent >= intervalle)
    {
        tempsPrecedent = temps;
        return true;
    }
    return false;
}

float Sonde::computeHeatIndex(float temperature, float percentHumidity) 
{
  // From DHT library Adafruit Industries
  // Using both Rothfusz and Steadman's equations
  // http://www.wpc.ncep.noaa.gov/html/heatindex_equation.shtml
  float hi;

  temperature = convertCtoF(temperature);

  hi = 0.5 * (temperature + 61.0 + ((temperature - 68.0) * 1.2) + (percentHumidity * 0.094));

  if (hi > 79) {
    hi = -42.379 +
             2.04901523 * temperature +
            10.14333127 * percentHumidity +
            -0.22475541 * temperature*percentHumidity +
            -0.00683783 * pow(temperature, 2) +
            -0.05481717 * pow(percentHumidity, 2) +
             0.00122874 * pow(temperature, 2) * percentHumidity +
             0.00085282 * temperature*pow(percentHumidity, 2) +
            -0.00000199 * pow(temperature, 2) * pow(percentHumidity, 2);

    if((percentHumidity < 13) && (temperature >= 80.0) && (temperature <= 112.0))
      hi -= ((13.0 - percentHumidity) * 0.25) * sqrt((17.0 - abs(temperature - 95.0)) * 0.05882);

    else if((percentHumidity > 85.0) && (temperature >= 80.0) && (temperature <= 87.0))
      hi += ((percentHumidity - 85.0) * 0.1) * ((87.0 - temperature) * 0.2);
  }

  return convertFtoC(hi);
}

float Sonde::convertCtoF(float c) 
{
  return c * 1.8 + 32;
}

float Sonde::convertFtoC(float f) 
{
  return (f - 32) * 0.55555;
}
