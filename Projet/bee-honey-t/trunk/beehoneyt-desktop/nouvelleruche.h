#ifndef NOUVELLERUCHE_H
#define NOUVELLERUCHE_H

#include <QDialog>

namespace Ui {
class nouvelleRuche;
}

class IHMNouvelleRuche : public QDialog
{
    Q_OBJECT

public:
    explicit IHMNouvelleRuche(QWidget *parent = nullptr);
    ~IHMNouvelleRuche();

private:
    Ui::nouvelleRuche *ui;
};

#endif // NOUVELLERUCHE_H
