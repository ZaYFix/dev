#include "Ihm.h"
#include "ui_ihm.h"
#include <QDebug>
#include <QMessageBox>
#include <QStyleFactory>

/**
 * @brief Constructeur de la classe Ihm
 *
 * @param parent
 */
IHM::IHM(QWidget *parent) : QWidget(parent), ui(new Ui::IHM), supervision(new Supervision(this)), valeurBoutton(0)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":weather.png"));
}

/**
 * @brief Destructeur de la classe Ihm
 *
 */
IHM::~IHM()
{
    delete ui;
}

/**
 * @brief Méthode qui affiche la valeur de la température sur l'IHM
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
 */
void IHM::on_pushbutton_rouge_clicked()
{
    emit changerCouleurLED("1");
}

/**
 * @brief Méthode qui émet un signal pour changer la couleur de la LED en vert
 *
 */
void IHM::on_pushButton_vert_clicked()
{
    emit changerCouleurLED("2");
}

/**
 * @brief Méthode qui émet un signal pour changer la couleur de la LED en orange
 *
 */
void IHM::on_pushButton_orange_clicked()
{
    emit changerCouleurLED("3");
}

/**
 * @brief Méthode qui émet un signal pour éteindre la LED
 *
 */
void IHM::on_pushButton_eteindre_clicked()
{
    emit changerCouleurLED("0");
}

/**
 * @brief Méthode qui vérifie si le port série a été définie avant de démarrer la liaison série
 *
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
 *
 */
void IHM::on_pushButton_confirmerPortSerie_clicked()
{
    QString nouveauPortSerie = ui->port_serie->text();
    supervision->setNouveauPortSerie(nouveauPortSerie);
}

/**
 * @brief Méthode qui rafraichie la liste de port série
 *
 */
void IHM::on_rafraichirListePortSerie_clicked()
{
    ui->listePortSerie->setText(supervision->rafraichirListePortSerie());
}
