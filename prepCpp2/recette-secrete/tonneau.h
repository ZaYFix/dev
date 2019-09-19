#ifndef TONNEAU_H
#define TONNEAU_H

#define RAISINS   20
#define CHARETTE  15
#define TAS       0

//#define CHEAT

class Tonneau
{
    private:
        const int _contenance;
        int _quantite;
        
        int vider(int q);
        
    public:
        Tonneau(int contenance);
        
        int quantite() const;
        int contenance() const;
        int remplir();
        int remplir(Tonneau &t);
        int vider();
};

#endif //TONNEAU_H
