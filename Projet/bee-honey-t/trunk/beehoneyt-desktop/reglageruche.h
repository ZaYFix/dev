#ifndef REGLAGERUCHE_H
#define REGLAGERUCHE_H

#include <QDialog>

namespace Ui {
class reglageRuche;
}

class reglageRuche : public QDialog
{
    Q_OBJECT

public:
    explicit reglageRuche(QWidget *parent = nullptr);
    ~reglageRuche();

private:
    Ui::reglageRuche *ui;
};

#endif // REGLAGERUCHE_H
