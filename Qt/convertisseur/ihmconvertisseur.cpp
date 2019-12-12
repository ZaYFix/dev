#include "ihmconvertisseur.h"

void IHMConvertisseur::instancierWidgets()
{
    valeur = new QLineEdit(this);
    doubleValidator = new QDoubleValidator(this);
    resultat = new QLabel(this);
    unite = new QLabel(this);
    choixConversion = new QComboBox(this);
    boutonConvertir = new QPushButton(QString::fromUtf8("Convertir"), this);
    boutonQuitter = new QPushButton(QString::fromUtf8("Quitter"), this);
}

void IHMConvertisseur::initialiserWidgets()
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    doubleValidator->setLocale(QLocale::C);
    doubleValidator->setDecimals(2);
    valeur->setValidator(doubleValidator);
    valeur->clear();
    resultat->setText("--.--");
    unite->setText(QString::fromUtf8(" °F"));
    choixConversion->addItem("Celcius -> Farenheit");
    choixConversion->addItem("Farenheit -> Celcius");
    choixConversion->addItem("Mètre -> Yard");
    choixConversion->addItem("Yard -> Mètre");
    choixConversion->addItem("Kilomètre -> Mille marin");
    choixConversion->addItem("Mille marin -> Kilomètre");
    choixConversion->addItem("Kilomètre/h -> Noeud");
    choixConversion->addItem("Noeud -> Kilomètre/h");
    choixConversion->setCurrentIndex(FARENHEIT);
}

void IHMConvertisseur::positionnerWidgets()
{
    QHBoxLayout *hLayout1 = new QHBoxLayout;
    QHBoxLayout *hLayout2 = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    hLayout1->addWidget(valeur);
    hLayout1->addWidget(choixConversion);
    hLayout1->addWidget(resultat);
    hLayout1->addWidget(unite);
    hLayout2->addWidget(boutonConvertir);
    hLayout2->addWidget(boutonQuitter);
    mainLayout->addLayout(hLayout1);
    mainLayout->addLayout(hLayout2);
    setLayout(mainLayout);
}

IHMConvertisseur::IHMConvertisseur(QWidget *parent)
    : QWidget(parent)
{
    /* instancier les widgets */
    instancierWidgets();

    /* initialiser les widgets */
    initialiserWidgets();

    /* positionner les widgets */
    positionnerWidgets();

    /* connecter les signaux aux slots */
    connect(choixConversion, SIGNAL(currentIndexChanged(int)), this, SLOT(permuter(int)));
    connect(this, SIGNAL(actualiser()), this, SLOT(convertir()));
    connect(boutonConvertir, SIGNAL(clicked()), this, SLOT(convertir()));
    connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    /* initialiser la fenêtre : dimensions, titre */
    setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, minimumSizeHint(), qApp->desktop()->availableGeometry()));
    setWindowTitle("Conversion d'unités marines");
}

IHMConvertisseur::~IHMConvertisseur()
{

}

void IHMConvertisseur::convertir()
{
    if (valeur->text().isEmpty())
    {
        resultat->setText(QString::fromUtf8("--.--"));
        afficherUnite();
        return;
    }
    switch (choixConversion->currentIndex())
    {
        case FARENHEIT:
            resultat->setText(QString::fromUtf8("%1").arg(9 * valeur->text().toDouble() / 5 + 32, 0, 'f', 2));
            break;
        case CELCIUS:
            resultat->setText(QString::fromUtf8("%1").arg(5 * (valeur->text().toDouble() - 32 )  / 9, 0, 'f', 2));
            break;
        case METRE:
            resultat->setText(QString::fromUtf8("%1").arg(valeur->text().toDouble() / 1.094));
            break;
        case YARD:
            resultat->setText(QString::fromUtf8("%1").arg(valeur->text().toDouble() * 1.094));
            break;
        case MILES:
            resultat->setText(QString::fromUtf8("%1").arg(valeur->text().toDouble() / 1.609));
            break;
        case KILOMETRE:
            resultat->setText(QString::fromUtf8("%1").arg(valeur->text().toDouble() * 1.609));
            break;
        case NOEUD:
            resultat->setText(QString::fromUtf8("%1").arg(valeur->text().toDouble() / 1.852));
            break;
        case KILOMETREHEURE:
            resultat->setText(QString::fromUtf8("%1").arg(valeur->text().toDouble() * 1.852));
            break;
    }
}

void IHMConvertisseur::permuter(int index)
{
    Q_UNUSED(index)
    if(valeur->text().toInt() > 0)
    {
        valeur->setText(resultat->text());
        emit actualiser();
    }
    else
    {
        valeur->clear();
        resultat->clear();
    }
    afficherUnite();
}

void IHMConvertisseur::afficherUnite()
{
    switch (choixConversion->currentIndex())
    {
        case FARENHEIT:
            unite->setText(QString::fromUtf8(" °F"));
        break;

        case CELCIUS:
            unite->setText(QString::fromUtf8(" °C"));
        break;

        case YARD:
            unite->setText(QString::fromUtf8(" yd"));
        break;

        case METRE:
            unite->setText(QString::fromUtf8(" m"));
        break;

        case KILOMETRE:
            unite->setText(QString::fromUtf8(" km"));
        break;

        case MILES:
            unite->setText(QString::fromUtf8(" mi"));
        break;

        case KILOMETREHEURE:
            unite->setText(QString::fromUtf8(" km/h"));
        break;

        case NOEUD:
            unite->setText(QString::fromUtf8(" nd"));
        break;
    }
}
