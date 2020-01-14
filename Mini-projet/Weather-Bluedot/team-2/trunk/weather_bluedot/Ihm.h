#ifndef IHM_H
#define IHM_H

#include <QWidget>
#include "Supervision.h"

class Supervision;

namespace Ui {
class IHM;
}

class IHM : public QWidget
{
    Q_OBJECT

public:
    explicit IHM(QWidget *parent = nullptr);
    ~IHM();

signals:
    void changerCouleurLED(QString couleur);

private:
    Ui::IHM *ui;
    Supervision *supervision;
    int valeurBoutton;

public slots:
    void afficherTemperature(double temperature, QString uniteTemperature);
    void afficherTemperatureRessentie(double temperatureRessentie, QString uniteTemperatureRessentie);
    void afficherHumidite(double humidite, QString uniteHumidite);
    void afficherLuminosite(double luminosite, QString uniteLuminosite);
    void afficherPression(double pression, QString unitePression);
    void afficherAltitude(double altitude, QString uniteAltitude);
private slots:
    void on_pushButton_orange_clicked();
    void on_pushButton_vert_clicked();
    void on_pushbutton_rouge_clicked();
    void on_pushButton_eteindre_clicked();
    void on_pushbutton_demarrer_clicked();
    void on_pushButton_confirmerPortSerie_clicked();
    void on_rafraichirListePortSerie_clicked();
};

#endif // IHM_H
