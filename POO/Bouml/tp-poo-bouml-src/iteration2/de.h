#ifndef DE_H
#define DE_H

#include <iostream>

using namespace std;

class De
{
    public:
        De();
        ~De();       

        void jouer();
        void lancerDes();
        void afficherDes() 
        void calculerDes();


    private:
        unsigned int de1;
        unsigned int de2;
};

#endif
