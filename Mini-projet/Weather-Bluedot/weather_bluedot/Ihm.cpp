#include "Ihm.h"
#include "ui_ihm.h"
#include <QDebug>
#include <QMessageBox>
#include <QTime>

/**
 * @file    Ihm.cpp
 * @brief   Déclaration de la classe Ihm
 * @author  ACKERMANN Théo
 * @author  LEGGER Pierre-Antoine
 * @version 1.0
 */

/**
* @brief Constructeur de la classe IHM
* @fn IHM::IHM
* @param parent
*/
IHM::IHM(QWidget *parent) : QWidget(parent), ui(new Ui::IHM), supervision(new Supervision(this)), valeurBoutton(0)
{
    ui->setupUi(this);
}

/**
* @brief Destructeur de la classe IHM
* @fn IHM::IHM
*/
IHM::~IHM()
{
    delete ui;
}

/**
 * @brief IHM::afficherTrame
 * @fn IHM::afficherTrame
 * @param trame
 */
void IHM::afficherTrame(QString trame)
{
    QTime heureActuel = heureActuel.currentTime();
    ui->affichageTrame->append("[ " + heureActuel.toString() + " ]");
    ui->affichageTrame->append(trame);

}

/**
 * @brief Méthode qui affiche la valeur de la température sur l'IHM
 * @fn IHM::afficherTemperature
 * @param temperature
 * @param uniteTemperature
 */
void IHM::afficherTemperature(double temperature, QString uniteTemperature)
{
    ui->affichageTemperature->display(temperature);
    ui->uniteTemperature->setText(QString::fromUtf8("°") + uniteTemperature);
    qDebug() << Q_FUNC_INFO << "Température" << temperature << uniteTemperature;
}

/**
 * @brief Méthode qui affiche la valeur de la température ressentie sur l'IHM
 * @fn IHM::afficherTemperatureRessentie
 * @param temperatureRessentie
 * @param uniteTemperatureRessentie
 */
void IHM::afficherTemperatureRessentie(double temperatureRessentie, QString uniteTemperatureRessentie)
{
    ui->affichageTemperatureRessentie->display(temperatureRessentie);
    ui->uniteTemperatureRessentie->setText(QString::fromUtf8("°") + uniteTemperatureRessentie);
    qDebug() << Q_FUNC_INFO << "Température Ressentie" << temperatureRessentie << uniteTemperatureRessentie;
}

/**
 * @brief Méthode qui affiche la valeur de l'humidité sur l'IHM
 * @fn IHM::afficherHumidite
 * @param humidite
 * @param uniteHumidite
 */
void IHM::afficherHumidite(double humidite, QString uniteHumidite)
{
    ui->affichageHumidite->display(humidite);
    ui->uniteHumidite->setText(uniteHumidite);
    qDebug() << Q_FUNC_INFO << "Humidité" << humidite << uniteHumidite;
}

/**
 * @brief Méthode qui affiche la valeur de la luminosité sur l'IHM
 * @fn IHM::afficherLuminosite
 * @param luminosite
 * @param uniteLuminosite
 */
void IHM::afficherLuminosite(double luminosite, QString uniteLuminosite)
{
    ui->affichageLuminosite->display(luminosite);
    ui->uniteLuminosite->setText(uniteLuminosite);
    qDebug() << Q_FUNC_INFO << "Luminosité" << luminosite << uniteLuminosite;
}

/**
 * @brief Méthode qui affiche la valeur de la pression sur l'IHM
 * @fn IHM::afficherPression
 * @param pression
 * @param unitePression
 */
void IHM::afficherPression(double pression, QString unitePression)
{
    ui->affichagePression->display(pression);
    ui->unitePression->setText(unitePression);
    qDebug() << Q_FUNC_INFO << "Pression" << pression << unitePression;
}

/**
 * @brief Méthode qui affiche la valeur de l'altitude sur l'IHM
 * @fn IHM::afficherAltitude
 * @param altitude
 * @param uniteAltitude
 */
void IHM::afficherAltitude(double altitude, QString uniteAltitude)
{
    ui->affichageAltitude->display(altitude);
    ui->uniteAltitude->setText(uniteAltitude);
    qDebug() << Q_FUNC_INFO << "Altitude" << altitude << uniteAltitude;
}

