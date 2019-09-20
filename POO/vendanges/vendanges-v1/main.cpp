#include "robot.h"

int main()
{  
    Robot robot;
    
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
