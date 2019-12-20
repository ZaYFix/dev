#include "Ihm.h"
#include "ui_ihm.h"
#include <QDebug>

IHM::IHM(QWidget *parent) : QWidget(parent), ui(new Ui::IHM), supervision(new Supervision(this))
{
    ui->setupUi(this);
}

IHM::~IHM()
{
    delete ui;
}

void IHM::afficherTemperature(double temperature, QString uniteTemperature)
{
    ui->affichageTemperature->display(temperature);
    ui->uniteTemperature->setText(QString::fromUtf8("°") + uniteTemperature);
    qDebug() << Q_FUNC_INFO << "Température" << temperature << uniteTemperature;
}

void IHM::afficherTemperatureRessentie(double temperatureRessentie, QString uniteTemperatureRessentie)
{
    ui->affichageTemperature->display(temperatureRessentie);
    ui->uniteTemperature->setText(QString::fromUtf8("°") + uniteTemperatureRessentie);
    qDebug() << Q_FUNC_INFO << "Température Ressentie" << temperatureRessentie << uniteTemperatureRessentie;
}

void IHM::afficherHumidite(unsigned int humidite, QString uniteHumidite)
{
    //ui->affichageHumidite->display(humidite);
    ui->uniteTemperature->setText(QString::fromUtf8("°") + uniteHumidite);
    qDebug() << Q_FUNC_INFO << "Humidité" << humidite << uniteHumidite;
}

void IHM::afficherLuminosite(unsigned int luminosite, QString uniteLuminosite)
{
    //ui->affichageLuminosite->display(luminosite);
    ui->uniteTemperature->setText(QString::fromUtf8("°") + uniteLuminosite);
    qDebug() << Q_FUNC_INFO << "Luminosité" << luminosite << uniteLuminosite;
}

void IHM::afficherPression(unsigned int pression, QString unitePression)
{
    //ui->affichagePression->display(pression);
    ui->uniteTemperature->setText(QString::fromUtf8("°") + unitePression);
    qDebug() << Q_FUNC_INFO << "Pression" << pression << unitePression;
}

void IHM::afficherAltitude(int altitude, QString uniteAltitude)
{
    ui->affichageAltitude->display(altitude);
    ui->uniteTemperature->setText(QString::fromUtf8("°") + uniteAltitude);
    qDebug() << Q_FUNC_INFO << "Altitude" << altitude << uniteAltitude;
}
