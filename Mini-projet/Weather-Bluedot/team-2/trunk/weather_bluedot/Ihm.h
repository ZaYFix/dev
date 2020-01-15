#ifndef IHM_H
#define IHM_H

#include "Supervision.h"
#include <QWidget>

class Supervision;

namespace Ui {
class IHM;
}

/**
* @file     Ihm.h
* @brief    Définition de la classe IHM
* @author   ACKERMANN Théo
* @author   LEGGER Pierre-Antoine
* @version  1.0
*/
class IHM : public QWidget
{
    Q_OBJECT

public:

    explicit IHM(QWidget *parent = nullptr);
    ~IHM();

public slots:

    void afficherTrame(QString trame);
    void afficherTemperature(double temperature, QString uniteTemperature);
    void afficherTemperatureRessentie(double temperatureRessentie, QString uniteTemperatureRessentie);
    void afficherHumidite(double humidite, QString uniteHumidite);
    void afficherLuminosite(double luminosite, QString uniteLuminosite);
    void afficherPression(double pression, QString unitePression);
    void afficherAltitude(double altitude, QString uniteAltitude);
    void ledAllumee();
    void ledEteinte();
    void ledCouleurRouge();
    void ledCouleurVerte();
    void ledCouleurOrange();

private:
    Ui::IHM *ui; /**< Pointeur vers l'interface graphique */
    Supervision *supervision; /**< Pointeur vers la classe Supervision */
    int valeurBoutton; /**< Variable qui contient la valeur du boutton démarrer */



private slots:

    void on_pushButton_orange_clicked();
    void on_pushButton_vert_clicked();
    void on_pushbutton_rouge_clicked();
    void on_pushButton_eteindre_clicked();
    void on_pushbutton_demarrer_clicked();
    void on_pushButton_confirmerPortSerie_clicked();
    void on_rafraichirListePortSerie_clicked();

signals:
    /**
     * @brief Signal qui permet de changer la couleur de la LED
     *
     * @param couleur
     */
    void changerCouleurLED(QString couleur);
};

#endif // IHM_H
