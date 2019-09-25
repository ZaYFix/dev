#ifndef ROBOT_H
#define ROBOT_H

#define POSITION_CHARETTE  15
#define POSITION_TAS       0
#define TAILLE_CHARETTE    1
#define TAILLE_TAS         20

//#define CHEAT

class Robot
{
    private:
        int positionTas;
        int positionCharette;
        const int tailleTas;
        const int tailleCharrette;
        int position;
        int charrette;
        int tas;
        int raisin;
        bool fini;
        
        void afficherJeu();

    public:
        Robot();
        Robot(int positionTas, int positionCharette, int tailleTas = TAILLE_TAS);
        
        int getTailleTas() const;
        int getTas() const;
        int distance() const;
        bool estMissionFinie() const;
        int  lirePosition();
        int  allerGauche();
        int  allerDroite();
        bool rammasser();
        bool deposer();
        void afficher();
};

#endif //ROBOT_H
