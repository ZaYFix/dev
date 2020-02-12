#include <QMessageBox>

#include <QDebug>

#include "ihm.h"
#include "ui_ihm.h"
#include "nouvelleruche.h"
#include "reglageruche.h"

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

ihm::~ihm()
{
    delete nouvelleRucheIHM;
    delete reglageRucheIHM;
    delete ui;
}

void ihm::on_pushButton_ruches_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton_ruches->setIcon(QIcon(":/ruches.png"));

    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques_gris.png"));
    ui->pushButton_alertes->setIcon(QIcon(":/alertes_gris.png"));
}

void ihm::on_pushButton_mesures_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->pushButton_ruches->setIcon(QIcon(":/ruches_gris.png"));
    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques_gris.png"));
    ui->pushButton_alertes->setIcon(QIcon(":/alertes_gris.png"));
}

void ihm::on_pushButton_tableaux_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

    ui->pushButton_ruches->setIcon(QIcon(":/ruches_gris.png"));
    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques_gris.png"));
    ui->pushButton_alertes->setIcon(QIcon(":/alertes_gris.png"));
}

void ihm::on_pushButton_graphiques_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques.png"));

    ui->pushButton_ruches->setIcon(QIcon(":/ruches_gris.png"));
    ui->pushButton_alertes->setIcon(QIcon(":/alertes_gris.png"));
}

void ihm::on_pushButton_alertes_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->pushButton_alertes->setIcon(QIcon(":/alertes.png"));

    ui->pushButton_ruches->setIcon(QIcon(":/ruches_gris.png"));
    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques_gris.png"));
}

void ihm::on_pushButton_nouvelle_ruche_clicked()
{
    nouvelleRucheIHM->exec();
}

void ihm::on_pushButton_reglage_clicked()
{
    reglageRucheIHM->exec();
}

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

void ihm::demarrerGraphiques()
{
    graphiqueTemperature();
    //graphiqueHumidite();
    //graphiqueLuminosite();
    //graphiquePression();
    //graphiquePoids();
    //graphiqueActivite();
}

void ihm::graphiqueTemperature()
{
    QLineSeries *temperatureInterieure = new QLineSeries();
    temperatureInterieure->setName("Température intérieure");
    temperatureInterieure->append(0, 27);
    temperatureInterieure->append(1, 26);
    temperatureInterieure->append(2, 28);
    temperatureInterieure->append(3, 31);
    temperatureInterieure->append(4, 24);

    QLineSeries *temperatureExterieure = new QLineSeries();
    temperatureExterieure->setName("Température extérieure");
    temperatureExterieure->append(0, 35);
    temperatureExterieure->append(1, 37);
    temperatureExterieure->append(2, 35);
    temperatureExterieure->append(3, 34);
    temperatureExterieure->append(4, 31);

    QChart *chart = new QChart();
    chart->legend()->show();
    //chart->legend()->setAlignment(Qt::AlignBottom);
    chart->addSeries(temperatureInterieure);
    chart->addSeries(temperatureExterieure);
    chart->createDefaultAxes();
    chart->setTitle("Températures intérieure et extérieure");
    ui->chartView_temperature->setChart(chart);
    ui->chartView_temperature->setRenderHint(QPainter::Antialiasing);
}

void ihm::setValeurGraphique(QLineSeries *serie, int x, int y)
{
    serie->append(x,y);
}

void ihm::demarrerGraphiquesBatons()
{
    graphiqueBatonTemperatureInterieure();
    graphiqueBatonTemperatureExterieure();
}

void ihm::graphiqueBatonTemperatureInterieure()
{
    QBarSet *set0 = new QBarSet("Température Intérieure");
    *set0 << 24;

    QBarSeries *series = new QBarSeries();
    series->append(set0);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,50);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    ui->chartView_baton_temperature_interieure->setChart(chart);
}

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
    axisY->setRange(0,50);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    ui->chartView_baton_temperature_exterieure->setChart(chart);
}

void ihm::demarrerTableauAlertes()
{

}
