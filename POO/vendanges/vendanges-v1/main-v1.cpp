#include "robot.h"

int main()
{  
    // TODO :

    // 1. Instancier un objet de type Robot en utilisant le constructeur par défaut
    Robot robot;

    // Avant d'accomplir la mission, vous pouvez afficher l'état de la situation
    robot.getTailleTas();
  
    // 2. Implémenter le diagramme de séquence "effectuer un chargement"
    
    do
    {
        robot.rammasser();
        
        while(robot.lirePosition() != POSITION_CHARETTE)
        {
            robot.allerDroite();
        }
        
        robot.deposer();
        
        while(robot.lirePosition() != POSITION_TAS)
        {
        
            robot.allerGauche();
        }
    }
    while(robot.estMissionFinie() == false);

    return 0;
}
