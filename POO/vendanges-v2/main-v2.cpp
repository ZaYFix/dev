#include "robot.h"

#define NOUVEAU_POSITION_TAS        5
#define NOUVELLE_POSITION_CHARETTE  20
#define NOUVEAU_TAILLE_TAS          10
int main()
{  
    Robot robot(NOUVEAU_POSITION_TAS, NOUVELLE_POSITION_CHARETTE, NOUVEAU_TAILLE_TAS);
    
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
    while(!robot.estMissionFinie());

    return 0;
}
