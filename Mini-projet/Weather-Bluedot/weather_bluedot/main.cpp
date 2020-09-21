#include "Ihm.h"
#include <QApplication>

/**
 * @file    main.cpp
 * @brief   Programme principal
 * @author  ACKERMANN Théo
 * @author  LEGGER Pierre-Antoine
 * @version 1.0
 */

/**
 * @brief   Programme principal déclarant une classe Ihm et l'affiche
 * @param   argc
 * @param   argv[]
 * @return  int
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IHM w;

    w.show();

    return a.exec();
}


