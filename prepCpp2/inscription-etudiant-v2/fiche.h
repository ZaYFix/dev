#ifndef FICHE_H
#define FICHE_H

#define FICHES_MAX 500
#define CHAR_MAX 50
#define SEXE_FEMININ_MAJUSCULE 'F'
#define SEXE_FEMININ_MINUSCULE 'f'
#define CARACTERE_NUL '\0'

struct Fiche
{
    char nom[FICHES_MAX];
    char prenom[FICHES_MAX];
    unsigned int age;
    char sexe;
};

void inscrireEtudiants();
int rechercherPlusJeune(unsigned int i, unsigned int nbFiches);
void afficherListeEtudiant();
void compterFemmes(unsigned int i);
void reecriture(unsigned int i);

#endif
