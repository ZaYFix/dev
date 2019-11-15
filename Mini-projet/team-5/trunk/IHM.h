#ifndef IHM_H
#define IHM_H

typedef enum
{
    OEUF = 0,
    POULE = 1,
    RENARD = 2,
    COQ = 3
} TypeCarte;

class IHM
{
    private:
       TypeCarte typeCarte;
    public:
        // constructeur(s) et destructeur(s)
        IHM(TypeCarte typeCarte);
        IHM();

        // méthode(s)
        void afficherRegles() const;
        void afficherCarte(TypeCarte typeCarte) const;
};

#endif // IHM_H