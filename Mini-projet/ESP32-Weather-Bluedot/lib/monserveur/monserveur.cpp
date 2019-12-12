/**
*
* @file lib/monserveur/monserveur.cpp
*
* @brief Définition de la classe MonServeur
*
* @author Thierry Vaira
*
* @version 0.1
*
*/
#include <monserveur.h>

/**
* @brief Constructeur de la classe MonServeur
*
* @fn MonServeur::MonServeur
*
* @param port uint16_t numéro de port du serveur (5000 par défaut)
*/
#ifdef WIFI
MonServeur::MonServeur(uint16_t port) : WiFiServer(port), adresseIP(""), port(port), periode(PERIODE_ENVOI_DEFAUT), tempsPrecedent(0), dhcp(true)
#else
MonServeur::MonServeur(uint16_t port) : adresseIP(""), port(port), periode(PERIODE_ENVOI_DEFAUT), tempsPrecedent(0), dhcp(true)
#endif
{
  this->requete.traite = true;
}

String MonServeur::getPort() const
{
  char strPort[16];
  sprintf(strPort, "%u", port);
  return String(strPort);
}

String MonServeur::getAdresseIP() const
{
  return adresseIP;
}

/**
* @brief Accesseur get du membre periode
*
* @fn MonServeur::getPeriode
*
* @return periode unsigned long la période d'envoi en millisecondes
*/
unsigned long MonServeur::getPeriode() const
{
  return periode;
}

/**
* @brief Mutateur set du membre periode
*
* @fn MonServeur::setPeriode
*
* @param periode unsigned long la nouvelle période d'envoi en millisecondes
*/
void MonServeur::setPeriode(unsigned long periode)
{
  this->periode = periode;
}

/**
* @brief Configure une adresse statique
*
* @fn MonServeur::configurer
*
* @param monAdresseIP IPAddress l'adresse IP statique
* @param maPasserelle IPAddress l'adresse IP du routeur par défaut
* @param monMasque IPAddress le masque de sous-réseau
* @param monDNSPrimaire IPAddress l'adresse IP du serveur DNS primaire à contacter
* @param monDNSSecondaire IPAddress l'adresse IP du serveur DNS secondaire à contacter (optionnel)
*/
void MonServeur::configurer(IPAddress monAdresseIP, IPAddress maPasserelle, IPAddress monMasque, IPAddress monDNSPrimaire, IPAddress monDNSSecondaire)
{
  this->monAdresseIP = monAdresseIP;
  this->maPasserelle = maPasserelle;
  this->monMasque = monMasque;
  this->monDNSPrimaire = monDNSPrimaire;
  this->monDNSSecondaire = monDNSSecondaire;
  dhcp = false;
}

/**
* @brief Démarre le serveur TCP via un réseau WiFi
*
* @fn MonServeur::demarrer
*
* @param ssid const char* le SSID du réseau WiFi à joindre
* @param password const char* le mot de passe associé au SSID
*/
void MonServeur::demarrer(const char *ssid, const char *password)
{
  #ifdef WIFI
  int n = -1;
  do
  {
    n = detecterWLAN(ssid, password);
    if(n == 0)
    {
      activerWifi();
    }
    #ifdef MODE_DETECTION_WLAN
    else if(n > 0)
    {
      if(selectionnerWLAN(n, ssid, password))
        activerWifi();
    }
    #endif
    else
    {
      //Serial.print(".");
      delay(500);
    }
  }
  while(n == -1);

  begin();
  #endif
}

/**
* @brief Connecte un client en attente
*
* @fn MonServeur::connecterClient
*
*/
void MonServeur::connecterClient()
{
  #ifdef WIFI
  int i = 0;

  // client en attente ?
  if(hasClient())
  {
    for (i = 0; i < MAX_CLIENTS; i++)
    {
      if (!clients[i] || !clients[i].connected())
      {
        if (clients[i])
        {
          clients[i].stop();
        }
        clients[i] = available();
        #ifdef DEBUG
          Serial.print(i+1);
          Serial.print(F(" - Nouveau client : "));
          Serial.print(clients[i].remoteIP());
          Serial.print(F(":"));
          Serial.print(clients[i].remotePort());
          Serial.println(F(""));
        #endif
        break;
      }
    }
    // plus de place ?
    if (i == MAX_CLIENTS)
    {
      WiFiClient wifiClient = available();
      wifiClient.stop();
      #ifdef DEBUG
        Serial.println(F("Connexion rejetée !"));
      #endif
    }
  }
  #endif
}

