/**
*
* @file lib/monserveur/monserveur.h
*
* @brief Déclaration de la classe MonServeur
*
* @author Thierry Vaira
*
* @version 0.1
*
*/
#ifndef MONSERVEUR_H
#define MONSERVEUR_H

#include "Arduino.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include "BluetoothSerial.h"

//#define DEBUG //!< active le mode débogage

#define WIFI //!< active le mode de communication WiFi
#define RS232 //!< active le mode de communication série
#define BLUETOOTH //!< active le mode de communication Bluetooth

//#define MODE_DETECTION_WLAN //!< active le mode du choix du WLAN

#define ATTENTE_RECONNEXION_WIFI  1000  //!< temps d'attente avant une nouvelle tentative de connexion
#define NB_TENTATIVES_WIFI        3     //!< nombre de tentaives max
#define PERIODE_ENVOI_DEFAUT      5000  //!< période d'envoi des données par défaut (en millisecondes)
#define MAX_CLIENTS               14    //!< nombre de clients max
#define MAX_LENGTH_PASSWORD       64    //!< longueur maximal du mot de passe
#define PORT_DEFAUT               5000  //!< numéro de port par défaut

#ifdef BLUETOOTH
extern BluetoothSerial ESPBluetooth;
#endif

/**
 * @struct Requete
 *
 * @brief Pour une requête émise par un client
 *
 */
typedef struct
{
  int numeroClient; //!< numéro de client connecté
  String requete; //!< la requête du client
  bool traite; //!< vrai si la requête a été traitée
} Requete;

/**
* @class MonServeur
*
* @brief Déclaration de la classe MonServeur qui permet d'exécuter un serveur TCP multi-clients
*
* @author Thierry Vaira
*
* @version 0.1
*
*/
#ifdef WIFI
class MonServeur : public WiFiServer
#else
class MonServeur
#endif
{
  private:
    String adresseIP; //!< l'adresse IP du serveur
    uint16_t port; //!< le port TCP du serveur
    String SSIDWifi; //!< le SSID du WiFi à joindre
    String PasswordWifi; //!< le mot de passe du SSID à joindre
    #ifdef WIFI
    WiFiClient clients[MAX_CLIENTS]; //!< les clients TCP connectés au serveur
    #endif
    unsigned long periode; //!< période d'envoi des données en millisecondes
    unsigned long tempsPrecedent; //!< temps du dernier envoi en millisecondes
    Requete requete; //!< une requête d'un client
    int nbTentatives; //!< nombre de tentatives max pour se connecter au WiFi
    bool dhcp;  //!< configuration en DHCP sinon adressage statique
    IPAddress monAdresseIP; //!< l'adresse IP statique
    IPAddress maPasserelle; //!< l'adresse IP du routeur par défaut
    IPAddress monMasque; //!< le masque de sous-réseau
    IPAddress monDNSPrimaire; //!< l'adresse IP du serveur DNS primaire à contacter
    IPAddress monDNSSecondaire; //!< l'adresse IP du serveur DNS secondaire à contacter (optionnel)    

    void activerWifi();
    int detecterWLAN(const char *ssid, const char *password);
    #ifdef MODE_DETECTION_WLAN
    int saisirNumeroReseau();
    String saisirPassword();
    bool selectionnerWLAN(int n, const char *ssid, const char *password);
    #endif
    bool estEcheance(unsigned long intervalle);

  public:
    MonServeur(uint16_t port=PORT_DEFAUT);

    String getPort() const;
    String getAdresseIP() const;
    unsigned long getPeriode() const;
    void setPeriode(unsigned long periode);
    void configurer(IPAddress monAdresseIP, IPAddress maPasserelle, IPAddress monMasque, IPAddress monDNSPrimaire, IPAddress monDNSSecondaire);
    void demarrer(const char *ssid, const char *password);
    void connecterClient();
    void envoyer(String message);
    bool lireRequete();
    String recupererRequete() const;
    void repondreRequete(String message);
    bool verifierRequete(String requete);
};

#endif
