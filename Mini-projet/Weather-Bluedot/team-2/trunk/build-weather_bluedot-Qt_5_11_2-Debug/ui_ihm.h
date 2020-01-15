/********************************************************************************
** Form generated from reading UI file 'ihm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHM_H
#define UI_IHM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHM
{
public:
    QVBoxLayout *verticalLayout_7;
    QTabWidget *technicien_2;
    QWidget *mesures;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *Temperature;
    QLCDNumber *affichageTemperature;
    QLabel *uniteTemperature;
    QHBoxLayout *horizontalLayout_2;
    QLabel *temperatureRessentie;
    QLCDNumber *affichageTemperatureRessentie;
    QLabel *uniteTemperatureRessentie;
    QHBoxLayout *horizontalLayout_3;
    QLabel *humidite;
    QLCDNumber *affichageHumidite;
    QLabel *uniteHumidite;
    QHBoxLayout *horizontalLayout_4;
    QLabel *luminosite;
    QLCDNumber *affichageLuminosite;
    QLabel *uniteLuminosite;
    QHBoxLayout *horizontalLayout_5;
    QLabel *pression;
    QLCDNumber *affichagePression;
    QLabel *unitePression;
    QHBoxLayout *horizontalLayout_6;
    QLabel *altitude;
    QLCDNumber *affichageAltitude;
    QLabel *uniteAltitude;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushbutton_demarrer;
    QWidget *leds;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *texteEtatLed;
    QLabel *etatLED;
    QLabel *texteCouleurLED;
    QLabel *couleurLED;
    QLabel *label;
    QFrame *line;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushbutton_rouge;
    QPushButton *pushButton_vert;
    QPushButton *pushButton_orange;
    QPushButton *pushButton_eteindre;
    QWidget *technicien;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_11;
    QTextEdit *affichageTrame;
    QWidget *configuration;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QLineEdit *port_serie;
    QPushButton *pushButton_confirmerPortSerie;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *listePortSerie;
    QPushButton *rafraichirListePortSerie;

    void setupUi(QWidget *IHM)
    {
        if (IHM->objectName().isEmpty())
            IHM->setObjectName(QStringLiteral("IHM"));
        IHM->resize(446, 301);
        IHM->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_7 = new QVBoxLayout(IHM);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        technicien_2 = new QTabWidget(IHM);
        technicien_2->setObjectName(QStringLiteral("technicien_2"));
        QFont font;
        font.setPointSize(8);
        technicien_2->setFont(font);
        mesures = new QWidget();
        mesures->setObjectName(QStringLiteral("mesures"));
        verticalLayout_2 = new QVBoxLayout(mesures);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 9);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        Temperature = new QLabel(mesures);
        Temperature->setObjectName(QStringLiteral("Temperature"));

        horizontalLayout->addWidget(Temperature);

        affichageTemperature = new QLCDNumber(mesures);
        affichageTemperature->setObjectName(QStringLiteral("affichageTemperature"));

        horizontalLayout->addWidget(affichageTemperature);

        uniteTemperature = new QLabel(mesures);
        uniteTemperature->setObjectName(QStringLiteral("uniteTemperature"));

        horizontalLayout->addWidget(uniteTemperature);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        temperatureRessentie = new QLabel(mesures);
        temperatureRessentie->setObjectName(QStringLiteral("temperatureRessentie"));

        horizontalLayout_2->addWidget(temperatureRessentie);

        affichageTemperatureRessentie = new QLCDNumber(mesures);
        affichageTemperatureRessentie->setObjectName(QStringLiteral("affichageTemperatureRessentie"));

        horizontalLayout_2->addWidget(affichageTemperatureRessentie);

        uniteTemperatureRessentie = new QLabel(mesures);
        uniteTemperatureRessentie->setObjectName(QStringLiteral("uniteTemperatureRessentie"));

        horizontalLayout_2->addWidget(uniteTemperatureRessentie);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        humidite = new QLabel(mesures);
        humidite->setObjectName(QStringLiteral("humidite"));

        horizontalLayout_3->addWidget(humidite);

        affichageHumidite = new QLCDNumber(mesures);
        affichageHumidite->setObjectName(QStringLiteral("affichageHumidite"));

        horizontalLayout_3->addWidget(affichageHumidite);

        uniteHumidite = new QLabel(mesures);
        uniteHumidite->setObjectName(QStringLiteral("uniteHumidite"));

        horizontalLayout_3->addWidget(uniteHumidite);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        luminosite = new QLabel(mesures);
        luminosite->setObjectName(QStringLiteral("luminosite"));

        horizontalLayout_4->addWidget(luminosite);

        affichageLuminosite = new QLCDNumber(mesures);
        affichageLuminosite->setObjectName(QStringLiteral("affichageLuminosite"));

        horizontalLayout_4->addWidget(affichageLuminosite);

        uniteLuminosite = new QLabel(mesures);
        uniteLuminosite->setObjectName(QStringLiteral("uniteLuminosite"));

        horizontalLayout_4->addWidget(uniteLuminosite);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pression = new QLabel(mesures);
        pression->setObjectName(QStringLiteral("pression"));

        horizontalLayout_5->addWidget(pression);

        affichagePression = new QLCDNumber(mesures);
        affichagePression->setObjectName(QStringLiteral("affichagePression"));

        horizontalLayout_5->addWidget(affichagePression);

        unitePression = new QLabel(mesures);
        unitePression->setObjectName(QStringLiteral("unitePression"));

        horizontalLayout_5->addWidget(unitePression);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        altitude = new QLabel(mesures);
        altitude->setObjectName(QStringLiteral("altitude"));

        horizontalLayout_6->addWidget(altitude);

        affichageAltitude = new QLCDNumber(mesures);
        affichageAltitude->setObjectName(QStringLiteral("affichageAltitude"));

        horizontalLayout_6->addWidget(affichageAltitude);

        uniteAltitude = new QLabel(mesures);
        uniteAltitude->setObjectName(QStringLiteral("uniteAltitude"));

        horizontalLayout_6->addWidget(uniteAltitude);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushbutton_demarrer = new QPushButton(mesures);
        pushbutton_demarrer->setObjectName(QStringLiteral("pushbutton_demarrer"));
        pushbutton_demarrer->setCursor(QCursor(Qt::PointingHandCursor));
        pushbutton_demarrer->setFlat(false);

        verticalLayout_4->addWidget(pushbutton_demarrer);


        verticalLayout_2->addLayout(verticalLayout_4);

        technicien_2->addTab(mesures, QString());
        leds = new QWidget();
        leds->setObjectName(QStringLiteral("leds"));
        verticalLayout = new QVBoxLayout(leds);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        texteEtatLed = new QLabel(leds);
        texteEtatLed->setObjectName(QStringLiteral("texteEtatLed"));
        texteEtatLed->setMaximumSize(QSize(120, 16777215));
        texteEtatLed->setTextFormat(Qt::AutoText);

        horizontalLayout_12->addWidget(texteEtatLed);

        etatLED = new QLabel(leds);
        etatLED->setObjectName(QStringLiteral("etatLED"));
        etatLED->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_12->addWidget(etatLED);

        texteCouleurLED = new QLabel(leds);
        texteCouleurLED->setObjectName(QStringLiteral("texteCouleurLED"));
        texteCouleurLED->setMaximumSize(QSize(85, 16777215));

        horizontalLayout_12->addWidget(texteCouleurLED);

        couleurLED = new QLabel(leds);
        couleurLED->setObjectName(QStringLiteral("couleurLED"));

        horizontalLayout_12->addWidget(couleurLED);


        verticalLayout_3->addLayout(horizontalLayout_12);

        label = new QLabel(leds);
        label->setObjectName(QStringLiteral("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setMidLineWidth(0);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        line = new QFrame(leds);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);


        verticalLayout->addLayout(verticalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushbutton_rouge = new QPushButton(leds);
        pushbutton_rouge->setObjectName(QStringLiteral("pushbutton_rouge"));

        horizontalLayout_7->addWidget(pushbutton_rouge);

        pushButton_vert = new QPushButton(leds);
        pushButton_vert->setObjectName(QStringLiteral("pushButton_vert"));

        horizontalLayout_7->addWidget(pushButton_vert);

        pushButton_orange = new QPushButton(leds);
        pushButton_orange->setObjectName(QStringLiteral("pushButton_orange"));

        horizontalLayout_7->addWidget(pushButton_orange);


        verticalLayout->addLayout(horizontalLayout_7);

        pushButton_eteindre = new QPushButton(leds);
        pushButton_eteindre->setObjectName(QStringLiteral("pushButton_eteindre"));

        verticalLayout->addWidget(pushButton_eteindre);

        technicien_2->addTab(leds, QString());
        technicien = new QWidget();
        technicien->setObjectName(QStringLiteral("technicien"));
        horizontalLayout_8 = new QHBoxLayout(technicien);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        affichageTrame = new QTextEdit(technicien);
        affichageTrame->setObjectName(QStringLiteral("affichageTrame"));
        affichageTrame->setReadOnly(true);

        horizontalLayout_11->addWidget(affichageTrame);


        verticalLayout_8->addLayout(horizontalLayout_11);


        horizontalLayout_8->addLayout(verticalLayout_8);

        technicien_2->addTab(technicien, QString());
        configuration = new QWidget();
        configuration->setObjectName(QStringLiteral("configuration"));
        verticalLayout_5 = new QVBoxLayout(configuration);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_2 = new QLabel(configuration);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setPointSize(13);
        label_2->setFont(font1);

        horizontalLayout_10->addWidget(label_2);

        port_serie = new QLineEdit(configuration);
        port_serie->setObjectName(QStringLiteral("port_serie"));
        port_serie->setFont(font);

        horizontalLayout_10->addWidget(port_serie);


        verticalLayout_6->addLayout(horizontalLayout_10);


        verticalLayout_5->addLayout(verticalLayout_6);

        pushButton_confirmerPortSerie = new QPushButton(configuration);
        pushButton_confirmerPortSerie->setObjectName(QStringLiteral("pushButton_confirmerPortSerie"));
        pushButton_confirmerPortSerie->setMaximumSize(QSize(60, 16777215));
        pushButton_confirmerPortSerie->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_5->addWidget(pushButton_confirmerPortSerie);

        line_2 = new QFrame(configuration);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        listePortSerie = new QLabel(configuration);
        listePortSerie->setObjectName(QStringLiteral("listePortSerie"));

        horizontalLayout_9->addWidget(listePortSerie);

        rafraichirListePortSerie = new QPushButton(configuration);
        rafraichirListePortSerie->setObjectName(QStringLiteral("rafraichirListePortSerie"));

        horizontalLayout_9->addWidget(rafraichirListePortSerie);


        verticalLayout_5->addLayout(horizontalLayout_9);

        technicien_2->addTab(configuration, QString());

        verticalLayout_7->addWidget(technicien_2);


        retranslateUi(IHM);

        technicien_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(IHM);
    } // setupUi

    void retranslateUi(QWidget *IHM)
    {
        IHM->setWindowTitle(QApplication::translate("IHM", "Weather Bluedot", nullptr));
        Temperature->setText(QApplication::translate("IHM", "Temp\303\251rature", nullptr));
        uniteTemperature->setText(QApplication::translate("IHM", "\302\260C", nullptr));
        temperatureRessentie->setText(QApplication::translate("IHM", "Ressentie", nullptr));
        uniteTemperatureRessentie->setText(QApplication::translate("IHM", "\302\260C", nullptr));
        humidite->setText(QApplication::translate("IHM", "Humidit\303\251", nullptr));
        uniteHumidite->setText(QApplication::translate("IHM", "%", nullptr));
        luminosite->setText(QApplication::translate("IHM", "Luminosit\303\251", nullptr));
        uniteLuminosite->setText(QApplication::translate("IHM", "lux", nullptr));
        pression->setText(QApplication::translate("IHM", "Pression", nullptr));
        unitePression->setText(QApplication::translate("IHM", "hPa", nullptr));
        altitude->setText(QApplication::translate("IHM", "Altitude", nullptr));
        uniteAltitude->setText(QApplication::translate("IHM", "m", nullptr));
        pushbutton_demarrer->setText(QApplication::translate("IHM", "D\303\211MARRER", nullptr));
        technicien_2->setTabText(technicien_2->indexOf(mesures), QApplication::translate("IHM", "Mesures", nullptr));
        texteEtatLed->setText(QApplication::translate("IHM", "La LED est actuellement ", nullptr));
        etatLED->setText(QApplication::translate("IHM", "\303\251teinte", nullptr));
        texteCouleurLED->setText(QString());
        couleurLED->setText(QString());
        label->setText(QApplication::translate("IHM", "Changement de la couleur de la LED", nullptr));
        pushbutton_rouge->setText(QApplication::translate("IHM", "Rouge", nullptr));
        pushButton_vert->setText(QApplication::translate("IHM", "Vert", nullptr));
        pushButton_orange->setText(QApplication::translate("IHM", "Orange", nullptr));
        pushButton_eteindre->setText(QApplication::translate("IHM", "Eteindre", nullptr));
        technicien_2->setTabText(technicien_2->indexOf(leds), QApplication::translate("IHM", "LED", nullptr));
        technicien_2->setTabText(technicien_2->indexOf(technicien), QApplication::translate("IHM", "Technicien", nullptr));
        label_2->setText(QApplication::translate("IHM", "Port s\303\251rie :", nullptr));
        pushButton_confirmerPortSerie->setText(QApplication::translate("IHM", "OK", nullptr));
        listePortSerie->setText(QString());
        rafraichirListePortSerie->setText(QApplication::translate("IHM", "Rafraichir", nullptr));
        technicien_2->setTabText(technicien_2->indexOf(configuration), QApplication::translate("IHM", "Configuration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IHM: public Ui_IHM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHM_H