/**
 * @brief Méthode qui émet un signal pour changer la couleur de la LED en rouge
 * @fn IHM::on_pushbutton_rouge_clicked
 */
void IHM::on_pushbutton_rouge_clicked()
{
    emit changerCouleurLED("1");
}

/**
 * @brief Méthode qui émet un signal pour changer la couleur de la LED en vert
 * @fn IHM::on_pushButton_vert_clicked
 */
void IHM::on_pushButton_vert_clicked()
{
    emit changerCouleurLED("2");
}

/**
 * @brief Méthode qui émet un signal pour changer la couleur de la LED en orange
 * @fn IHM::on_pushButton_orange_clicked
 */
void IHM::on_pushButton_orange_clicked()
{
    emit changerCouleurLED("3");
}

/**
 * @brief Méthode qui émet un signal pour éteindre la LED
 * @fn IHM::on_pushButton_eteindre_clicked
 */
void IHM::on_pushButton_eteindre_clicked()
{
    emit changerCouleurLED("0");
}

/**
 * @brief Méthode qui modifie un texte pour informer l'état de la LED
 * @fn IHM::ledAllumee
 */
void IHM::ledAllumee()
{
    ui->etatLED->setText("allumée");
    ui->texteCouleurLED->setText("et est de couleur");
}

/**
 * @brief Méthode qui modifie un texte pour informer l'état de la LED
 * @fn IHM::ledEteinte
 */
void IHM::ledEteinte()
{
    ui->etatLED->setText("éteinte");
    ui->texteCouleurLED->setText("\0");
    ui->couleurLED->setText("\0");
}

/**
 * @brief Méthode qui modifie un texte pour informer que la LED est de couleur rouge
 * @fn IHM::ledCouleurRouge
 */
void IHM::ledCouleurRouge()
{
    ui->couleurLED->setText("rouge.");
}

/**
 * @brief Méthode qui modifie un texte pour informer que la LED est de couleur verte
 * @fn IHM::ledCouleurVerte
 */
void IHM::ledCouleurVerte()
{
    ui->couleurLED->setText("verte.");
}

/**
 * @brief Méthode qui modifie un texte pour informer que la LED est de couleur orange
 * @fn IHM::ledCouleurOrange
 */
void IHM::ledCouleurOrange()
{
    ui->couleurLED->setText("orange.");
}

/**
 * @brief Méthode qui vérifie si le port série a été définie avant de démarrer la liaison série
 * @fn IHM::on_pushbutton_demarrer_clicked
 */
void IHM::on_pushbutton_demarrer_clicked()
{
    if(ui->port_serie->text().isEmpty())
    {
        QMessageBox::warning(
            this,
            tr("Weather Bluedot"),
            tr("Veuillez d'abord choisir un port série.") );
    }
    else
    {
        switch(valeurBoutton)
        {
            case 0:
                ui->pushbutton_demarrer->setText("STOP");
                ui->pushbutton_demarrer->setStyleSheet("background-color:rgb(255,0,0)");
                supervision->demarrerCommunicationPort();
                valeurBoutton = 1;
            break;
            case 1:
                ui->pushbutton_demarrer->setText("DÉMARRER");
                ui->pushbutton_demarrer->setStyleSheet("background-color:rgb(0,128,0)");
                supervision->arreterCommunicationPort();
                valeurBoutton = 0;
            break;
        }
    }

}

/**
 * @brief Méthode qui définie le nouveau port série
 * @fn IHM::on_pushButton_confirmerPortSerie_clicked
 */
void IHM::on_pushButton_confirmerPortSerie_clicked()
{
    QString nouveauPortSerie = ui->port_serie->text();
    supervision->setNouveauPortSerie(nouveauPortSerie);
}

/**
 * @brief Méthode qui rafraichie la liste de port série
 * @fn IHM::on_rafraichirListePortSerie_clicked
 */
void IHM::on_rafraichirListePortSerie_clicked()
{
    ui->listePortSerie->setText(supervision->rafraichirListePortSerie());
}
