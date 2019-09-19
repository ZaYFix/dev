#include "robot.h"

#define NOUVEAU_POSITION_TAS        5
#define NOUVELLE_POSITION_CHARETTE  20
#define NOUVEAU_TAILLE_TAS          10
int main()
{  
    // TODO :

    // 1. Instancier un objet de type Robot en utilisant le constructeur par défaut
    Robot robot(NOUVEAU_POSITION_TAS, NOUVELLE_POSITION_CHARETTE, NOUVEAU_TAILLE_TAS);

    // Avant d'accomplir la mission, vous pouvez afficher l'état de la situation
    robot.getTailleTas();
  
    // 2. Implémenter le diagramme de séquence "effectuer un chargement"
    
    do
    {
        robot.rammasser();
        
        while(robot.lirePosition() != NOUVELLE_POSITION_CHARETTE)
        {
            robot.allerDroite();
        }
        
        robot.deposer();
        
        while(robot.lirePosition() != NOUVEAU_POSITION_TAS )
        {
        
            robot.allerGauche();
        }
    }
    while(robot.estMissionFinie() == false);

    return 0;
}
