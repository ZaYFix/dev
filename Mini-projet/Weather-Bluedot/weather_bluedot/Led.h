#ifndef LED_H
#define LED_H

#include <QObject>

/**
* @file     Led.h
* @brief    Définition de la classe Led
* @details  La classe LED permet de connaitre l'état et la couleur de la LED
* @author   ACKERMANN Théo
* @author   LEGGER Pierre-Antoine
* @version  1.0
*/
class Led : public QObject
{
    Q_OBJECT

public:

    Led(QObject *parent = nullptr);
    ~Led();

public slots:

    void extraireEtatLed(QString const trameBrut);
    void deduireEtatLed(int etat, int couleur);

private:
    unsigned int ledRouge; /**<  Variable qui stocke la valeur de la led rouge          */
    unsigned int ledVerte; /**<  Variable qui stocke la valeur de la led verte          */
    unsigned int etat;     /**<  Variable qui stocke la valeur de l'état de la led      */
    unsigned int couleur;  /**<  Variable qui stocke la valeur de la couleur de la led  */

signals:
    /**
     * @brief Méthode qui émet un signal qui indique que la led est allumée
     *
     */
    void ledAllumee();
    /**
     * @brief Méthode qui émet un signal qui indique que la led est éteinte
     *
     */
    void ledEteinte();
    /**
     * @brief Méthode qui émet un signal qui indique que la led est allumée en rouge
     *
     */
    void ledCouleurRouge();
    /**
     * @brief Méthode qui émet un signal qui indique que la led est allumée en verte
     *
     */
    void ledCouleurVerte();
    /**
     * @brief Méthode qui émet un signal qui indique que la led est allumée en orange
     *
     */
    void ledCouleurOrange();
};

#endif // LED_H
