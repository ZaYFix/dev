#include "nouvelleruche.h"
#include "ui_nouvelleruche.h"

nouvelleRuche::nouvelleRuche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nouvelleRuche)
{
    ui->setupUi(this);
    ui->dateEdit_mise_en_service->setDate(QDate::currentDate());
}

nouvelleRuche::~nouvelleRuche()
{
    delete ui;
}
