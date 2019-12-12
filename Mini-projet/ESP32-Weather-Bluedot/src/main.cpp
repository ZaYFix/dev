/**
*
* @file src/main.cpp
*
* @brief Programme principal ESP32-Weather
*
* @author Thierry Vaira
*
* @version 0.1
*
*/
#include <Arduino.h>
#include <afficheur.h>
#include <sonde.h>
#include <ledbicolore.h>
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include <monserveur.h>

// Brochages
#define GPIO_DHT            4       //!< DHT relié sur GPIO 25
#define GPIO_LED_ROUGE      17      //!< Led bicolore (rouge relié sur GPIO 17)
#define GPIO_LED_VERTE      16      //!< Led bicolore (vert relié sur GPIO 16)
#define ADRESSE_I2C_OLED    0x3c    //!< Adresse I2C de l'OLED
#define BROCHE_I2C_SDA      21      //!< Broche SDA
#define BROCHE_I2C_SCL      22      //!< Broche SCL

// Périodes
#define PERIODE_ACQUISITION 500     //!< période d'acquisition en millisecondes pour la sonde
#define PERIODE_ENVOI       5000    //!< période d'envoi des données en millisecondes pour le serveur

// Réseau
#define PORT                5000    //!< numéro de port du serveur

// Réseau WiFi par défaut
const char *ssid = "btsiris"; //!< le SSID du réseau WiFi à joindre
const char *password = "bts-iris"; //!< le mot de passe du SSID

// configuration adressage statique
IPAddress monAdresseIP(192, 168, 52, 20); //!< l'adresse IP statique
IPAddress maPasserelle(192, 168, 52, 42); //!< l'adresse IP du routeur par défaut
IPAddress monMasque(255, 255, 255, 0); //!< le masque de sous-réseau
IPAddress monDNSPrimaire(192, 168, 52, 42); //!< l'adresse IP du serveur DNS primaire à contacter
IPAddress monDNSSecondaire(8, 8, 8, 8); //!< l'adresse IP du serveur DNS secondaire à contacter (optionnel)
//Adresse MAC de la carte testée : 80:7D:3A:C4:2A:B8

#ifdef BLUETOOTH
#define BLUETOOTH_SLAVE //!< esclave
//#define BLUETOOTH_MASTER //!< maître
BluetoothSerial ESPBluetooth;
#endif

Afficheur afficheur(ADRESSE_I2C_OLED, BROCHE_I2C_SDA, BROCHE_I2C_SCL); //!< afficheur OLED SSD1306
Sonde sonde; //!< sonde équipée d'un TSL 2591 et d'un DHT22
LedBicolore led(GPIO_LED_ROUGE, GPIO_LED_VERTE); //!< led bicolore
MonServeur monServeur(PORT); //!< serveur TCP multi-clients sur le port PORT

/**
* @brief Initialise les ressources du programme
*
* @fn setup
*
*/
void setup()
{
  Serial.begin(115200);
  while (!Serial);

  sonde.demarrer();
  sonde.setPeriode(PERIODE_ACQUISITION); // 500 ms

  led.initialiser();
  led.eteindre();

  // si adressage statique sinon DHCP
  //monServeur.configurer(monAdresseIP, maPasserelle, monMasque, monDNSPrimaire, monDNSSecondaire);
  monServeur.demarrer(ssid, password);
  monServeur.setPeriode(PERIODE_ENVOI); // 5000 ms

  afficheur.initialiser();

  String titre = "";
  String stitre = "=====================";

  #ifdef WIFI
  titre = "IoT " + monServeur.getAdresseIP() + ":" + monServeur.getPort();  
  #endif
  #ifdef BLUETOOTH
  #ifdef BLUETOOTH_MASTER
  String nomBluetooth = "iot-esp-maitre";  
  ESPBluetooth.begin(nomBluetooth, true);
  const uint8_t* adresseESP32 = esp_bt_dev_get_address();
  char str[18];
  sprintf(str, "%02x:%02x:%02x:%02x:%02x:%02x", adresseESP32[0], adresseESP32[1], adresseESP32[2], adresseESP32[3], adresseESP32[4], adresseESP32[5]);
  stitre = String("== ") + String(str) + String(" ==");
  #ifndef WIFI
  titre = nomBluetooth;
  #endif  
  #else  
  String nomBluetooth = "iot-esp32";
  ESPBluetooth.begin(nomBluetooth);
  const uint8_t* adresseESP32 = esp_bt_dev_get_address();
  char str[18];
  sprintf(str, "%02x:%02x:%02x:%02x:%02x:%02x", adresseESP32[0], adresseESP32[1], adresseESP32[2], adresseESP32[3], adresseESP32[4], adresseESP32[5]);
  stitre = String("== ") + String(str) + String(" ==");
  #ifndef WIFI
  titre = nomBluetooth;
  #endif  
  #endif  
  #endif
  afficheur.setTitre(titre);
  afficheur.setSTitre(stitre);
  afficheur.afficher();
}

/**
* @brief Boucle infinie d'exécution du programme
*
* @fn loop
*
*/
void loop()
{
  // réalise une acquisition des mesures de la sonde si besoin ?
  if(sonde.acquerir())
  {
    // affiche les mesures de la sonde sur l'écran OLED
    afficheur.setMessageLigne(Afficheur::Ligne1, sonde.getLuminosite());
    afficheur.setMessageLigne(Afficheur::Ligne2, sonde.getTemperature());
    afficheur.setMessageLigne(Afficheur::Ligne3, sonde.getRessentie());
    afficheur.setMessageLigne(Afficheur::Ligne4, sonde.getHumidite());
    afficheur.afficher();

    // envoie les données aux clients
    String donneesSonde = sonde.getDonnees(); // le protocole est défini ici (à revoir)
    String donneesLed = led.getDonnees(); // le protocole est défini ici (à revoir)
    String message = donneesSonde + donneesLed;
    monServeur.envoyer(message);
  }

  // connecte un nouveau client si besoin
  monServeur.connecterClient();

  // lit une requête client et la traite si besoin
  if(monServeur.lireRequete())
  {
    String requete = monServeur.recupererRequete(); // le protocole est défini ici (à revoir)
    // traite la requête et répond au client
    String reponse = led.traiterRequete(requete); // le protocole est défini ici (à revoir)
    monServeur.repondreRequete(reponse);
  }
}
