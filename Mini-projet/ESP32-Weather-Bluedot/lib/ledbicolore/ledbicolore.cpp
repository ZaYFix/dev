/**
*
* @file lib/ledbicolore/ledbicolore.cpp
*
* @brief Définition de la classe LedBicolore
*
* @author Thierry Vaira
*
* @version 0.1
*
*/
#include <ledbicolore.h>

/**
* @brief Constructeur de la classe LedBicolore
*
* @fn LedBicolore::LedBicolore
*
* @param brocheGPIORouge int broche GPIO pour la led rouge
* @param brocheGPIOVerte int broche GPIO pour la led verte
*/
LedBicolore::LedBicolore(int brocheGPIORouge, int brocheGPIOVerte) : brocheGPIORouge(brocheGPIORouge), brocheGPIOVerte(brocheGPIOVerte), etatLedRouge(false), etatLedVerte(false), etat(false), couleur(Aucune), valide(false)
{
}

/**
* @brief Retourne l'état de la validité de la requête du client
*
* @fn LedBicolore::estValide
*
* @return bool la validité de la requête du client
*/
bool LedBicolore::estValide() const
{
  return valide;
}

/**
* @brief Retourne l'état allumée ou éteinte de la Led
*
* @fn LedBicolore::getEtat
*
* @return bool état allumée ou éteinte de la Led
*/
bool LedBicolore::getEtat() const
{
  return etat;
}

/**
* @brief Retourne la couleur courante de la Led
*
* @fn LedBicolore::getCouleur
*
* @return Couleur la couleur courante de la Led
*/
Couleur LedBicolore::getCouleur() const
{
  return couleur;
}

/**
* @brief Retourne les données en suivant le protocole
*
* @fn LedBicolore::getDonnees
*
* @return String les données formatées au protocole choisi
*/
String LedBicolore::getDonnees() const
{
  String donnees;
  //LedRouge;LedVerte;Etat;Couleur;\r\n
  donnees = "LED;" + String(etatLedRouge) + ";" + String(etatLedVerte) + ";" + String(etat) + ";" + String((int)couleur) + ";" + "\r\n";
  return donnees;
}

/**
* @brief Initialise les broches GPIO de la led
*
* @fn LedBicolore::initialiser
*
*/
void LedBicolore::initialiser()
{
  pinMode(brocheGPIORouge, OUTPUT);
  pinMode(brocheGPIOVerte, OUTPUT);
}

/**
* @brief Commande l'état de la led rouge
*
* @fn LedBicolore::commanderLedRouge
*
* @param etat bool allumée ou éteinte
*/
void LedBicolore::commanderLedRouge(bool etat)
{
  if(etat)
  {
    digitalWrite(brocheGPIORouge, HIGH);   // on
    etatLedRouge = true;
  }
  else
  {
    digitalWrite(brocheGPIORouge, LOW);   // off
    etatLedRouge = false;
  }
}

/**
* @brief Commande l'état de la led verte
*
* @fn LedBicolore::commanderLedVerte
*
* @param etat bool allumée ou éteinte
*/
void LedBicolore::commanderLedVerte(bool etat)
{
  if(etat)
  {
    digitalWrite(brocheGPIOVerte, HIGH);   // on
    etatLedVerte = true;
  }
  else
  {
    digitalWrite(brocheGPIOVerte, LOW);   // off
    etatLedVerte = false;
  }
}

/**
* @brief Allume la led
*
* @fn LedBicolore::allumer
*
* @param couleur Couleur la couleur demandée
*/
void LedBicolore::allumer(Couleur couleur)
{
  switch(couleur)
  {
    case Aucune:
      commanderLedRouge(false);
      commanderLedVerte(false);
      this->couleur = Aucune;
      etat = false;
      break;
    case Rouge:
      commanderLedRouge(true);
      commanderLedVerte(false);
      this->couleur = Rouge;
      etat = true;
      break;
    case Vert:
      commanderLedRouge(false);
      commanderLedVerte(true);
      this->couleur = Vert;
      etat = true;
      break;
    case Orange:
      commanderLedRouge(true);
      commanderLedVerte(true);
      this->couleur = Orange;
      etat = true;
      break;
    default:
      commanderLedRouge(false);
      commanderLedVerte(false);
      this->couleur = Aucune;
      etat = false;
  }
}

/**
* @brief Eteint la led
*
* @fn LedBicolore::eteindre
*
*/
void LedBicolore::eteindre()
{
  allumer(Aucune);
}

/**
* @brief Traite une requête client
*
* @fn LedBicolore::traiterRequete
*
* @param requete String la requête d'un client à traiter
* @return String la réponse à renvoyer au client
*/
String LedBicolore::traiterRequete(String requete)
{
  String reponse;

  valide = false;
  requete.toUpperCase();
  if(requete.indexOf("LED ON") != -1)
  {
    allumer(couleur);
    valide = true;
  }
  if(requete.indexOf("LED OFF") != -1 || requete.indexOf("LED 0") != -1)
  {
    eteindre();
    valide = true;
  }
  if(requete.indexOf("LED 1") != -1 || requete.indexOf("LED ROUGE") != -1)
  {
    allumer(Rouge);
    valide = true;
  }
  if(requete.indexOf("LED 2") != -1 || requete.indexOf("LED VERT") != -1)
  {
    allumer(Vert);
    valide = true;
  }
  if(requete.indexOf("LED 3") != -1 || requete.indexOf("LED ORANGE") != -1)
  {
    allumer(Orange);
    valide = true;
  }

  // retour la réponse à envoyée au serveur
  if(valide)
  {
    reponse = "OK\n";
  }
  else
  {
    reponse = "ERREUR\n";
  }
  return reponse;
}
