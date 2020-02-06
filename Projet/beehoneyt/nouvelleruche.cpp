#include "nouvelleruche.h"
#include "ui_nouvelleruche.h"

nouvelleRuche::nouvelleRuche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nouvelleRuche)
{
    ui->setupUi(this);
}

nouvelleRuche::~nouvelleRuche()
{
    delete ui;
}
