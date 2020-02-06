#ifndef NOUVELLERUCHE_H
#define NOUVELLERUCHE_H

#include <QDialog>

namespace Ui {
class nouvelleRuche;
}

class nouvelleRuche : public QDialog
{
    Q_OBJECT

public:
    explicit nouvelleRuche(QWidget *parent = nullptr);
    ~nouvelleRuche();

private:
    Ui::nouvelleRuche *ui;
};

#endif // NOUVELLERUCHE_H