/**
* @brief Envoie un message à tous les clients connectés
*
* @fn MonServeur::envoyer
*
* @param message String le message à envoyer
*/
void MonServeur::envoyer(String message)
{
  // seulement à l'expiration de la période ?
  if(!estEcheance(periode))
    return;
  #ifdef WIFI
  // pour tous les clients connectés
  for (int i = 0; i < MAX_CLIENTS; i++)
  {
    if (clients[i] && clients[i].connected())
    {
      #ifdef DEBUG
        Serial.print(F("Envoi client "));
        Serial.print(clients[i].remoteIP());
        Serial.print(F(":"));
        Serial.print(clients[i].remotePort());
        Serial.println(F(""));
      #endif
      clients[i].print(message);
    }
  }
  #endif
  #ifdef RS232
  Serial.print(message);
  #endif
  #ifdef BLUETOOTH
  ESPBluetooth.print(message);
  #endif
}

/**
* @brief Réceptionne une requête client
*
* @fn MonServeur::lireRequete
*
* @return bool true si une requête valide a été lue
*/
bool MonServeur::lireRequete()
{
  #ifdef WIFI
  // parcourir tous les clients connectés
  for (int i = 0; i < MAX_CLIENTS; i++)
  {
    if (clients[i] && clients[i].connected())
    {
      // des données à lire ?
      if (clients[i].available())
      {
        // récupère la requête
        String requete = clients[i].readStringUntil('\n');
        #ifdef DEBUG
          Serial.print(F("Requête client "));
          Serial.print(clients[i].remoteIP());
          Serial.print(F(":"));
          Serial.print(clients[i].remotePort());
          Serial.print(F(" -> "));
          Serial.println(requete);
        #endif
        clients[i].flush();
        requete.trim();
        bool etat = verifierRequete(requete);
        // requête connue et la pécédente a été traité ?
        if(etat && this->requete.traite)
        {
          // alors on la mémorise
          //this->requete.client = clients[i];
          this->requete.numeroClient = i;
          this->requete.requete = requete;
          this->requete.traite = false;
        }
        else
        {
          repondreRequete("ERREUR\n");
        }
        return etat;
      }
    }
  }
  #endif

  #ifdef RS232
  while (Serial.available())
  {
    String requete = Serial.readStringUntil('\n');
    requete.trim();
    bool etat = verifierRequete(requete);
    if(etat && this->requete.traite)
    {
      // alors on la mémorise
      this->requete.requete = requete;
      this->requete.traite = false;
    }
    else
    {
      repondreRequete("ERREUR\n");
    }
    return etat;
  }
  #endif

  #ifdef BLUETOOTH
  while (ESPBluetooth.available())
  {
    String requete = ESPBluetooth.readStringUntil('\n');
    requete.trim();
    bool etat = verifierRequete(requete);
    if(etat && this->requete.traite)
    {
      // alors on la mémorise
      this->requete.requete = requete;
      this->requete.traite = false;
    }
    else
    {
      repondreRequete("ERREUR\n");
    }
    return etat;
  }
  #endif

  return false;
}

/**
* @brief Récupère la dernière requête d'un client
*
* @fn MonServeur::recupererRequete
*
* @return String la dernière requête d'un client
*/
String MonServeur::recupererRequete() const
{
  return requete.requete;
}

/**
* @brief Répond à la dernière requête du client
*
* @fn MonServeur::repondreRequete
*
* @param message String le réponse envoyée au client
*/
void MonServeur::repondreRequete(String message)
{
  #ifdef WIFI
  // client existant et connecté ?
  if (clients[this->requete.numeroClient] && clients[this->requete.numeroClient].connected())
  {
    #ifdef DEBUG
      Serial.print(F("Réponse client "));
      Serial.print(clients[this->requete.numeroClient].remoteIP());
      Serial.print(F(":"));
      Serial.print(clients[this->requete.numeroClient].remotePort());
      Serial.println(F(""));
    #endif
    clients[this->requete.numeroClient].print(message);
    // requête traitée
    this->requete.traite = true;
  }
  #endif
  #ifdef RS232
  Serial.print(message);
  // requête traitée
  this->requete.traite = true;
  #endif
  #ifdef BLUETOOTH
  ESPBluetooth.print(message);
  // requête traitée
  this->requete.traite = true;
  #endif
}

