#include <QMessageBox>

#include <QDebug>

#include "ihm.h"
#include "ui_ihm.h"
#include "nouvelleruche.h"
#include "reglageruche.h"

/**
 * @file    ihm.cpp
 * @brief   Déclaration de la classe ihm
 * @author  ACKERMANN Théo
 * @version 0.1
 */

/**
 * @brief Constructeur de la classe ihm
 * @fn ihm::ihm
 * @param parent
 */
ihm::ihm(QWidget *parent) :QMainWindow(parent),ui(new Ui::ihm),nouvelleRucheIHM(0),reglageRucheIHM(0)
{
    ui->setupUi(this);

    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques_gris.png"));
    ui->pushButton_alertes->setIcon(QIcon(":/alertes_gris.png"));

    nouvelleRucheIHM = new nouvelleRuche(this);
    reglageRucheIHM = new reglageRuche(this);

    ui->comboBox_liste_ruches->addItem("Nom de la ruche");

    demarrerGraphiques();
    demarrerGraphiquesBatons();
    demarrerTableauAlertes();
}

/**
 * @brief Destructeur de la classe ihm
 * @fn ihm::~ihm
 */
ihm::~ihm()
{
    delete nouvelleRucheIHM;
    delete reglageRucheIHM;
    delete ui;
}

/**
 * @brief Bouton/icone qui permet d'aller sur l'onglet de la ruche
 * @fn ihm::on_pushButton_ruches_clicked
 */
void ihm::on_pushButton_ruches_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton_ruches->setIcon(QIcon(":/ruches.png"));

    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques_gris.png"));
    ui->pushButton_alertes->setIcon(QIcon(":/alertes_gris.png"));
}

/**
 * @brief
 *
 */
void ihm::on_pushButton_mesures_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->pushButton_ruches->setIcon(QIcon(":/ruches_gris.png"));
    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques_gris.png"));
    ui->pushButton_alertes->setIcon(QIcon(":/alertes_gris.png"));
}

/**
 * @brief
 *
 */
void ihm::on_pushButton_tableaux_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

    ui->pushButton_ruches->setIcon(QIcon(":/ruches_gris.png"));
    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques_gris.png"));
    ui->pushButton_alertes->setIcon(QIcon(":/alertes_gris.png"));
}

/**
 * @brief Bouton/icone qui permet d'aller sur l'onglet des graphiques
 *
 */
void ihm::on_pushButton_graphiques_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques.png"));

    ui->pushButton_ruches->setIcon(QIcon(":/ruches_gris.png"));
    ui->pushButton_alertes->setIcon(QIcon(":/alertes_gris.png"));
}

/**
 * @brief Bouton/icone qui permet d'aller sur l'onglet des alertes
 *
 */
void ihm::on_pushButton_alertes_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->pushButton_alertes->setIcon(QIcon(":/alertes.png"));

    ui->pushButton_ruches->setIcon(QIcon(":/ruches_gris.png"));
    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques_gris.png"));
}

/**
 * @brief Bouton qui permet d'ouvrir la fenêtre de création du nouvelle ruche
 *
 */
void ihm::on_pushButton_nouvelle_ruche_clicked()
{
    nouvelleRucheIHM->exec();
}

/**
 * @brief Bouton qui permet d'ouvrir la fenêtre des réglages de la ruche
 *
 */
void ihm::on_pushButton_reglage_clicked()
{
    reglageRucheIHM->exec();
}

/**
 * @brief Bouton qui permet de supprimer la ruche selectionné
 *
 */
void ihm::on_pushButton_supprimer_ruche_clicked()
{
    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(
        this,"","Êtes-vous sûr de vouloir supprimer la ruche ?",QMessageBox::No|QMessageBox::Yes); // Ajouter nom de la ruche

    if(reponse == QMessageBox::Yes)
        qDebug() << "Oui";
    else
        qDebug() << "Non";
}

/**
 * @brief Méthode qui initialise les graphiques
 * @fn ihm::demarrerGraphiques
 */
void ihm::demarrerGraphiques()
{
    graphiqueTemperature();
    graphiqueHumidite();
    //graphiqueLuminosite();
    //graphiquePression();
    //graphiquePoids();
    //graphiqueActivite();
}

