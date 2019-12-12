/**
*
* @file lib/ledbicolore/ledbicolore.h
*
* @brief Déclaration de la classe LedBicolore
*
* @author Thierry Vaira
*
* @version 0.1
*
*/
#ifndef LEDBICOLORE_H
#define LEDBICOLORE_H

#include <Arduino.h>

#define GPIO_LED_ROUGE_DEFAUT 17 //<! Broche GPIO de led rouge
#define GPIO_LED_VERTE_DEFAUT 16 //<! Broche GPIO de led verte

/**
 * @enum Couleur
 *
 * @brief Précise les couleurs possible pour une Led bicolore
 *
 */
enum Couleur { Aucune, Rouge, Vert, Orange };

/**
* @class LedBicolore
*
* @brief Déclaration de la classe Led qui permet de commander une Led bicolore
*
* @author Thierry Vaira
*
* @version 0.1
*
*/
class LedBicolore
{
public:
  LedBicolore(int brocheGPIORouge=GPIO_LED_ROUGE_DEFAUT, int brocheGPIOVerte=GPIO_LED_VERTE_DEFAUT);
  bool estValide() const;
  bool getEtat() const;
  Couleur getCouleur() const;
  String getDonnees() const;
  void initialiser();
  void commanderLedRouge(bool etat);
  void commanderLedVerte(bool etat);
  void allumer(Couleur couleur);
  void eteindre();
  String traiterRequete(String requete);

private:
  int brocheGPIORouge; //!< numéro de broche de la Led Rouge
  int brocheGPIOVerte; //!< numéro de broche de la Led Verte
  bool etatLedRouge; //!< l'état allumée ou éteint de la Led Rouge
  bool etatLedVerte; //!< l'état allumée ou éteint de la Led verte
  bool etat; //!< l'état allumée ou éteint de la Led
  Couleur couleur; //!< la couleur actuelle de la Led
  bool valide; //!< état de la validité de la requête traitée
};

#endif
