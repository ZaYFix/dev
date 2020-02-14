#ifndef IHM_H
#define IHM_H

#include <QMainWindow>

#include <QtWidgets>
#include <QtCharts>

class nouvelleRuche;
class reglageRuche;

namespace Ui {
class ihm;
}

class ihm : public QMainWindow
{
    Q_OBJECT

public:
    explicit ihm(QWidget *parent = nullptr);
    ~ihm();

    void demarrerGraphiques();

    void graphiqueTemperature();
    void graphiqueHumidite();
    void graphiqueLuminosite();
    void graphiquePression();
    void graphiquePoids();
    void graphiqueActivite();

    void setValeurGraphique(QLineSeries *serie, int x, int y);

    void demarrerGraphiquesBatons();
    void graphiqueBatonTemperatureInterieure();
    void graphiqueBatonTemperatureExterieure();

    void demarrerTableauAlertes();

private slots:
    void on_pushButton_ruches_clicked();

    void on_pushButton_mesures_clicked();

    void on_pushButton_tableaux_clicked();

    void on_pushButton_graphiques_clicked();

    void on_pushButton_alertes_clicked();

    void on_pushButton_nouvelle_ruche_clicked();

    void on_pushButton_reglage_clicked();

    void on_pushButton_supprimer_ruche_clicked();

    void changerAbscisseGraphiques();

private:
    Ui::ihm *ui;
    nouvelleRuche *nouvelleRucheIHM;
    reglageRuche *reglageRucheIHM;
};

#endif // IHM_H