/**
* @brief Vérifie si la requête respecte le protocole
*
* @fn MonServeur::verifierRequete
*
* @return bool true si la requête est valide sinon false
*/
bool MonServeur::verifierRequete(String requete)
{
  requete.toUpperCase();
  // requête valide ?
  if(requete.startsWith("SET"))
  {
    if(requete.indexOf("LED") != -1)
    {
      return true;
    }
  }
  return false;
}

// Méthodes privées

/**
* @brief Active le WiFi
*
* @fn MonServeur::activerWifi
*
*/
void MonServeur::activerWifi()
{
  #ifdef WIFI
  delay(10);
  Serial.println();
  #ifdef DEBUG
    Serial.print(F("Connexion à "));
    Serial.println(SSIDWifi);
  #endif

  if (WiFi.status() == WL_CONNECTED)
  {
    WiFi.disconnect();
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.persistent(false);
    WiFi.mode(WIFI_OFF);
    WiFi.mode(WIFI_STA);

    if(!dhcp)
    {
      if (!WiFi.config(monAdresseIP, maPasserelle, monMasque, monDNSPrimaire, monDNSSecondaire))
      {
        #ifdef DEBUG
          Serial.println(F("Erreur adressage statique !"));
        #endif
      }
    }

    WiFi.begin((char *)SSIDWifi.c_str(), (char *)PasswordWifi.c_str());
  }

  nbTentatives = 0;
  while (WiFi.status() != WL_CONNECTED && nbTentatives < NB_TENTATIVES_WIFI)
  {
    delay(ATTENTE_RECONNEXION_WIFI);
    #ifdef DEBUG
      Serial.print(F("."));
    #endif
    nbTentatives++;
  }

  if (nbTentatives >= NB_TENTATIVES_WIFI)
  {
    #ifdef DEBUG
      Serial.println(F("Redémarrage ..."));
    #endif
    ESP.restart();
  }

  #ifdef DEBUG
    Serial.println(F(""));
    Serial.print(F("Connecté à "));
    Serial.println(SSIDWifi);
    Serial.print(F("Adresse IP : "));
    Serial.println(WiFi.localIP());
    Serial.print(F("Port : "));
    Serial.println(port);
    Serial.print(F("Adresse MAC : "));
    Serial.println(WiFi.macAddress());
  #endif

  adresseIP = WiFi.localIP().toString();
  #endif
}

/**
* @brief Recherche et sélectionne un réseau WiFi
*
* @fn MonServeur::detecterWLAN
*
* @param ssid const char* le SSID du réseau WiFi à joindre
* @param password const char* le mot de passe associé au SSID
*/
int MonServeur::detecterWLAN(const char *ssid, const char *password)
{
  int nb = -1;
  #ifdef WIFI
  nb = WiFi.scanNetworks();
  #ifdef DEBUG
    Serial.print(F("Nb réseaux : "));
    Serial.println(nb);
  #endif
  if (nb == 0)
  {
    #ifdef DEBUG
      Serial.println(F("Aucun réseau !"));
    #endif
    return -1;
  }
  else
  {
    for (int i = 0; i < nb; ++i)
    {
      if((String(WiFi.SSID(i)) == String(ssid)))
      {
        SSIDWifi = String(WiFi.SSID(i));
        if(strlen(password) > 0)
        {
          PasswordWifi = String(password);
        }
        #ifdef MODE_DETECTION_WLAN
        else
        {
          Serial.print(F("Saisir le mot de passe pour le réseau "));
          Serial.print(SSIDWifi);
          Serial.print(F(" : "));
          PasswordWifi = saisirPassword();
        }
        #endif
        return 0;
      }
    }
    #ifdef MODE_DETECTION_WLAN
    for (int i = 0; i < nb; ++i)
    {
      Serial.print(i + 1);
      Serial.print(F(": "));
      Serial.print(WiFi.SSID(i));
      Serial.print(F(" ("));
      Serial.print(WiFi.RSSI(i));
      Serial.print(F(")"));
      //Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
      Serial.println(F(""));
      delay(10);
    }
    #endif
  }
  #ifdef DEBUG
    Serial.println(F(""));
  #endif
  #endif
  return nb;
}

