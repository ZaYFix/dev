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

public slots:
    void afficherTemperature(double temperature, QString uniteTemperature);
    void afficherTemperatureRessentie(double temperatureRessentie, QString uniteTemperatureRessentie);
    void afficherHumidite(unsigned int humidite, QString uniteHumidite);
    void afficherLuminosite(unsigned int luminosite, QString uniteLuminosite);
    void afficherPression(unsigned int pression, QString unitePression);
    void afficherAltitude(int altitude, QString uniteAltitude);
private slots:
    void on_pushButton_orange_clicked();
    void on_pushButton_vert_clicked();
    void on_pushbutton_rouge_clicked();
    void on_pushButton_eteindre_clicked();
};

#endif // IHM_H
