#include "nouvelleruche.h"
#include "ui_nouvelleruche.h"
#include <QDebug>

IHMNouvelleRuche::IHMNouvelleRuche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nouvelleRuche)
{
    ui->setupUi(this);
    ui->dateEdit_mise_en_service->setDate(QDate::currentDate());
}

IHMNouvelleRuche::~IHMNouvelleRuche()
{
    delete ui;
}
