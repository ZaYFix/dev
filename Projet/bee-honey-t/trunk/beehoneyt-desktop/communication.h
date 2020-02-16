#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include "parametres_communications.h"

class Communication  : public QObject
{
    Q_OBJECT

public:
    Communication(QObject *parent = nullptr);
};

#endif // COMMUNICATION_H
