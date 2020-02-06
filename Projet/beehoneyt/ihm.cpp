#include "ihm.h"
#include "ui_ihm.h"
#include "nouvelleruche.h"

ihm::ihm(QWidget *parent) :QMainWindow(parent),ui(new Ui::ihm),nvRuche(0)
{
    ui->setupUi(this);

    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques_gris.png"));
    ui->pushButton_alertes->setIcon(QIcon(":/alertes_gris.png"));

    nvRuche = new nouvelleRuche(this);
}

ihm::~ihm()
{
    delete nvRuche;
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

    ui->pushButton_graphiques->setIcon(QIcon(":/graphiques_gris.png"));
}

void ihm::on_pushButton_nouvelle_ruche_clicked()
{
    nvRuche->exec();
}
