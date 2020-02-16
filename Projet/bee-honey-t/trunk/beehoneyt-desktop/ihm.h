#ifndef IHM_H
#define IHM_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCharts>

/**
 * @enum PagesIHM
 * @brief Définit les numéros de page de l'IHM
 *
 */
enum PagesIHM
{
    PAGE_ACCUEIL,       //!< Page principale
    PAGE_MESURES,       //!< Page
    PAGE_TABLEAUX,      //!< Page
    PAGE_GRAPHIQUES,    //!< Page des graphiques
    PAGE_ALERTES        //!< Page des dernières alertes
};

class IHMNouvelleRuche;
class IHMReglageRuche;

namespace Ui {
class ihm;
}

class Ihm : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ihm(QWidget *parent = nullptr);
    ~Ihm();

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
    IHMNouvelleRuche *ihmNouvelleRuche;
    IHMReglageRuche *ihmReglageRuche;

    void chargerIconesBoutons();
};

#endif // IHM_H
