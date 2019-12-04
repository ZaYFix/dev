#ifndef IHM_H
#define IHM_H

#include "JeuPoulePoule.h"
#include "Joueur.h"

#define TEMPS_AFFICHAGE_EXEMPLE 2
#define TEMPS_AFFICHAGE_CARTE 2
#define TEMPS_AFFICHAGE_TEXTE 4

#define VERSION 2.1

#define NB_MAX_POUR_UN_CARACTERE_ESPACE 9
#define NOMBRE_DE_MANCHE 3

class Joueur;

class IHM
{
    private:
        JeuPoulePoule *jeuPoulePoule;
        Joueur *joueur;
        unsigned int reponseJoueurNbOeufs;
        char reponseQuestion;
        char reponseRelancerManche;
        char reponseQuestionFinDePartie;
       
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
        void afficherCarteOeuf() const;
        void afficherCartePoule() const;
        void afficherCarteRenard() const;
        void afficherCarteCoq() const;
        void afficherCarteChien() const;
        void afficherCarteCanard() const;
        void afficherCarteVer() const;
        void afficherQuestionFinDeManche();
        void afficherBravoManche();
        void afficherGagnerPartie();
        void afficherQuestionFinDePartie();
        void afficherBienvenue() const;
        void afficherMauvaiseReponse();
        void afficherQuestionExemple();
        void afficherMauvaiseReponse() const;
        void afficherRevoirPartie() const;
        void afficherNbTotalOeufs() const;
        void afficherNbTotalOeufsActuel() const;
        void afficherValeurIncorrecte() const;
        void afficherRelancerManche();
        void afficherQuestionPartieDemo();
        void fairePartieDemonstration();
        void demanderNom();

        // accesseur(s)
        unsigned int getReponseJoueurNbOeufs() const;
        char getReponseQuestion() const;
        
        //mutateur(s)
        void setReponseQuestion();
        void setReponseJoueurNbOeufs();
};

#endif // IHM_H