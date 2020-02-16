#ifndef REGLAGERUCHE_H
#define REGLAGERUCHE_H

#include <QDialog>

namespace Ui {
class reglageRuche;
}

class IHMReglageRuche : public QDialog
{
    Q_OBJECT

public:
    explicit IHMReglageRuche(QWidget *parent = nullptr);
    ~IHMReglageRuche();

private:
    Ui::reglageRuche *ui;
};

#endif // REGLAGERUCHE_H