#ifdef MODE_DETECTION_WLAN
/**
* @brief Saisie d'un numéro de réseau WiFi
*
* @fn MonServeur::saisirNumeroReseau
*
* @return int le numéro de réseau choisi
*/
int MonServeur::saisirNumeroReseau()
{
  int numero = 0;

  #ifdef WIFI
  while (!Serial.available());
  do
  {
     byte c = Serial.read();
     if(isdigit(c))
     {
        numero *= 10;
        numero += c - '0';
     }
     delay(10);
  }
  while (Serial.available() && numero == 0);
  #endif

  return numero;
}

/**
* @brief Saisie d'un mot de passe
*
* @fn MonServeur::saisirPassword
*
* @return String le mot de passe saisi
*/
String MonServeur::saisirPassword()
{
  int pos = 0;
  char saisie[MAX_LENGTH_PASSWORD+1];
  bool fini = false;

  #ifdef WIFI
  while (!Serial.available());
  do
  {
    byte c = Serial.read();
    switch (c)
    {
    case '\n':
      saisie[pos] = 0; // fin de chaîne
      pos = 0;
      fini = true;
      break;
    case '\r':
      break;
    default:
      if (pos < MAX_LENGTH_PASSWORD)
        saisie[pos++] = c;
      break;
    }
    delay(10);
  }
  while (Serial.available() && !fini);

  if(!fini)
  {
    if (pos > 0 && pos < MAX_LENGTH_PASSWORD)
      saisie[pos] = 0;
    else
      saisie[MAX_LENGTH_PASSWORD] = 0;
  }
  #endif

  return String(saisie);
}

/**
* @brief Sélectionne un réseau WiFi
*
* @fn MonServeur::selectionnerWLAN
*
* @param n int numéro de réseau
* @param ssid const char* le SSID du réseau WiFi à joindre
* @param password const char* le mot de passe associé au SSID
*
* @return bool true si le réseau a été correctement sélectionné
*/
bool MonServeur::selectionnerWLAN(int n, const char *ssid, const char *password)
{
  int numero = 0;
  bool valide = false;

  #ifdef WIFI
  if (n == 0)
  {
    return false;
  }
  else
  {
    do
    {
      Serial.print(F("Choisir un réseau : "));
      numero = saisirNumeroReseau();
      if(numero > 0 && numero <= n)
      {
        Serial.print(F("Réseau sélectionné : "));
        Serial.print(WiFi.SSID(numero-1));
        Serial.println(F(""));
        if((String(WiFi.SSID(numero-1)) == String(ssid)))
        {
          SSIDWifi = String(WiFi.SSID(numero-1));
          if(strlen(password) > 0)
          {
            PasswordWifi = String(password);
          }
          else
          {
            Serial.println(F(""));
            Serial.print(F("Saisir le mot de passe : "));
            PasswordWifi = saisirPassword();
          }
        }
        else
        {
          SSIDWifi = String(WiFi.SSID(numero-1));
          Serial.println(F(""));
          Serial.print(F("Saisir le mot de passe : "));
          PasswordWifi = saisirPassword();
        }
        valide = true;
      }
      else
        Serial.println(F("Numéro de réseau invalide !"));
    }
    while(!valide);
  }
  #endif

  return true;
}
#endif 

/**
* @brief Retourne true si l'échéance de la période fixée a été atteinte
*
* @fn MonServeur::estEcheance
*
* @param intervalle unsigned long l'intervalle de temps en millisecondes entre deux échéances
*
* @return bool vrai si l'échéance de la période a été atteinte
*/
bool MonServeur::estEcheance(unsigned long intervalle)
{
    unsigned long temps = millis();
    if (temps - tempsPrecedent >= intervalle)
    {
        tempsPrecedent = temps;
        return true;
    }
    return false;
}
