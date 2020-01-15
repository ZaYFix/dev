#include "Ihm.h"
#include <QApplication>

/**
 * @file    main.cpp
 * @author  ACKERMANN Théo
 * @author  LEGGER Pierre-Antoine
 * @version 1.0
 */

/**
 * @brief   Programme principale déclarant une classe Ihm et l'affiche
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


