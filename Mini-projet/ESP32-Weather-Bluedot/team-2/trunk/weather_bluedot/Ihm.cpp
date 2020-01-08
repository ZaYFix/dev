#include "Ihm.h"
#include "ui_ihm.h"
#include <QDebug>

/**
 * @brief Constructeur de la classe Ihm
 *
 * @param parent
 */
IHM::IHM(QWidget *parent) : QWidget(parent), ui(new Ui::IHM), supervision(new Supervision(this))
{
    ui->setupUi(this);
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
 * @brief Méthode qui affiche la valeur de la température
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
 * @brief Méthode qui affiche la valeur de la température ressentie
 *
 * @param temperatureRessentie
 * @param uniteTemperatureRessentie
 */
void IHM::afficherTemperatureRessentie(double temperatureRessentie, QString uniteTemperatureRessentie)
{
    ui->affichageTemperature->display(temperatureRessentie);
    ui->uniteTemperature->setText(QString::fromUtf8("°") + uniteTemperatureRessentie);
    qDebug() << Q_FUNC_INFO << "Température Ressentie" << temperatureRessentie << uniteTemperatureRessentie;
}

/**
 * @brief Méthode qui affiche la valeur de l'humidité
 *
 * @param humidite
 * @param uniteHumidite
 */
void IHM::afficherHumidite(unsigned int humidite, QString uniteHumidite)
{
    //ui->affichageHumidite->display(humidite);
    ui->uniteTemperature->setText(QString::fromUtf8("°") + uniteHumidite);
    qDebug() << Q_FUNC_INFO << "Humidité" << humidite << uniteHumidite;
}

/**
 * @brief Méthode qui affiche la valeur de la luminosité
 *
 * @param luminosite
 * @param uniteLuminosite
 */
void IHM::afficherLuminosite(unsigned int luminosite, QString uniteLuminosite)
{
    //ui->affichageLuminosite->display(luminosite);
    ui->uniteTemperature->setText(QString::fromUtf8("°") + uniteLuminosite);
    qDebug() << Q_FUNC_INFO << "Luminosité" << luminosite << uniteLuminosite;
}

/**
 * @brief Méthode qui affiche la valeur de la pression
 *
 * @param pression
 * @param unitePression
 */
void IHM::afficherPression(unsigned int pression, QString unitePression)
{
    //ui->affichagePression->display(pression);
    ui->uniteTemperature->setText(QString::fromUtf8("°") + unitePression);
    qDebug() << Q_FUNC_INFO << "Pression" << pression << unitePression;
}

/**
 * @brief Méthode qui affiche la valeur de l'altitude
 *
 * @param altitude
 * @param uniteAltitude
 */
void IHM::afficherAltitude(int altitude, QString uniteAltitude)
{
    ui->affichageAltitude->display(altitude);
    ui->uniteTemperature->setText(QString::fromUtf8("°") + uniteAltitude);
    qDebug() << Q_FUNC_INFO << "Altitude" << altitude << uniteAltitude;
}

void IHM::on_pushbutton_rouge_clicked()
{
    emit changerCouleurLED("1");
}

void IHM::on_pushButton_vert_clicked()
{
    emit changerCouleurLED("2");
}

void IHM::on_pushButton_orange_clicked()
{
    emit changerCouleurLED("3");
}

void IHM::on_pushButton_eteindre_clicked()
{
    emit changerCouleurLED("0");
}
