#ifndef IHMCONVERTISSEUR_H
#define IHMCONVERTISSEUR_H

#include <QtWidgets>
#include <QDebug>

#define FARENHEIT       0
#define CELCIUS         1
#define YARD            2
#define METRE           3
#define MILES           4
#define KILOMETRE       5
#define NOEUD           6
#define KILOMETREHEURE  7

class IHMConvertisseur : public QWidget
{
    Q_OBJECT

private:
    QLineEdit   *valeur;
    QLabel      *resultat;
    QLabel      *unite;
    QComboBox   *choixConversion;
    QPushButton *boutonConvertir;
    QPushButton *boutonQuitter;
    QDoubleValidator *doubleValidator;

    void afficherUnite();

    void instancierWidgets();

    void initialiserWidgets();

    void positionnerWidgets();

public:
    IHMConvertisseur(QWidget *parent = 0);
    ~IHMConvertisseur();

signals:
    void actualiser();

private slots:
    void convertir();
    void permuter(int index);
};

#endif // IHMCONVERTISSEUR_H
