#include "reglageruche.h"
#include "ui_reglageruche.h"

reglageRuche::reglageRuche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reglageRuche)
{
    ui->setupUi(this);
}

reglageRuche::~reglageRuche()
{
    delete ui;
}
