#ifndef TONNEAU_H
#define TONNEAU_H

class Tonneau
{
    private:
        int _contenance;
        int _quantite;
        
    public:
        Tonneau(int contenance);
        
        int quantite() const;
        int contenance() const;
        void remplir();
        void remplir(Tonneau &t);
        void vider();
};

#endif //TONNEAU_H