/**
 * @brief Méthode qui initialise le graphique de température
 * @fn ihm::graphiqueTemperature
 */
void ihm::graphiqueTemperature()
{
    QLineSeries *temperatureInterieure = new QLineSeries();
    temperatureInterieure->setName("Intérieure");
    // Valeurs de test
    temperatureInterieure->append(0, 27);
    temperatureInterieure->append(1, 26);
    temperatureInterieure->append(2, 28);
    temperatureInterieure->append(3, 31);
    temperatureInterieure->append(4, 24);

    QLineSeries *temperatureExterieure = new QLineSeries();
    temperatureExterieure->setName("Extérieure");
    // Valeurs de test
    temperatureExterieure->append(0, 35);
    temperatureExterieure->append(1, 37);
    temperatureExterieure->append(2, 35);
    temperatureExterieure->append(3, 34);
    temperatureExterieure->append(4, 31);

    QChart *chart = new QChart();
    chart->legend()->show();
    chart->addSeries(temperatureInterieure);
    chart->addSeries(temperatureExterieure);

    chart->createDefaultAxes();
    chart->setTitle("Températures");
    ui->chartView_temperature->setChart(chart);
    ui->chartView_temperature->setRenderHint(QPainter::Antialiasing);

    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTickCount(7);
    axisX->setFormat("dd.MM");
    axisX->setTitleText("Jours");
    axisX->setMin(QDateTime::currentDateTime().addDays(-3));
    axisX->setMax(QDateTime::currentDateTime().addDays(3));

    //QValueAxis *axisY = new QValueAxis();
    //axisY->setMin(-10);
    //axisY->setMax(45);

    //chart->setAxisY(axisY);
    chart->setAxisX(axisX);
}

/**
 * @brief Méthode qui initialise le graphique d'humidité
 * @fn ihm::graphiqueHumidite
 */
void ihm::graphiqueHumidite()
{
    QLineSeries *humidite = new QLineSeries();
    // Valeurs de test
    humidite->append(0, 27);
    humidite->append(1, 26);
    humidite->append(2, 28);
    humidite->append(3, 31);
    humidite->append(4, 24);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(humidite);
    chart->setTitle("Humidité");
    ui->chartView_humidite->setChart(chart);
    ui->chartView_humidite->setRenderHint(QPainter::Antialiasing);

    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTickCount(7);
    axisX->setFormat("dd.MM");
    axisX->setTitleText("Jours");
    axisX->setMin(QDateTime::currentDateTime().addDays(-3));
    axisX->setMax(QDateTime::currentDateTime().addDays(3));

    QValueAxis *axisY = new QValueAxis();
    axisY->setMin(0);
    axisY->setMax(100);

    chart->setAxisY(axisY);
    chart->setAxisX(axisX);
    //humidite->attachAxis(axisX);
}

/**
 * @brief Méthode qui permet de mettre une valeur dans un graphique
 * @param serie
 * @param x
 * @param y
 */
void ihm::setValeurGraphique(QLineSeries *serie, int x, int y)
{
    serie->append(x,y);
}

/**
 * @brief
 *
 */
void ihm::demarrerGraphiquesBatons()
{
    graphiqueBatonTemperatureInterieure();
    graphiqueBatonTemperatureExterieure();
}

/**
 * @brief
 *
 */
void ihm::graphiqueBatonTemperatureInterieure()
{
    QBarSet *set0 = new QBarSet("Température Intérieure");
    *set0 << 37;

    QBarSeries *series = new QBarSeries();
    series->append(set0);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(36,40);
    axisY->setTickCount(10);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    ui->chartView_baton_temperature_interieure->setChart(chart);
}

/**
 * @brief
 *
 */
void ihm::graphiqueBatonTemperatureExterieure()
{
    QBarSet *set0 = new QBarSet("Température Extérieure");
    *set0 << 37;

    QBarSeries *series = new QBarSeries();
    series->append(set0);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,45);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    ui->chartView_baton_temperature_exterieure->setChart(chart);
}

/**
 * @brief
 *
 */
void ihm::demarrerTableauAlertes()
{

}
