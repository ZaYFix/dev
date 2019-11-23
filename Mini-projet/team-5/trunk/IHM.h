#ifndef IHM_H
#define IHM_H

#include "JeuPoulePoule.h"

#define TEMPS_AFFICHAGE_EXEMPLE 2
#define TEMPS_AFFICHAGE_CARTE 2
#define VERSION 2.0
#define NB_MAX_POUR_UN_CARACTERE_ESPACE 9

class IHM
{
    private:
        JeuPoulePoule *jeuPoulePoule;
        unsigned int reponseJoueurNbOeufs;
        char reponseQuestion;
       
    public:
        // constructeur(s) et destructeur(s)
        IHM(JeuPoulePoule *jeuPoulePoule=NULL);
        ~IHM();

        // méthode(s)
        void afficherNomJeu() const;
        void afficherRegles() const;
        void afficherExemple();
        void effacerIHM() const;
        void attendre(unsigned int tempsAffichageDefini) const;
        void afficherCarte(TypeCarte typeCarte, bool afficheNumeroCarte=false) const;
        void afficherQuestionFinDeManche();
        void afficherBravo() const;
        void afficherGagnerManche() const;
        void afficherBienvenue() const;
        void afficherQuestionExemple();
        void afficherMauvaiseReponse() const;
        void afficherRevoirPartie() const;
        void afficherNbTotalOeufs() const;
        void afficherNbTotalOeufsActuel() const;
        void afficherValeurIncorrecte() const;

        // accesseur(s)
        unsigned int getReponseJoueurNbOeufs() const;
        char getReponseQuestion() const;
        
        //mutateur(s)
        void setReponseQuestion();
};

#endif // IHM_H